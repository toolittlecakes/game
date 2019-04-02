#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <string>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include "image.h"
#include "object.h"

class Map {
    std::vector<Image> images;
public:
    int height = 10;
    int width = 12;


    Map(int level) {
        std::string path = std::string("../images/level") + std::to_string(level) + '/';
        std::string filename = path + "field.png";
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                Image img(filename);
                images.emplace_back(img);
            }
        }
    }
    Image& get_image(int i, int j) {
        return images[i * width + j];
    }
    void move_object(Object& obj, int x_step, int y_step) {
        if (obj.x + x_step < width && obj.x + x_step >=0 ) {
            obj.move(x_step, 0);
        }
        if (obj.y + y_step < height && obj.y + y_step >=0 ) {
            obj.move(0, y_step);
        }
    }
};

#endif //GAME_MAP_H
