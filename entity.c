#include "entity.h"
#include "entity_p.h"

int add_item(Entity *e, Item *item)
{
    if (MAX_INVENTORY == e->inv_space) return -1;
    e->inventory[e->inv_space++] = item;

    // who did this loop for real
    for (int i = 0; i < 2*MAX_RADIUS+1; ++i) {          //rows
        for (int j = 0; j < 2*MAX_RADIUS+1; ++j) {      //cols
            for (int k = 0; k < e->inv_space; ++k) {    //items
                if ((e->moves[i][j] = movetype_at(e->inventory[k], i, j))) {
                    break;  // no, that's not supposed to be ==
                }
            }
        }
    }
    return 0;
}

//// ANNOYING LIST FUNCTIONS BELOW ////

Entity *get_head(EntityList *el)
{
    if(!el->head) return NULL;
    return el->head->cargo;
}

EntityList *empty_el()
{
    EntityList *el = malloc(sizeof(EntityList));
    el->head = NULL;
    el->tail = NULL;
    return el;
}

void advance(EntityList *el)
{
    if(!el->head) return;       // null case
    el->tail->next = el->head;  // after the old end is the old beginning
    el->tail = el->head;        // the head node is now the end node
    el->head = el->head->next;  // move one down the list
    el->tail->next = NULL;      // the new tail
    // these comments aren't really helping are they
}

EntityNode *create_en(Entity *e)
{
    EntityNode *en = malloc(sizeof(EntityNode));
    en->cargo = e;
    en->next = NULL;
    return en;
}

void free_en(EntityNode *en)
{
    free(en->cargo);    // this will have to change with inventories
    free(en);
}

