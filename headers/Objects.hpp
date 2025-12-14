#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <string>

#define LINE_WIDTH 5.0f

class Objects {
public:
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

    virtual ~Objects();
};


class Triangle : public Objects {
public:
    Triangle();
    void draw() override;

    //moovement
    bool isClicked(int mx, int my) override;
    void startDrag(int mx, int my) override;
    void stopDrag() override;
    void dragTo(int mx, int my) override;
    void put_in_middle() override;
    
    
    ~Triangle() override {};
};

class Square : public Objects {
public:
    void draw() override;
    ~Square() override {};
};

class Circle : public Objects {
public:
    void draw() override;
    ~Circle() override {};
};