//
//  Graphics.cpp
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Graphics.hpp"
#include "Runner.hpp"
namespace Graphics{
    void drawTriangle(Triangle& t){
        drawTriangle(t.v1, t.v2, t.v3);
    }

    void drawTriangle(const Math::Vector2D &v1, const Math::Vector2D &v2, const Math::Vector2D &v3){
        drawTriangle(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y);
    }

    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3){
        glBegin(GL_TRIANGLES);
        glVertex3f(x1, y1, 0.f);
        glVertex3f(x2, y2, 0.f);
        glVertex3f(x3, y3, 0.f);
        glEnd();
    }

    void drawRect(float x, float y, float w, float h){
        glBegin(GL_QUADS);
        glVertex3f(x, y, 0.0f);
        //top left
        glVertex3f(x, y+h, 0.0f );
        //bottom left
        glVertex3f(x+w, y+h, 0.0f );
        //bottom right
        glVertex3f(x+w, y, 0.0f );
        //top right
        glEnd();
    }

    void drawRect(const Math::Vector2D &v, float w, float h){
        drawRect(v.x, v.y, w, h);
    }
    
    void drawPoly(Polygon &p){
        glBegin(GL_POLYGON);
        for(auto points : p.getVerticies()){
            glVertex3f(points.x, points.y, 0.0f);
        }
        glEnd();
    }
    
    void drawPoly(std::vector<Math::Vector2D>& v){
        glBegin(GL_POLYGON);
        for(auto points : v){
            glVertex3f(points.x, points.y, 0.0f);
        }
        glEnd();
    }
    
    
    std::vector<unsigned char> getScreenData(int x, int y, int w, int h){
        std::vector<unsigned char> data(4*w*h);
        glReadPixels(x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, &data[0]);
        return data;
    }    
    void setBackground(float r, float g, float b, float a){
        Runner::r = r/255;
        Runner::g = g/255;
        Runner::b = b/255;
        Runner::a = a/255;
    }
    
    void setBackground(float r, float g, float b){
        setBackground(r, g, b, 0);
    }
    
    void setBackground(const Colour &c){
        setBackground(c.r, c.g, c.b, c.a);
    }
}