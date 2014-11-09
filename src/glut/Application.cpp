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
        glutIdleFunc(idleFunc);
        setTimer();
    }

    void Application::run() {
        glutMainLoop();
    }

    void Application::addWindow(Window* window, const WindowParameters& params) {
        windowManager->add(window, params);
        windowDispatcher->register(window);
        window->initialize();
        window->onResize();
    }

    void Application::idleFunc() {
	for (const auto& it: windowManager->windows) {
	    if (it.second->isVisible())
		it.second->onIdle();
	}
    }

    void Application::timerFunc(int value) {
	for (const auto& it: windowManager->windows) {
	    if (it.second->isVisible()) {
                windowManager->setCurrent(it.second);
                it.second->onTimer(value);
                glutPostRedisplay();
            }
        }
        setTimer();
    }

    void Application::setTimer() {
        glutTimerFunc(24, timerFunc, 0);
    }
}
