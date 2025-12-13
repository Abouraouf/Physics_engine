#pragma once
#include "Objects.hpp"
#include "Window.hpp"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>

class Base {
public:
    std::vector<Objects*> objects;
    void display();
    void drawHoriSplit(float fraction);
    void drawSmallSplit(float fraction);
};