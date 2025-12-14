#include "../headers/Objects.hpp"
#include "../headers/Window.hpp"
#include "../headers/Base.hpp"

Base* g_base = nullptr;

void bridge_display() {
    g_base->display();
}

void mouse(int button, int state, int mx, int my) {
    int flippedY = WINDOW_HEIGHT - my;
    if (button == GLUT_LEFT_BUTTON) {
        for (auto obj : g_base->objects) {
            if (obj->isClicked(mx, flippedY)) {
                if (state == GLUT_DOWN) {
                    if (obj->center) {
                        obj->startDrag(mx, flippedY);
                    } else {
                        obj->put_in_middle();
                    }
                } else if (state == GLUT_UP) {
                    obj->stopDrag();
                }
                glutPostRedisplay();
                return;  // handle only one object
            }
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
