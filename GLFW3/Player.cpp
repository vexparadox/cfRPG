//
//  Player.cpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#include "Player.hpp"

Player::Player(const Math::Vector2D &scene, const Math::Vector2D &position, const Graphics::Rect &bounds, bool visible): GameObject(scene, position, bounds, visible){
    worldHandler = WorldHandler::getInstance();
    inputHandler = InputHandler::getInstance();
}

void Player::update(){
    int thisMouseX = inputHandler->getMouseX();
    int thisMouseY = inputHandler->getMouseY();
    bool movement = false;
    Math::Vector2D sv;
    //on player movement
    if(inputHandler->getDOWN()){
        sv.y += speed;
        movement = true;
    }
    if(inputHandler->getUP()){
        sv.y += -speed;
        movement = true;
    }
    if(inputHandler->getRIGHT()){
        sv.x += speed;
        movement = true;
    }
    if(inputHandler->getLEFT()){
        sv.x += -speed;
        movement = true;
    }
    worldHandler->movementCheck(editPosition(), sv, editScene(), true, true);
    
//    if(inputHandler->getSPACE() && getVelocity().y == 0){
//        sv.y += -speed*2;
//    }
//    if(getVelocity().x != 0 && getVelocity().y != 0){
//        //do the movement given from the player
//        std::cout << getVelocity().x << " " << getVelocity().y << std::endl;
//        movement = true;
//    }else{
//        movement = false;
//    }
    
    //you can't mine whilst moving
    if(!movement){
        //if the LMB is pressed and you're not already mining, start the checks to start mining
        if(inputHandler->getMOUSE0() && !mining){
            //get the distance between the mouse and the player
            float distance = Math::vectorDistance(getPosition().x+SPRITE_SIZE/2, getPosition().y+SPRITE_SIZE/2, thisMouseX, thisMouseY);
            
            //only if the distance is less than the spritesize*3 then we should start mining
            if(distance < SPRITE_SIZE*3){
                WorldHandler::Tile tile = *worldHandler->getTile(thisMouseX, thisMouseY);
                if(tile.solid){
                    miningTime = tile.strength;
                    miningType = tile.textureCode;
                    miningX = thisMouseX-(thisMouseX%SPRITE_SIZE);
                    miningY = thisMouseY-(thisMouseY%SPRITE_SIZE);
                    mining = true;
                    timer.start();
                }
            }
        }
        //if you're currently mining then check you're still holding that LMB
        if(mining){
            int x = thisMouseX-(thisMouseX%SPRITE_SIZE);
            int y = thisMouseY-(thisMouseY%SPRITE_SIZE);
            
            //check if you're still on the original tile
            if(x != miningX || y!= miningY){
                this->stopMining();
            }else if(!inputHandler->getMOUSE0()){
                this->stopMining();
            }else{
                //if the mining is still happening
                if(timer.elapsedTime() >= miningTime){
                    this->pickup(worldHandler->getTile(thisMouseX, thisMouseY));
                    worldHandler->getTile(thisMouseX, thisMouseY) = &worldHandler->getTiles()[0];
                    this->stopMining();
                }
                else if(timer.elapsedTime() >= miningTime-(miningTime/4)){
                    miningLevel = 3;
                } else if(timer.elapsedTime() >= miningTime/2){
                    miningLevel = 2;
                } else if(timer.elapsedTime() >= miningTime/4){
                    miningLevel = 1;
                }
            }
        }
    }else if(mining){
        std::cout << "you moved" << std::endl;
        this->stopMining();
    }
}


void Player::pickup(WorldHandler::Tile *tile){
    inventory.push_back(inventoryItem(tile, 1));
}

void Player::stopMining(){
    mining = false;
    miningLevel = 0;
    timer.reset();
}

void Player::render(){
    //if mining draw the level of destruction over the current tile
    if(mining){
        switch(miningLevel){
        case 1:
            SpriteHandler::getInstance()->get(destruction1)->draw(miningX, miningY, SPRITE_SIZE, SPRITE_SIZE);
            break;
        case 2:
            SpriteHandler::getInstance()->get(destruction2)->draw(miningX, miningY, SPRITE_SIZE, SPRITE_SIZE);
            break;
        case 3:
            SpriteHandler::getInstance()->get(destruction3)->draw(miningX, miningY, SPRITE_SIZE, SPRITE_SIZE);
            break;
        }
    }
    SpriteHandler::getInstance()->get(SPRITE_CODE::player)->draw(this->getPosition());
}