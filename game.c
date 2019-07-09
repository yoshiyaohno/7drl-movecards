#include "game.h"

void process(Game *game)
{
    Action act;
    while (1) {

        act = decide_action(game, get_head(game->entity_list));

        // maybe do validation
        if (ACTION_NULL == act.type) return;

        resolve_action(game, get_head(game->entity_list), act);
        advance(game->entity_list);

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
            game->next_plr_action.type = ACTION_NULL;
            break;
        case AI_ENM:
            act.type = ACTION_WAIT;
            break;
        default:
            act.type = ACTION_WAIT;
            break;
    }
    return act;
}

void resolve_action(Game *game, Entity *ent, Action act)
{
    switch(act.type) {
        case ACTION_MOVE:
            ent->row = act.row;
            ent->col = act.col;
            break;
        case ACTION_WAIT:
            break;
    }
}

Game *init_game()
{
    Game *game = malloc(sizeof(Game));
    game->next_plr_action.type = ACTION_NULL;
    game->map = init_map();
    game->entity_list = empty_el();

    // garbage time //
    Entity *plr = malloc(sizeof(Entity));
    plr->ai = AI_PLR;
    plr->row = 1;
    plr->col = 1;
    game->entity_list->head = create_en(plr);
    game->entity_list->tail = game->entity_list->head;
    game->player = plr;
    // wig          //
}

