#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include <locale.h>

#include "game.h"
#include "map.h"

// yaay
typedef struct Game Game;

// opaque pointer time
typedef struct Interface Interface;

// also clean up curses
void free_interface(Interface *);

// take a game to link to
Interface *init_interface(Game *);

// draw Game's map to the main board (uhhh also player)
void draw_map(Interface *);

// loop doing interface stuff until you get a valid action
Action plr_input(Interface *);

