#pragma once

#include <stdlib.h>

typedef enum tile {
    TILE_FLOOR,
    TILE_WALL,
} tile;

// predeclare
typedef struct Map Map;

// convert a tile to printable version
char disp_tile(tile);

tile tile_at(Map *, int row, int col);

Map *init_map();

void free_map(Map *);

// (currently) in bounds and open
int is_valid(Map *, int row, int col);

int in_bounds(Map *, int row, int col);

// I am shitting the bed
void get_bounds(Map *, int *rows, int *cols);

