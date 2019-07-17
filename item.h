#pragma once

#define MAX_RADIUS  4

#include <stdlib.h>

// opaque definition
typedef struct Item Item;

typedef enum movetype {
    MV_NONE,
    MV_MOVE,
    MV_BLOCK,
    MV_ATK,
    // whatever garbage
} movetype;

typedef enum itemrarity {
    RAR_NULL,
    RAR_COMM,
    RAR_UNCOMM,
    RAR_RARE,
    // whatever garbage
} itemrarity;

Item *basic_item_lol(); // GET RID OF THIS SOON OK

char *get_item_name(Item *);

movetype movetype_at(Item *, int row, int col);

