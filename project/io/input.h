#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <SFML/Window/Event.hpp>

class Input {
    bool is_pressed_flag = false;
    sf::RenderWindow &window;
    mutable std::map<sf::Keyboard::Key, bool> keys;
public:
    explicit Input(sf::RenderWindow &new_window) : window(new_window) {}

    void update();

    int getAxisY() const;

    int getAxisX() const;

    bool getKeyState(sf::Keyboard::Key key) const;

    bool is_pressed() const;
};


#endif //GAME_INPUT_H
