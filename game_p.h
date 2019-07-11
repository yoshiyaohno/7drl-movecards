#pragma once

#include "game.h"

typedef struct Game {
    Action next_plr_action; //hmm
    Entity *player;
    EntityList *entity_list;
    Map *map;
} Game;

