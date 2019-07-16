#pragma once

#include "interface.h"

typedef enum input {
    INP_NULL,
    INP_NE,
    INP_E,
    INP_SE,
    INP_S,
    INP_SW,
    INP_W,
    INP_NW,
    INP_N,
    INP_OK,
} input;

typedef struct Interface {
    int curs_row, curs_col;
    Game *game;
    WINDOW *board;
    WINDOW *status;
    // later: windows for inventory, farlook, etc
} Interface;

void move_cursor(Interface *face);

// draw Game's map to the main board (uhhh also player)
void draw_map(Interface *);

input translate_input(int);

void action_selected(Interface *);

int is_cursor_valid(Interface *);

int abs_curs_row(Interface *);
int abs_curs_col(Interface *);
int rel_curs_row(Interface *);
int rel_curs_col(Interface *);

