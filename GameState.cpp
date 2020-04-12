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
}

void GameState::HandleInput() {
    sf::Event event;

    while( _data->window.pollEvent( event )) {

        switch(event.type) {
            case sf::Event::Closed:
                _data->window.close();
                break;

            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case 0:
                        //Spostamento a sinistra
                        break;
                    case 3:
                        //Spostamento a destra
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
    _data->window.display();
}