//
//  GameState.hpp
//  Project2
//
//  Created by William Meaton on 21/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include <stdio.h>
#include "State.hpp"
#include "Handlers.h"

class GameState : public State{
public:
    GameState();
    ~GameState(){};
    void update();
    void draw();
};
#endif /* GameState_hpp */