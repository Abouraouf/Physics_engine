#include "../headers/Objects.hpp"
#include "../headers/Window.hpp"
#include "../headers/Base.hpp"

Base* g_base = nullptr;

void bridge_display() {
    g_base->display();
}

void mouse(int button, int state, int mx, int my)
{
    int flippedY = WINDOW_HEIGHT - my;
    // int i = 0;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        for (auto obj : g_base->objects) {
                if (obj->center == true)
                    obj->startDrag(mx, flippedY);
                else
                    obj->put_in_middle();
                break;
            }
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        for (auto obj : g_base->objects) {
            if (obj->center)
                obj->stopDrag();

        }
    }
}

void motion(int mx, int my) {
    int flippedY = WINDOW_HEIGHT - my;
    for (auto obj : g_base->objects) {
        obj->dragTo(mx,flippedY);
    }
    glutPostRedisplay();
}


int main(int argc, char **argv) {
    Window window;
    Base App;

    Triangle* triangle = new Triangle();
    App.objects.push_back(triangle);
    g_base = &App;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow(window.get_name().c_str());
    glutDisplayFunc(bridge_display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();

    return 0;
}
