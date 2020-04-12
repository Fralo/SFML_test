//
// Created by leonardo on 11/04/20.
//

#ifndef SFML_EXPLORE_STATEMACHINE_HPP
#define SFML_EXPLORE_STATEMACHINE_HPP

#include <memory>
#include <stack>

#include "State.hpp"

typedef std::unique_ptr<State> StateRef;

class StateMachine {

public:
    StateMachine() {};
    ~StateMachine() {};

    void AddState( StateRef newState, bool isReplacing = true);
    void RemoveState( );

    void ProcessStateChanges( );

    StateRef &GetAtciveState( );

private:
    std::stack<StateRef> _states;
    StateRef _newState;
    bool _isRemoving;
    bool _isAdding;
    bool _isReplacing;
};


#endif //SFML_EXPLORE_STATEMACHINE_HPP
