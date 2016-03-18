//
//  Core.hpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Core_hpp
#define Core_hpp

#include "Runner.hpp" //THIS IS NEEDED
#include "States.h"
#include "InputHandler.hpp"

class Core : public BaseCore{
public:
    Core(){};
    ~Core();
    void draw();
    void update();
    void setup();
    void keyPressed(int key);
    void keyReleased(int key);
    void mousePressed(int button);
    void mouseReleased(int button);
    void exitCalled();
    MenuState* menuState;
    GameState* gameState;
    MapCreationState* mapCreationState;
    std::shared_ptr<InputHandler> inputHandler;
    
};

#endif /* Core_hpp */
