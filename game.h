#pragma once

#include <stdlib.h>

#include "entity.h"
#include "action.h"
#include "map.h"

// this is stupid .... 
typedef struct EntityList EntityList;
typedef struct Entity Entity;
typedef struct Map Map;

// hide this one
typedef struct Game Game;

// what do you see on that tile?
//  (later you should .. figure out how to do a better version of this)
char chinspect(const Game *, int row, int col);

// is this stupid ... ?
Entity *get_player(const Game *);
Map *get_map(const Game *);

// ...sets next plr action
void set_next_plr_action(Game *, Action);

// what will Entity do?
Action decide_action(Game *, Entity *);

// update world for Entity doing Action
//  *ASSUME ACTION IS VALID*
void resolve_action(Game *, Entity *, Action);

// resolve actions until someone decides to do ACTION_NULL
//  (currently only happens when it's the player's turn)
void process(Game *);

Game *init_game();
void free_game(Game *);

