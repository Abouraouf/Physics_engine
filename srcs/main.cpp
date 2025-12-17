#include "../headers/Objects.hpp"
#include "../headers/Window.hpp"
#include "../headers/Base.hpp"
#include "../headers/Triangle.hpp"
#include "../headers/Square.hpp"

Base *g_base = NULL;

void bridge_display() {
    g_base->display();
}

void update() {
    static auto lastTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = currentTime - lastTime;
    float dt = elapsed.count(); 
    lastTime = currentTime;

    for (auto obj : g_base->objects) {
        if (obj->type == "Triangle")
        {
            if (Triangle* tri = dynamic_cast<Triangle*>(obj)) {
                tri->update(dt); 
            }
        }
        else
            if (Square* squ = dynamic_cast<Square*>(obj)) {
                squ->update(dt);
            }
    }
    glutPostRedisplay();
}

Objects *create_object(const Objects& object)
{
    if (object.type == "Triangle")
        return new Triangle;
    else
        return new Square;
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
                if (g_base->calulate_object(obj->type) < g_base->max)
                    g_base->objects.push_back(create_object(*obj));
                glutPostRedisplay();
                return;
            }
        }
    }
    else if (button == GLUT_RIGHT_BUTTON){
            for (auto obj : g_base->objects) {
                if (obj->isClicked(mx, flippedY)) {
            if (state == GLUT_UP) {
                    obj->putback();
            }
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
    Square* square = new Square();
    App.objects.push_back(triangle);
    App.objects.push_back(square);
    g_base = &App;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    int window_id = glutCreateWindow(window.get_name().c_str());
    glutDisplayFunc(bridge_display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutIdleFunc(update);
    glutMainLoop();

    for(auto obj : g_base->objects){
        delete obj;
    }
    glutDestroyWindow(window_id);
    return 0;
}
