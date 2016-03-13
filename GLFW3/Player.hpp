//
//  Player.hpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <algorithm>
#include "Creature.hpp"
#include "Handlers.h"
#include "Tile.hpp"
#include "Timer.hpp"
#include "Item.hpp"
#include "Inventory.hpp"
#include <dT/drawtext.h>

class Player : public GameObject{
public:
    Player(const Math::Vector2D &scene, const Math::Vector2D &position, const Graphics::Rect &bounds, bool visible);
    virtual void render();
    virtual void update();
    float speed = 8;
    std::shared_ptr<WorldHandler>  worldHandler;
    std::shared_ptr<InputHandler> inputHandler;

    struct dtx_font *font;
    
    //collection and mining stuff
    void stopMining();
    bool mining = false;
    float inventoryItemDisplayAlpha = 0;
    float miningTime = 0;
    //the current interacted tile
    int selectedX = 0, selectedY = 0;
    int miningType = 0, miningLevel = 0;
    int inventorySelected = 0;
    Math::Timer timer;
    Inventory inv;
};

#endif /* Player_hpp */
