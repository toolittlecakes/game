//
// Created by toolittlecakes on 4/1/19.
//

#include "output.h"

void Output::update() {
    window.display();
}

void Output::clean() {
    window.clear();
    window.draw(background.getSprite());
}

void Output::draw_image(const Image &image, int x, int y) {
    sf::Sprite sprite = image.getSprite();
    int width = image.width;
    int height = image.heights;
    sprite.move(x * width + x_corner, y * height + y_corner);
    window.draw(sprite);
}

void Output::draw(Object &object) {
    draw_image(object.image, object.x, object.y);
}

void Output::draw(Map &map) {
    for(int i = 0; i < map.height; i++) {
        for(int j = 0; j < map.width; j++) {
            draw_image(map.get_image(i, j), j, i);
        }
    }
}
