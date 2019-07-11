#include "entity.h"

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

