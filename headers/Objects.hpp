#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

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
