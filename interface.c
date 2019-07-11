#include "interface.h"

Interface init_interface(const Game *game)
{
    int term_x, term_y;
    Interface face;
    face.game = game;

    setlocale(LC_ALL, "");
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    // set up windows
    getmaxyx(stdscr, term_y, term_x);
    game.board  = newwin((term_y - 4), term_x, 0, 0);
    game.status = newwin(4, term_x, (term_y - 4), 0);
    refresh(); // let's not make that mistake again

    return face;
}

void draw_map(Interface *face)
{
    // lmao what is error checking just stay in bounds

    Map *m = face->game->map; // just for brevity
    int i, j;
    for (i = 0; i < m->rows; ++i) {
        for (j = 0; j < m->cols; ++j) {
            mvwaddch(face->board, i, j, chinspect(game, i, j));
        }
    }

    wrefresh(face->board);
}

