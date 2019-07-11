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

// convert a tile to printable version
char disp_tile(tile_t);

Map *init_map();

void free_map(Map *);

// (currently) in bounds and open
int is_valid(Map *, int row, int col);

#endif

