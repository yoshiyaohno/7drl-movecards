#pragma once

#include "map.h"

typedef struct Map {
    tile_t **arr;
    int rows, cols;
} Map;

