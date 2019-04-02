#ifndef GAME_IMAGE_H
#define GAME_IMAGE_H

#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

struct Image {

    sf::Texture texture;

    int width;
    int heights;

    Image(const std::string &filename) {
        texture.loadFromFile(filename);
        texture.setSmooth(true);
        width = texture.getSize().x;
        heights = texture.getSize().y;
    }

    sf::Texture &getTexture() {
        return texture;
    }

    sf::Sprite getSprite() {
        sf::Sprite sprite(texture);
        return sprite;
    }
};

#endif //GAME_IMAGE_H
