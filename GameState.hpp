//
// Created by leonardo on 12/04/20.
//

#ifndef SFML_EXPLORE_GAMESTATE_HPP
#define SFML_EXPLORE_GAMESTATE_HPP


#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

class GameState  : public State{
public:
    GameState(GameDataRef data);

    void Init();

    void HandleInput();

    void Update(float dt);

    void Draw( float dt );

private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite omino;
};



#endif //SFML_EXPLORE_GAMESTATE_HPP
