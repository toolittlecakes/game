
#include "image.h"

Image::Image(const std::string &filename) {
    texture.loadFromFile(filename);
    texture.setSmooth(true);
    width = texture.getSize().x;
    heights = texture.getSize().y;
}

const sf::Texture &Image::getTexture() const {
    return texture;
}

sf::Sprite Image::getSprite() const {
    sf::Sprite sprite(texture);
    return sprite;
}
