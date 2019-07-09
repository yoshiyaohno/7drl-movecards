#ifndef MAP_H
#define MAP_H

#include <stdlib.h>

typedef enum tile_t {
    TILE_FLOOR,
    TILE_WALL,
} tile_t;

typedef struct Map {
    tile_t **arr;
    int rows, cols;
} Map;

Map *init_map();

void free_map(Map *);

int is_valid(Map *, int row, int col);

#endif

