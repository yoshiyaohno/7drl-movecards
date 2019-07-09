#include "entity.h"

Action decide_action(Entity *ent)
{
    Action act;
    switch(ent->ai) {
        case AI_PLR:
            act = ent->game->next_plr_action;
            ent->game->next_plr_action = NULL;
            break;
        case AI_ENM:
            act.type = ACTION_WAIT;
            break;
        default:
            act.type = ACTION_WAIT;
            break;
    }
    return act
}

//// ANNOYING LIST FUNCTIONS BELOW ////

Entity *get_head(EntityList *el)
{
    if(!el->head) return NULL;
    return el->head->cargo;
}

EntityList *empty_el()
{
    el = malloc(sizeof(EntityList));
    el->head = NULL;
    el->tail = NULL;
    return el;
}

void advance_el(EntityList *el)
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
    en = malloc(sizeof(EntityNode));
    en->cargo = e;
    en->next = NULL;
    return en;
}

