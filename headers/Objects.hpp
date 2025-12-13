#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <string>

#define LINE_WIDTH 5.0f

class Objects {
public:
    float x, y;
    float width, height;
    float r, g, b;
    std::string type;
    int state;

    Objects();
    virtual void draw() = 0;
    virtual ~Objects();
};

class Triangle : public Objects {
public:
    void draw() override;
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