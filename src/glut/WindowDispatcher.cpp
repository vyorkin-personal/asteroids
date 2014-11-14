#include "glut/WindowDispatcher.hpp"

namespace glut {
    WindowManager* WindowDispatcher::windowManager = nullptr;

    void WindowDispatcher::initialize(WindowManager* windowManager) {
        WindowDispatcher::windowManager = windowManager;

        glutIdleFunc(idleFunc);
        resetTimer();
    }

    void WindowDispatcher::registerCallbacks(Window* window) {
        glutDisplayFunc(displayFunc);
        glutReshapeFunc(reshapeFunc);
        glutVisibilityFunc(visibilityFunc);
        glutMouseFunc(mouseFunc);
        glutKeyboardFunc(keyboardFunc);
        glutKeyboardUpFunc(keyboardUpFunc);
        glutSpecialFunc(specialFunc);
        glutSpecialUpFunc(specialUpFunc);
        glutMotionFunc(motionFunc);
        glutPassiveMotionFunc(passiveMotionFunc);
    }

    void WindowDispatcher::reshapeFunc(int width, int height) {
        getCurrentWindow()->onResize(Size2i(width, height));
    }

    void WindowDispatcher::displayFunc() {
        getCurrentWindow()->render();
    }

    void WindowDispatcher::visibilityFunc(int state) {
        auto window = getCurrentWindow();

        if (state == GLUT_VISIBLE) {
            window->visible = true;
            window->onShow();
        } else if (state == GLUT_NOT_VISIBLE) {
            window->visible = false;
            window->onHide();
        }
    }

    void WindowDispatcher::entryFunc(int state) {
        auto window = getCurrentWindow();

        if (state == GLUT_ENTERED)
            window->onMouseEnter();
        else if (state == GLUT_LEFT)
            window->onMouseLeave();
    }

    void WindowDispatcher::mouseFunc(int button, int state, int x, int y) {
        auto window = getCurrentWindow();
        const auto mouseButton = getMouseButton(button);
        const auto position = Point2i(x, y);

        if (state == GLUT_UP)
            window->onMouseButtonUp(mouseButton, position);
        else
            window->onMouseButtonDown(mouseButton, position);
    }

    void WindowDispatcher::keyboardFunc(unsigned char key, int x, int y) {
        getCurrentWindow()->onKeyDown(0, key);
    }

    void WindowDispatcher::keyboardUpFunc(unsigned char key, int x, int y) {
        getCurrentWindow()->onKeyUp(0, key);
    }

    void WindowDispatcher::specialFunc(int key, int x, int y) {
        getCurrentWindow()->onKeyDown(key, 0);
    }

    void WindowDispatcher::specialUpFunc(int key, int x, int y) {
        getCurrentWindow()->onKeyUp(key, 0);
    }

    void WindowDispatcher::motionFunc(int x, int y) {
        getCurrentWindow()->onMouseMove(Point2i(x, y));
    }

    void WindowDispatcher::passiveMotionFunc(int x, int y) {
        getCurrentWindow()->onMouseMove(Point2i(x, y));
    }
    void WindowDispatcher::idleFunc() {
	for (const auto& it: windowManager->windows) {
	    if (it.second->isVisible())
		it.second->onIdle();
	}
    }

    void WindowDispatcher::timerFunc(int value) {
	for (const auto& it: windowManager->windows) {
	    if (it.second->isVisible()) {
                windowManager->setCurrent(it.second);
                it.second->onTimer(value);
                glutPostRedisplay();
            }
        }
        resetTimer();
    }

    void WindowDispatcher::resetTimer() {
        glutTimerFunc(24, timerFunc, 0);
    }

    MouseButton WindowDispatcher::getMouseButton(const int button) {
        switch (button) {
            case GLUT_LEFT_BUTTON: return MouseButton::Left;
            case GLUT_RIGHT_BUTTON: return MouseButton::Right;
            case GLUT_MIDDLE_BUTTON: return MouseButton::Middle;
            default: return MouseButton::None;
        };
    }
}
