#include <sstream>
#include "SplashScreenState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

int frame_processati = 0;

SplashScreenState::SplashScreenState(GameDataRef data) : _data(data) {}

void SplashScreenState::Init() {
    _data->assets.LoadTexture("Splash Screen State Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);
    _background.setTexture(this->_data->assets.GetTexture("Splash Screen State Background"));
}

void SplashScreenState::HandleInput() {
    sf::Event event;

    while( _data->window.pollEvent( event )) {
        if( sf::Event::Closed == event.type ) {
            _data->window.close();
        }
    }
}

void SplashScreenState::Update(float dt) {
    if(_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME )
        std::cout << "Go to Main Menu" <<  std::endl;
}

void SplashScreenState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw( _background );
    _data->window.display();
    std::cout << ++frame_processati << std::endl;
}