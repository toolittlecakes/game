#include <SFML/Graphics.hpp>
#include "game/Map.h"
#include "game/level.h"
#include "game/Game.h"

int main()
{
    Game game;
    game.init();
    game.run();

    return 0;
}