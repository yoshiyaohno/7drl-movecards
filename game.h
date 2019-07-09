#ifndef GAME_H
#define GAME_H

#include <stdlib.h>

#include "entity.h"
#include "action.h"
#include "map.h"

// this is stupid .... 
typedef struct Entity Entity;
typedef struct Map Map;

typedef struct Game {
    Action next_plr_action; //hmm
    Entity *player;
    EntityList *entity_list;
    Map *map;
} Game;

// what will Entity do?
Action decide_action(Game *, Entity *);

// update world after Entity does Action
void resolve_action(Game *, Entity *, Action);

// err do the loop and all the entities and stuff haha
void process(Game *);

//Game *init_game();
//void free_game(Game *);

#endif

