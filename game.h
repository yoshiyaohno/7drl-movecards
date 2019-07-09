#ifndef GAME_H
#define GAME_H

#include "entity.h"
#include "action.h"

// this is stupid .... 
typedef struct Entity Entity;

typedef struct GameState {
    Action next_plr_action; //hmm
    Entity *player;
    EntityList *entity_list;
    // map
} GameState;

void resolve_action(Entity *);

void process();

#endif

