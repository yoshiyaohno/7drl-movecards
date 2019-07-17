#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

#include "item.h"
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

void draw_interface(Interface *);

void resolve_input(Interface *, int);

// loop doing interface stuff until you get a valid action
Action plr_input(Interface *);

