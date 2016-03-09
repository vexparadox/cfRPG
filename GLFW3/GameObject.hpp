//
//  GameObject.hpp
//  Project2
//
//  Created by William Meaton on 19/01/2016.
//
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "CoreMain.h"
#include "WorldHandler.hpp"

class GameObject{
    Math::Vector2D position, scene, velocity;
    Graphics::Rect bounds;
    bool visible = false;
    float gravityStrength = 2;
protected:
    GameObject(const Math::Vector2D &position, const Math::Vector2D &scene, const Graphics::Rect &bounds, bool visible = false);
public:
    const bool& isVisible();
    const Math::Vector2D& getPosition();
    Math::Vector2D& editPosition();
    const Math::Vector2D& getScene();
    Math::Vector2D& editScene();
    const Math::Vector2D& getVelocity();
    Math::Vector2D& editVelocity();
    virtual void update() = 0;
    virtual void render() = 0;
    void gravity();
    void setPosition(const Math::Vector2D &v);
    void setPosition(const float &x, const float &y);
    void setScene(const Math::Vector2D &v);
    void setScene(const float &x, const float &y);
};

#endif /* GameObject_hpp */
