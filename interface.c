#include "interface.h"
#include "interface_p.h"

#define STATUS_HEIGHT   4

void draw_interface(Interface *face)
{
    draw_map(face);

    box(face->board, 0, 0);

    // draw options
    // update statusline (based on cursor, options)
    werase(face->status);
    box(face->status, 0, 0);

    color_options(face);

    mvwprintw(face->status, 1, 1, "Cursor: %d %d",
                rel_curs_row(face),
                rel_curs_col(face));

    wmove(face->board, 1 + abs_curs_row(face), 1 + abs_curs_col(face));

    wnoutrefresh(face->status);
    wnoutrefresh(face->board);
    doupdate();
}

void resolve_input(Interface *face, int inp)
{
    int old_crow = face->curs_row;
    int old_ccol = face->curs_col;
    switch (translate_input(inp)) {
        case INP_OK:
            action_selected(face);
            break;

        case INP_N:
            face->curs_row += -1;
            break;
        case INP_NE:
            face->curs_row += -1;
            face->curs_col += +1;
            break;
        case INP_E:
            face->curs_col += +1;
            break;
        case INP_SE:
            face->curs_row += +1;
            face->curs_col += +1;
            break;
        case INP_S:
            face->curs_row += +1;
            break;
        case INP_SW:
            face->curs_row += +1;
            face->curs_col += -1;
            break;
        case INP_W:
            face->curs_col += -1;
            break;
        case INP_NW:
            face->curs_row += -1;
            face->curs_col += -1;
            break;
        
        case INP_NULL:
        default:
            break;
    }

    // crunch
    if (!is_cursor_valid(face)) {
        face->curs_row = old_crow;
        face->curs_col = old_ccol;
    }
}

void color_options(Interface *face)
{
    int sav_crow = face->curs_row;
    int sav_ccol = face->curs_col;
    int change_to;
    for (int i = -MAX_RADIUS; i <= MAX_RADIUS; ++i) {
        for (int j = -MAX_RADIUS; j <= MAX_RADIUS; ++j) {
            face->curs_row = i;
            face->curs_col = j;
            wmove(face->board, 1+abs_curs_row(face), 1+abs_curs_col(face));
            if (is_cursor_valid(face)) {
                switch (face->player->moves[i+MAX_RADIUS][j+MAX_RADIUS]) {
                    case MV_MOVE:
                        change_to = PAIR_MOVE;
                        break;
                    default:
                    case MV_NONE:
                        change_to = PAIR_NONE;
                        break;
                }
                wchgat(face->board, 1, A_NORMAL, change_to, NULL);
            }
        }
    }
    face->curs_row = sav_crow;
    face->curs_col = sav_ccol;
}

void action_selected(Interface *face)
{
    if (is_valid(get_map(face->game), abs_curs_row(face), abs_curs_col(face))) {
        mvwprintw(face->status, 2, 1, "sneeze");
        Action mvaction;
        mvaction.type = ACTION_MOVE;
        mvaction.row = abs_curs_row(face);
        mvaction.col = abs_curs_col(face);
        set_next_plr_action(face->game, mvaction);
        face->curs_row = 0;
        face->curs_col = 0;
    }
}

Interface *init_interface(Game *game)
{
    Interface *face = malloc(sizeof(Interface));
    face->game = game;
    face->player = get_player(game);

    face->curs_row = 0;
    face->curs_col = 0;

    // initialize curses, with options
    setlocale(LC_ALL, "");
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    //curs_set(0);
    nodelay(stdscr, TRUE);
    
    if (FALSE == has_colors()) {
        endwin();
        printf("please use a terminal that supports color\n");
        exit(1);
    }
    start_color();
    init_pair(PAIR_MOVE, COLOR_WHITE, COLOR_GREEN);
    init_pair(PAIR_NONE, COLOR_WHITE, COLOR_BLACK);

    // set up windows
    int term_x, term_y;
    getmaxyx(stdscr, term_y, term_x);
    face->board  = newwin((term_y - STATUS_HEIGHT), term_x, 0, 0);
    face->status = newwin(4, term_x, (term_y - STATUS_HEIGHT), 0);

    draw_map(face);
    box(face->board,  0, 0);
    box(face->status, 0, 0);

    refresh(); // let's not make that mistake again

    return face;
}

void draw_map(Interface *face)
{
    int m_rows, m_cols;         // bruh moment
    get_bounds(get_map(face->game), &m_rows, &m_cols);
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            mvwaddch(face->board, i+1, j+1, chinspect(face->game, i, j));
        }
    }
}

void free_interface(Interface *face)
{
    free(face);
    endwin();
}

input translate_input(int ch)
{
    switch (ch) {
        case 'h':   return INP_W;
        case 'j':   return INP_S;
        case 'k':   return INP_N;
        case 'l':   return INP_E;
        case 'y':   return INP_NW;
        case 'u':   return INP_NE;
        case 'b':   return INP_SW;
        case 'n':   return INP_SE;
        case ' ':   return INP_OK;

        case ERR:
        default:    return INP_NULL;
    }
}

int abs_curs_row(Interface *face)
{
    return face->curs_row + face->player->row;
}

int abs_curs_col(Interface *face)
{
    return face->curs_col + face->player->col;
}

int rel_curs_row(Interface *face)
{
    return face->curs_row;
}

int rel_curs_col(Interface *face)
{
    return face->curs_col;
}


int is_cursor_valid(Interface *face)
{
    int m_rows, m_cols;
    get_bounds(get_map(face->game), &m_rows, &m_cols);
    return rel_curs_row(face) >= -MAX_RADIUS
        && rel_curs_row(face) <=  MAX_RADIUS
        && rel_curs_col(face) >= -MAX_RADIUS
        && rel_curs_col(face) <=  MAX_RADIUS
        && abs_curs_row(face) >= 0
        && abs_curs_row(face) < m_rows
        && abs_curs_col(face) >= 0
        && abs_curs_col(face) < m_cols
        ;
}

