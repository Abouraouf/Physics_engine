#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <chrono>
#define LINE_WIDTH 5.0f

class Objects {
public:
    //gravity
    float velocity_y;
    float gravity;
    //moovement
    float x_start, y_start;
    float x, y;
    float width, height;
    float xoffset = 0, yoffset = 0;
    float r, g, b;
    std::string type;
    int state;
    bool center;
    bool dragged;

    Objects();
    virtual void draw() = 0;

    //moovement
    virtual bool isClicked(int mx, int my) = 0;
    virtual void startDrag(int mx, int my) = 0;
    virtual void put_in_middle() = 0;
    virtual void stopDrag() = 0;
    virtual void dragTo(int mx, int my) = 0;
    virtual void checkCollision(Objects* Other) = 0;
    virtual void putback() = 0;

    //gravity
    virtual void apply_gravity(float dt) = 0;
    virtual void update(float dt);
    virtual ~Objects();

};
