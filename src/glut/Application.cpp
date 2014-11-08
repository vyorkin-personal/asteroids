#include "glut/Application.hpp"

namespace glut {
    Application::Application()
        windowManager = new WindowManager();
        windowDispatcher = new WindowDispatcher(windowManager);
    }

    Application::~Application() {
        delete windowDispatcher;
        delete windowManager;
    }

    void Application::initialize(int argc, char* argv[]) {
        glutInit(&argc, argv);
    }

    void Application::addWindow(Window* window, const WindowParameters& params) {
        windowManager->add(window, params);
        windowDispatcher->register(window);
        window->initialize();
    }
}
