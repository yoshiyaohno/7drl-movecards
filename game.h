#pragma once

#include <stdlib.h>

#include "entity.h"
#include "action.h"
#include "map.h"

// this is stupid .... 
typedef struct EntityList EntityList;
typedef struct Entity Entity;
typedef struct Map Map;

typedef struct Game {
    Action next_plr_action; //hmm
    Entity *player;
    EntityList *entity_list;
    Map *map;
} Game;

// what do you see on that tile?
//  (later you should .. figure out how to do a better version of this)
char chinspect(const Game *, int row, int col);

// what will Entity do?
Action decide_action(Game *, Entity *);

// update world for Entity doing Action
//  *ASSUME ACTION IS VALID*
void resolve_action(Game *, Entity *, Action);

// err do the loop and all the entities and stuff haha
void process(Game *);

Game *init_game();
void free_game(Game *);

