#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H


#include <SFML/Window.hpp>
#include "Map.h"
#include "object.h"
#include "../io/output.h"
#include "../io/input.h"

class Level {
protected:
    int number;
    Map map;
    std::string dir_name;
    Input& input;
    Output& output;
public:
    Level(int num, Input& in, Output& out) : number(num), map(num), input(in), output(out) {
        dir_name =  "../images/level" + std::to_string(number) + '/';
    }
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual bool is_passed() = 0;


    virtual ~Level(){}
};




class Level1: public Level {
    std::vector<Object> boxes;
    Object player{5, 5, Image(dir_name + "player.png")};
public:
    Level1(Input& in, Output& out) : Level(1, in, out) {

    }


    void init() {
        std::string box_filename = dir_name + "box.png";
        boxes.emplace_back(1, 3, Image(box_filename));
        boxes.emplace_back(2, 1, Image(box_filename));
        boxes.emplace_back(6, 4, Image(box_filename));
        boxes.emplace_back(4, 6, Image(box_filename));

    }

    void update() {
        map.move_object(player, input.getAxisX(), input.getAxisY());

        for(int i = 0; i < boxes.size(); i++) {
            if(boxes[i].x == player.x && boxes[i].y == player.y) {
                map.move_object(boxes[i], input.getAxisX(), input.getAxisY());
            }
        }
    }

    void draw() {
        output.draw(map);

        for (int i = 0; i < boxes.size(); i++) {
            output.draw(boxes[i]);
        }
        output.draw(player);

        output.update();
    }



    bool is_passed() {
        return player.x == 1 && player.y == 1;
    }



    void run() {

        draw();
        while (is_passed() == false) {
            input.update();
            if(input.is_pressed()) {
                update();
                draw();
            }
            sf::sleep(sf::milliseconds(50));
        }
    }
};



#endif //GAME_LEVEL_H
