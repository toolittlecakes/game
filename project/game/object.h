#include <utility>

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "image.h"

struct Object {
    int x;
    int y;
    Image image;
    Object(int _x, int _y, Image _image) : x(_x), y(_y), image(std::move(_image)){}

    void move(int x_step, int y_step);
};
#endif //GAME_OBJECT_H
