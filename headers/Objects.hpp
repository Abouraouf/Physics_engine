#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

#define LINE_WIDTH 5.0f

class Objects
{
	private:
		float x, y;
		float width, height;
		float r, g, b;
		std::string type;
		int state;
	public:
		Objects();
		~Objects();
};
