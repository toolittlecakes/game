
#ifndef GAME_OUTPUT_H
#define GAME_OUTPUT_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "../game/object.h"
#include "../game/Map.h"

class Output {
    sf::RenderWindow* window;
    int x_corner = 266;
    int y_corner = 64;
    Image background {"../images/background.png"};

public:
    void init(sf::RenderWindow* new_window) {
        window = new_window;
        update();
    }
    void update() {
        window->display();
        window->clear();
        window->draw(background.getSprite());
    }

    void draw_image(Image& image, int x, int y) {
        sf::Sprite sprite = image.getSprite();
        int width = image.width;
        int height = image.heights;
        sprite.move(x * width + x_corner, y * height + y_corner);
        window->draw(sprite);
    }

    void draw(Object& object) {
        draw_image(object.image, object.x, object.y);
    }

    void draw(Map& map) {
        for(int i = 0; i < map.height; i++) {
            for(int j = 0; j < map.width; j++) {
                draw_image(map.get_image(i, j), j, i);
            }
        }
    }

};
#endif //GAME_OUTPUT_H
