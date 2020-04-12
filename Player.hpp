//
// Created by leonardo on 12/04/20.
//

#ifndef SFML_EXPLORE_PLAYER_HPP
#define SFML_EXPLORE_PLAYER_HPP

#include "SFML/Graphics.hpp"
#include "Game.hpp"

class Player {
public:
    Player() {};
    ~Player() {};



private:
    sf::Sprite _sprite;
    int _x;
    int _y;

};


#endif //SFML_EXPLORE_PLAYER_HPP
