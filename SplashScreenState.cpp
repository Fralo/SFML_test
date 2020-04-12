#include <sstream>
#include "SplashScreenState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include <iostream>

int frame_processati = 0;

SplashScreenState::SplashScreenState(GameDataRef data) : _data(data) {}

void SplashScreenState::Init() {
    _data->assets.LoadTexture("Splash Screen State Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);
    _background.setTexture(this->_data->assets.GetTexture("Splash Screen State Background"));
    //_background.setTextureRect(sf::IntRect(0, 0, 622, 324));
    _background.setColor(sf::Color(0,255,128,255));
    _background.setPosition( (SCREEN_WIDTH - _background.getGlobalBounds().width)/2 , (SCREEN_HEIGHT - _background.getGlobalBounds().height) /2);
}

void SplashScreenState::HandleInput() {
    sf::Event event;

    while( _data->window.pollEvent( event )) {

        switch(event.type) {
            case sf::Event::Closed:
                _data->window.close();
                break;

            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case 0:
                        _data->window.close();
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

void SplashScreenState::Update(float dt) {
    if(_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME ) {
        _data->machine.AddState( StateRef( new MainMenuState(_data ) ), true);
    }
}

void SplashScreenState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw( _background );
    _data->window.display();
    //std::cout << ++frame_processati << std::endl;
}