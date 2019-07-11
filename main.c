#include "interface.h"
#include "game.h"

int main()
{
    Game *game = init_game();
    Interface *interface = init_interface(game);

    draw_map(interface);

    getch();

    free_game(game);
    free_interface(interface);

    return 0;
}

