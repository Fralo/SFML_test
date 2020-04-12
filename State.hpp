//
// Created by leonardo on 11/04/20.
//

#ifndef SFML_EXPLORE_STATE_HPP
#define SFML_EXPLORE_STATE_HPP


class State {
public:
    virtual void Init( ) = 0;
    virtual void HandleInput( ) = 0;
    virtual void Update( float dt ) = 0;
    virtual void Draw( float dt ) = 0;

    virtual void Pause( ) { }
    virtual void Resume( ) { }
};


#endif //SFML_EXPLORE_STATE_HPP
