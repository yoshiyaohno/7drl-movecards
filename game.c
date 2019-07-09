#include "game.h"

void process(Game *game)
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

Action decide_action(Game *game, Entity *ent)
{
    Action act;
    switch(ent->ai) {
        case AI_PLR:
            act = game->next_plr_action;
            game->next_plr_action = NULL;
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

void resolve_action(Game *game, Entity *ent, Action act)
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

