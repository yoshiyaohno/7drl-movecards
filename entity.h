#pragma once

#include <stdlib.h>

#include "action.h"
#include "game.h"

// this is stupid
typedef struct Game Game;

typedef enum ai_t {
    AI_PLR,
    AI_ENM,
    // more to come ...
} ai_t;

typedef struct Entity {
    ai_t ai;
    int row, col;
    // inventory eventually
} Entity;

typedef struct EntityNode {
    Entity *cargo;
    struct EntityNode *next;
} EntityNode;

typedef struct EntityList {
    EntityNode *head;
    EntityNode *tail;
} EntityList;

// plus functions on the EL

Entity *get_head(EntityList *);     // hahahaha

void advance(EntityList *);

EntityList *empty_el();

//void free_el(EntityList *);

//void append_el(EntityList *, Entity *);

EntityNode *create_en(Entity *);

