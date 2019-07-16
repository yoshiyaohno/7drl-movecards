#include "interface.h"
#include "game.h"

int main()
{
    Game *game = init_game();
    Interface *interface = init_interface(game);

    int ch;

    while ('q' != (ch = getch())) {
        process(game);
        resolve_input(interface, ch);
        draw_interface(interface);
    }

    // main loop:
        // process entities
        // draw map and interface, refresh
        // accept input
        // send input to interface to handle

    free_game(game);
    free_interface(interface);

    return 0;
}

