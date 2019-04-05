
#ifndef GAME_OUTPUT_H
#define GAME_OUTPUT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../game/object.h"
#include "../game/Map.h"

class Output {
    sf::RenderWindow &window;
    int x_corner = 266;
    int y_corner = 64;
    Image background{"../images/background.png"};

public:
    explicit Output(sf::RenderWindow &new_window) : window(new_window) {}

    void update();

    void clean();

    void draw_image(const Image &image, int x, int y);

    void draw(Object &object);

    void draw(Map &map);

};

#endif //GAME_OUTPUT_H
