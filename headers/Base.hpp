#pragma once
#include "Objects.hpp"
#include "Window.hpp"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>

class Base {
public:
    int max;

    Base();
    std::vector<Objects*> objects;
    void display();
    void drawHoriSplit(float fraction);
    int  calulate_object(const std::string& type);
};
extern Base* g_base;
