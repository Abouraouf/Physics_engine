#include "../headers/Objects.hpp"
#include "../headers/Window.hpp"
#include "../headers/Base.hpp"

Base* g_base = nullptr;

void bridge_display() {
    g_base->display();
}

void update() {
    static auto lastTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = currentTime - lastTime;
    float dt = elapsed.count();  // time in seconds since last update
    lastTime = currentTime;

    for (auto obj : g_base->objects) {
        if (Triangle* tri = dynamic_cast<Triangle*>(obj)) {
            tri->update(dt);   // applies gravity if not dragged
        }
    }

    glutPostRedisplay(); // redraw the window
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
    glutIdleFunc(update);
    glutMainLoop();

    return 0;
}
