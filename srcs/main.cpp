#include "../headers/Objects.hpp"
#include "../headers/Window.hpp"
#include "../headers/Base.hpp"

Base* g_base = nullptr;

void bridge_display() {
    g_base->display();
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
    glutMainLoop();

    return 0;
}
