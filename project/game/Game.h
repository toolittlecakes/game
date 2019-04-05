#ifndef GAME_GAME_H
#define GAME_GAME_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../io/output.h"
#include "../io/input.h"
#include "levels/level.h"
#include "levels/level1.h"

class Game {
    sf::RenderWindow window;
    Input input;
    Output output;
    std::vector<std::unique_ptr<Level>> levels;

public:
    Game(): input(window), output(window) {
        window.create(sf::VideoMode(1300, 768), "Game");
        levels.emplace_back(std::make_unique<Level1>(input, output));
    }
    void run() {
        try {
            for (auto &level : levels) {
                level->init();
                level->run();
            }
        }
        catch (std::logic_error&) {}
        window.close();
    }
};
#endif //GAME_GAME_H
