#pragma once

#include <stdlib.h>

#include "action.h"
#include "game.h"
#include "item.h"

#define MAX_INVENTORY   8

// this is stupid
typedef struct Game Game;

typedef enum ai {
    AI_PLR,
    AI_ENM,
    // more to come ...
} ai;

typedef struct Entity {
    ai ai;
    int row, col;
    int inv_space;
    Item *inventory[MAX_INVENTORY];
    movetype moves[2*MAX_RADIUS+1][2*MAX_RADIUS+1];
} Entity;

// returns -1 for failure I guess hahaha
int add_item(Entity *, Item *);

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

void free_en(EntityNode *);

// and something to create entities, and free them (after inventory)

