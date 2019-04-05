#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H


#include <SFML/Window.hpp>
#include "../Map.h"
#include "../object.h"
#include "../../io/output.h"
#include "../../io/input.h"

class Level {
protected:
    const int number;
    Map map;
    const std::string dir_name;
    Input &input;
    Output &output;
public:
    Level(int num, Input &in, Output &out) : number(num), map(num), input(in), output(out),
                                             dir_name("../images/level" + std::to_string(number) + '/') {
    }

    virtual void init() = 0;

    virtual void update() = 0;

    virtual void draw() = 0;

    virtual void run() = 0;

    virtual bool is_passed() const = 0;


    virtual ~Level() = default;
};



#endif //GAME_LEVEL_H
