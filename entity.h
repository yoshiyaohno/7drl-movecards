#ifndef ENTITY_H
#define ENTITY_H

#include <stdlib.h>

#include "action.h"
#include "game.h"

// this is stupid
typedef struct GameState GameState;

typedef enum ai_t {
    AI_PLR,
    AI_ENM,
    // more to come ...
} ai_t;

typedef struct Entity {
    ai_t ai;
    int row, col;
    const GameState *game;
    // inventory eventually
} Entity;

// ask the AI what to do (look at gamestate obvs)
Action decide_action(Entity *);

typedef struct EntityList {
    EntityNode *head;
    EntityNode *tail;
} EntityList;

typedef struct EntityNode {
    Entity *cargo;
    EntityNode *next;
} EntityNode;

// plus functions on the EL

Entity *get_head(EntityList *);     // hahahaha

void advance_el(EntityList *);

EntityList *empty_el();

//void free_el(EntityList *);

//void append_el(EntityList *, Entity *);

EntityNode *create_en(Entity *);

#endif

