#pragma once

#include "interface.h"

typedef struct Interface {
    int curs_row, curs_col;
    Game *game;
    WINDOW *board;
    WINDOW *status;
    // later: windows for inventory, farlook, etc
} Interface;

