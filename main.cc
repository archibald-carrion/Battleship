#include "Game.hpp"
//#include "assemblyInterface.hpp"

/**
 * @brief main function, contain the main loop that run while the game is running aka the game's windows isn't closed
 * @return the main function return a 0 (int) 
 */
int main()
{
    Game game;
    //assemblyInterface interface;
    //game.setInterface(interface);

    while (game.running())
    {
        game.update();
        game.render();
    }
    return 0;
}