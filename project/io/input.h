#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <SFML/Window/Event.hpp>

class Input {
    bool is_pressed_flag = false;
    sf::RenderWindow *window = nullptr;
    std::map<sf::Keyboard::Key, bool> keys;
public:
    void init(sf::RenderWindow *new_window) {
        window = new_window;
    }

    void update() {
        sf::Event event{};
        is_pressed_flag = false;
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
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

    int getAxisY() {
        return (keys[sf::Keyboard::Key::S] || keys[sf::Keyboard::Key::Down]) -
               (keys[sf::Keyboard::Key::W] || keys[sf::Keyboard::Key::Up]);
    }


    int getAxisX() {
        return (keys[sf::Keyboard::Key::D] || keys[sf::Keyboard::Key::Right]) -
               (keys[sf::Keyboard::Key::A] || keys[sf::Keyboard::Key::Left]);

    }

    bool getKeyState(sf::Keyboard::Key key) { return keys[key]; }

    bool is_pressed() { return is_pressed_flag; }
};


#endif //GAME_INPUT_H
