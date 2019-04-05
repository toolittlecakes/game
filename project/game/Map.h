#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <string>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include "image.h"
#include "object.h"

class Map {
    Image image;
public:
    int height = 10;
    int width = 12;


    explicit Map(int level) : image(std::string("../images/level") + std::to_string(level) + "/field.png") {}

    const Image &get_image(int i, int j) const;

    void move_object(Object &obj, int x_step, int y_step);
};

#endif //GAME_MAP_H
