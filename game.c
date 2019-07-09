#include "game.h"

GameState game;

void process()
{
    Action act;
    while (act = decide_action(get_head(game->entity_list))) {

        // maybe do validation

        resolve_action(act, get_head(game->entity_list));
        advance(entity_list);

        // process death, etc
    }

    // when done, we know it is either the player's turn or something is bad
}

void resolve_action(Entity *ent, Action act)
{
    switch(act.type) {
        case ACTION_MOVE:
            if(is_valid(game->map), act.row, act.col) {
                ent->row = act.row;
                ent->col = act.col;
            }
            break;
        case ACTION_WAIT:
            break;
    }
}

