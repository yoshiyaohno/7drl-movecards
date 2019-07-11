#include "interface.h"
#include "interface_p.h"

Action plr_input(Interface *face)
{
    face->curs_row = 0;
    face->curs_col = 0;

    curs_set(1);
}

Interface *init_interface(const Game *game)
{
    int term_x, term_y;
    Interface *face = malloc(sizeof(Interface));
    face->game = game;

    setlocale(LC_ALL, "");
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    // set up windows
    getmaxyx(stdscr, term_y, term_x);
    face->board  = newwin((term_y - 4), term_x, 0, 0);
    face->status = newwin(4, term_x, (term_y - 4), 0);
    refresh(); // let's not make that mistake again

    return face;
}

void draw_map(Interface *face)
{
    // lmao what is error checking like just stay in bounds

    Map *m = face->game->map; // just for brevity
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            mvwaddch(face->board, i, j, chinspect(face->game, i, j));
        }
    }
    wrefresh(face->board);
}

void free_interface(Interface *face)
{
    free(face);
    endwin();
}

input translate_input(char ch)
{
    switch (ch) {
        case 'h':   return INP_W;
        case 'j':   return INP_S;
        case 'k':   return INP_N;
        case 'l':   return INP_E;
        case 'y':   return INP_NW;
        case 'u':   return INP_NE;
        case 'b':   return INP_SE;
        case 'n':   return INP_SW;
        case ' ':   return INP_OK;
        default:    return INP_NULL;
    }
}

