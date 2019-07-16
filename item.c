#include "item.h"
#include "item_p.h"

char *get_item_name(Item *item)
{
    return item->name;
}

movetype movetype_at(Item *item, int row, int col)
{
    assert(-MAX_RADIUS <= row && MAX_RADIUS >= row);
    assert(-MAX_RADIUS <= col && MAX_RADIUS >= col);
    return item->arr[row][col];
}

