#include "../headers/Objects.hpp"

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); 
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glutSwapBuffers();              
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                        
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   
    glutInitWindowSize(1400, 1000);
    glutCreateWindow("My Window");        

    glutDisplayFunc(display);                      

    glutMainLoop();                               
    return 0;
}