
#include "input.h"

void Input::update() {
    sf::Event event{};
    is_pressed_flag = false;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                throw std::logic_error{"game closed"};
                break;

            case sf::Event::KeyPressed:
                is_pressed_flag = true;
                keys[event.key.code] = true;
                break;
            case sf::Event::KeyReleased:
                keys[event.key.code] = false;
                break;
            default:
                break;
        }
    }
}

int Input::getAxisY() const {
    return (keys[sf::Keyboard::Key::S] || keys[sf::Keyboard::Key::Down]) -
           (keys[sf::Keyboard::Key::W] || keys[sf::Keyboard::Key::Up]);
}

int Input::getAxisX() const {
    return (keys[sf::Keyboard::Key::D] || keys[sf::Keyboard::Key::Right]) -
           (keys[sf::Keyboard::Key::A] || keys[sf::Keyboard::Key::Left]);

}

bool Input::getKeyState(sf::Keyboard::Key key) const { return keys[key]; }

bool Input::is_pressed() const { return is_pressed_flag; }
