#ifndef GAME_GAME_H
#define GAME_GAME_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../io/output.h"
#include "../io/input.h"
#include "level.h"

class Game {
    sf::RenderWindow window;
    Input input;
    Output output;

public:
    void init() {
        window.create(sf::VideoMode(1300, 768), "Game");


        input.init(&window);
        output.init(&window);

    }
    void run() {

        Level1 level1(input, output); // создает уровень, заполняет поля класса Level и создает пустой вектор коробочек и игрока
        level1.init(); // заполняет вектор коробочек
        level1.run(); // сама игра (процесс)

        window.close();
    }
};
#endif //GAME_GAME_H
