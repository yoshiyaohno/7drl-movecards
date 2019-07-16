#include "map.h"
#include "map_p.h"

Map *init_map()
{
    Map *m = malloc(sizeof(Map));
    m->rows = 8;
    m->cols = 16;

    m->arr = malloc(m->rows * sizeof(tile *));
    for (int i = 0; i < m->rows; ++i) {
        m->arr[i] = malloc(m->cols * sizeof(tile));
        for (int j = 0; j < m->cols; ++j) {
            m->arr[i][j] = TILE_FLOOR;
        }
    }
    for (int i = 2; i < 5; ++i) {
        for (int j = 5; j < 9; ++j) {
            m->arr[i][j] = TILE_WALL;
        }
    }
    return m;
}

tile tile_at(Map *m, int row, int col)
{
    return m->arr[row][col];
}

char disp_tile(tile t)
{
    switch (t) {
        case TILE_FLOOR:    return '.';
        case TILE_WALL:     return '#';
        default:            return '~';
    }
}

int is_valid(Map *m, int row, int col)
{
    if (!in_bounds(m, row, col)) return 0;
    return TILE_FLOOR == m->arr[row][col];
}

int in_bounds(Map *m, int row, int col)
{
    return (row >= 0 || row < m->rows || col >= 0 || col < m->cols);
}

void free_map(Map *m)
{
    for (int i = 0; i < m->rows; ++i) {
        free(m->arr[i]);
    }
    free(m->arr);
    free(m);
}

void get_bounds(Map *m, int *rows, int *cols)
{
    *rows = m->rows;
    *cols = m->cols;
}

