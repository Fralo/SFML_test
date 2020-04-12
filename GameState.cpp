#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include <iostream>

int frame_processati = 0;

GameState::GameState(GameDataRef data) : _data(data) {}

void GameState::Init() {
    _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_PATH);
    _background.setTexture(this->_data->assets.GetTexture("Game Background"));
    _data->assets.LoadTexture("omino", OMINO);
    omino.setTexture(this->_data->assets.GetTexture("omino"));
    omino.setScale(0.1f, 0.1f);
    omino.setPosition(100, 100);
}

void GameState::HandleInput() {
    sf::Event event;

    while( _data->window.pollEvent( event )) {
        sf::Vector2f newPos;
        switch(event.type) {
            case sf::Event::Closed:
                _data->window.close();
                break;

            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case 71:
                        //Spostamento a sinistra
                        newPos = sf::Vector2f(omino.getPosition().x -5, omino.getPosition().y);
                        if(newPos.x >=50) {
                            omino.setPosition(newPos);
                        }
                        break;
                    case 72:
                        //Spostamento a destra
                        newPos = sf::Vector2f(omino.getPosition().x + 5, omino.getPosition().y);
                        if(newPos.x + omino.getGlobalBounds().width <=650) {
                            omino.setPosition(newPos);
                        }
                        break;
                    case 73:
                        //Spostamento alto
                        newPos = sf::Vector2f(omino.getPosition().x, omino.getPosition().y - 5);
                        if(newPos.y>= 50) {
                            omino.setPosition(newPos);
                        }
                        break;
                    case 74:
                        newPos = sf::Vector2f(omino.getPosition().x, omino.getPosition().y  + 5);
                        if(newPos.y + omino.getGlobalBounds().height<= 550) {
                            omino.setPosition(newPos);
                        }
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void GameState::Update(float dt) { }

void GameState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw( _background );
    _data->window.draw(omino);
    _data->window.display();
}