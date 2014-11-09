#include "glut/Application.hpp"

namespace glut {
    Application::Application() {
        windowManager = new WindowManager();
    }

    Application::~Application() {
        delete windowManager;
    }

    void Application::initialize(int argc, char* argv[]) {
        glutInit(&argc, argv);
        WindowDispatcher::initialize(windowManager);
    }

    void Application::run() {
        glutMainLoop();
    }

    void Application::addWindow(Window* window, const WindowParameters& params) {
        windowManager->add(window, params);
        WindowDispatcher::set(window);
        window->initialize(params);
        window->onResize(params.size);
    }

}
