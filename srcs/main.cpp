#include "../headers/Objects.hpp"
#include "../headers/Window.hpp"

void drawHoriSplit(float fraction)
{
    float splitX = WINDOW_HEIGHT * fraction;

    glColor3f(0.5f, 0.5f, 0.5f);
    glLineWidth(LINE_WIDTH);
    glBegin(GL_LINES);
        glVertex2f(0, splitX);
        glVertex2f(WINDOW_WIDTH,splitX);
    glEnd();
}

void drawSmallSplit(float fraction)
{
    float splitX_1 = (WINDOW_HEIGHT * fraction);
    float splitX_2 = (WINDOW_HEIGHT * (fraction * 2));
    float splitX_3 = (WINDOW_HEIGHT * (fraction * 3));

    glColor3f(0.5f, 0.5f, 0.5f);
    glLineWidth(LINE_WIDTH);
    glBegin(GL_LINES);
        glVertex2f(splitX_1, 0);
        glVertex2f(splitX_1,splitX_1);
        glVertex2f(splitX_2, 0);
        glVertex2f(splitX_2,splitX_1);
        glVertex2f(splitX_3, 0);
        glVertex2f(splitX_3,splitX_1);

    glEnd();
}


void display()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Set up 2D coordinates matching your window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT); // left, right, bottom, top
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw the split line
    drawHoriSplit(0.33f);
    drawSmallSplit(0.33f);

    glutSwapBuffers();
}


int main(int argc, char **argv)
{
    Window window;
    glutInit(&argc, argv);                        
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow(window.get_name().c_str());        
    glutDisplayFunc(display);                      
    glutMainLoop();                               
    return 0;
}
