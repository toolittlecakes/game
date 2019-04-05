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

    explicit Image(const std::string &filename);

    const sf::Texture &getTexture() const;

    sf::Sprite getSprite() const;
};

#endif //GAME_IMAGE_H
