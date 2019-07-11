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

input translate_input(char);

