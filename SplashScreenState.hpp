#ifndef SFML_EXPLORE_SPLASHSCREENSTATE_HPP
#define SFML_EXPLORE_SPLASHSCREENSTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

class SplashScreenState : public State{
public:
    SplashScreenState(GameDataRef data);

    void Init();

    void HandleInput();

    void Update(float dt);

    void Draw( float dt );

private:
    GameDataRef _data;
    sf::Clock _clock;
    //sf::Texture _backgroundTexture;
    sf::Sprite _background;
};



#endif //SFML_EXPLORE_SPLASHSCREENSTATE_HPP
