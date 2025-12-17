#include "../headers/Base.hpp"
#include "../headers/Objects.hpp"

Base::Base() : max(10)
{
}

int Base::calulate_object(const std::string& Type)
{
    int count = 0;
    for (auto obj : objects)
    {
        if (obj->type == Type)
            count++;
    }
    return count;
}


void Base::drawHoriSplit(float fraction) {
    float splitX = WINDOW_HEIGHT * fraction;

    glColor3f(0.5f, 0.5f, 0.5f);
    glLineWidth(LINE_WIDTH);
    glBegin(GL_LINES);
        glVertex2f(0, splitX);
        glVertex2f(WINDOW_WIDTH, splitX);
    glEnd();
}

void Base::display() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawHoriSplit(0.33f);
	for(Objects *obj : objects)
		obj->draw();
    glutSwapBuffers();
}