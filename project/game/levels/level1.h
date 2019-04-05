#ifndef GAME_LEVEL1_H
#define GAME_LEVEL1_H

#include "level.h"

class Level1 : public Level {
    std::vector<Object> boxes;
    Object player{5, 5, Image(dir_name + "player.png")};
public:
    Level1(Input &in, Output &out) : Level(1, in, out) {

    }

    void init() override;

    void update() override;

    void draw() override;

    bool is_passed() const override;

    void run() override;
};


#endif //GAME_LEVEL1_H
