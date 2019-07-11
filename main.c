#include "interface.h"
#include "game.h"

int main()
{
    Game *game = init_game();
    Interface *interface = init_interface(game);

    draw_map(interface);

    getch();
    endwin();

    return 0;
}

