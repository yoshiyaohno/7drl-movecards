#include "item.h"
#include "item_p.h"

char *get_item_name(Item *item)
{
    return item->name;
}

// hmm
Item *basic_item_lol()
{
    Item *item = malloc(sizeof(Item));
    item->name = "test item";
    movetype jef[9][9] = {
        {MV_MOVE, MV_NONE, MV_NONE, MV_NONE, MV_MOVE,
            MV_NONE, MV_NONE, MV_NONE, MV_MOVE},
        {MV_NONE, MV_NONE, MV_NONE, MV_NONE, MV_NONE,
            MV_NONE, MV_NONE, MV_NONE, MV_NONE},
        {MV_NONE, MV_NONE, MV_NONE, MV_NONE, MV_MOVE,
            MV_NONE, MV_NONE, MV_NONE, MV_NONE},
        {MV_NONE, MV_NONE, MV_NONE, MV_MOVE, MV_MOVE,
            MV_MOVE, MV_NONE, MV_NONE, MV_NONE},
        {MV_MOVE, MV_NONE, MV_MOVE, MV_MOVE, MV_NONE,       //mid
            MV_MOVE, MV_MOVE, MV_NONE, MV_MOVE},
        {MV_NONE, MV_NONE, MV_NONE, MV_MOVE, MV_MOVE,
            MV_MOVE, MV_NONE, MV_NONE, MV_NONE},
        {MV_NONE, MV_NONE, MV_NONE, MV_NONE, MV_MOVE,
            MV_NONE, MV_NONE, MV_NONE, MV_NONE},
        {MV_NONE, MV_NONE, MV_NONE, MV_NONE, MV_NONE,
            MV_NONE, MV_NONE, MV_NONE, MV_NONE},
        {MV_MOVE, MV_NONE, MV_NONE, MV_NONE, MV_MOVE,
            MV_NONE, MV_NONE, MV_NONE, MV_MOVE},
    };
    memcpy(item->arr, jef, 9 * 9 * sizeof(movetype));
    return item;
}

movetype movetype_at(Item *item, int row, int col)
{
    assert(0 <= row && 2*MAX_RADIUS+1 >= row);
    assert(0 <= col && 2*MAX_RADIUS+1 >= col);
    return item->arr[row][col];
}

