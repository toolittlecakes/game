
#include "level1.h"

void Level1::init() {
    std::string box_filename = dir_name + "box.png";
    boxes.emplace_back(1, 3, Image(box_filename));
    boxes.emplace_back(2, 1, Image(box_filename));
    boxes.emplace_back(6, 4, Image(box_filename));
    boxes.emplace_back(4, 6, Image(box_filename));

}

void Level1::update() {
    map.move_object(player, input.getAxisX(), input.getAxisY());

    for (auto &box : boxes) {
        if (box.x == player.x && box.y == player.y) {
            map.move_object(box, input.getAxisX(), input.getAxisY());
        }
    }
}

void Level1::draw() {
    output.clean();

    output.draw(map);

    for (auto &box : boxes) {
        output.draw(box);
    }
    output.draw(player);

    output.update();
}

bool Level1::is_passed() const {
    bool result = true;
    for (int i = 0; i < boxes.size() - 1; i++) {
        if (boxes[i].x != boxes[i + 1].x || boxes[i].y != boxes[i + 1].y) {
            return false;
        }
    }

    return true;
}

void Level1::run() {

    draw();
    while (!is_passed()) {
        input.update();
        if (input.is_pressed()) {
            update();
            draw();
        }
        sf::sleep(sf::milliseconds(50));
    }
}
