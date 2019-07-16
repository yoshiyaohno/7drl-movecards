#pragma once

#include <assert.h>

#include "item.h"

typedef struct Item {
    char *name;
    movetype arr[2 * MAX_RADIUS + 1][2 * MAX_RADIUS + 1];
} Item;

