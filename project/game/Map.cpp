#include "Map.h"

const Image &Map::get_image(int i, int j) const {
    return image;
}

void Map::move_object(Object &obj, int x_step, int y_step) {
    if (obj.x + x_step < width && obj.x + x_step >=0 ) {
        obj.move(x_step, 0);
    }
    if (obj.y + y_step < height && obj.y + y_step >=0 ) {
        obj.move(0, y_step);
    }
}
