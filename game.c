#include "game.h"

GameState game;

void process()
{
    Action act;
    while (act = decide_action(get_head(game->entity_list))) {

        // maybe do validation

        resolve_action(act, entity_list->head->cargo);
        advance(entity_list);

        // process death, etc
    }

    // when done, we know it is either the player's turn or something is bad
}

