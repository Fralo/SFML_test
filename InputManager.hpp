#ifndef SFML_EXPLORE_INPUTMANAGER_HPP
#define SFML_EXPLORE_INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>

class InputManager {
public:
    InputManager() { }
    ~InputManager() { }

    bool IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

    sf::Vector2i  GetMousePosition( sf::RenderWindow& window );
};


#endif //SFML_EXPLORE_INPUTMANAGER_HPP
