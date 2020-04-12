#ifndef SFML_EXPLORE_MAINMENUSTATE_HPP
#define SFML_EXPLORE_MAINMENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

class MainMenuState : public State{
public:
    MainMenuState(GameDataRef data);

    void Init();

    void HandleInput();

    void Update( float dt );

    void Draw( float dt );

private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite _title;
    sf::Sprite _startButton;
};

#endif //SFML_EXPLORE_MAINMENUSTATE_HPP
