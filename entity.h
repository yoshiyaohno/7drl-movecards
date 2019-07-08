#ifndef ENTITY_H
#define ENTITY_H

#include "action.h"
#include "game.h"

// this is stupid
typedef struct GameState GameState;

typedef enum ai_t {
    AI_PLR,
    AI_ENM,
} ai_t;

typedef struct Entity {
    ai_t ai;
    int row, col;
    const GameState *game;
    // inventory eventually
} Entity;

Action decide_action(Entity *);

typedef struct EntityList {
    Entity *head;
    Entity *tail;
} EntityList;
// plus functions on the EL

void advance(EntityList *);

#endif

