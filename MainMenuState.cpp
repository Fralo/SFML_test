//
// Created by leonardo on 12/04/20.
//

#include "MainMenuState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include <iostream>



MainMenuState::MainMenuState(GameDataRef data) : _data(data) {}

void MainMenuState::Init() {
    _data->assets.LoadTexture("Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
    _data->assets.LoadTexture("Title", START_BUTTON_PATH);
    _data->assets.LoadTexture("Start Button", MENU_TITLE_PATH);

    _background.setTexture(_data->assets.GetTexture("Menu Background"));
    _title.setTexture(_data->assets.GetTexture("Start Button"));
    _startButton.setTexture(_data->assets.GetTexture("Title"));

    _background.setScale(0.5,0.5);
    _title.setScale(0.5,0.5);
    _startButton.setScale(0.05f, 0.05f);

    _title.setPosition( ( SCREEN_WIDTH - _title.getGlobalBounds().width) / 2, _title.getGlobalBounds().height);
    _startButton.setPosition(( SCREEN_WIDTH - _startButton.getGlobalBounds().width) / 2, _title.getGlobalBounds().height + 250 );
}

void MainMenuState::HandleInput() {
    sf::Event event;

    while( _data->window.pollEvent( event )) {

        switch(event.type) {
            case sf::Event::Closed:
                _data->window.close();
                break;
        }

        //Controllare il click
        if ( _data->input.IsSpriteClicked(_startButton, sf::Mouse::Left, _data->window) ) {
            //std::cout<< "Game Started !" << std::endl;
            _data->machine.AddState( StateRef( new GameState(_data)), true);
        }
    }
}

void MainMenuState::Update( float dt ) {};

void MainMenuState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw( _background );
    _data->window.draw( _title );
    _data->window.draw( _startButton );
    _data->window.display();
}