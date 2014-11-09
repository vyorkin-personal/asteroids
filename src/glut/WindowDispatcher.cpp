#include "glut/WindowDispatcher.hpp"

namespace glut {
    WindowDispatcher::WindowDispatcher(WindowManager* windowManager):
	windowManager{windowManager} {}

    void WindowDispatcher::register(Window* window) {
        glutDisplayFunc(displayFunc);
        glutReshapeFunc(reshapeFunc);
        glutVisibilityFunc(visibilityFunc);
        glutCloseFunc(closeFunc);

        glutMouseFunc(mouseFunc);
        glutMouseWheelFunc(mouseWheelFunc);
        glutKeyboardDownFunc(keyboardDownFunc);
        glutKeyboardUpFunc(keyboardUpFunc);
        glutSpecialDownFunc(specialDownFunc);
        glutSpecialUpFunc(specialUpFunc);
        glutJoystickFunc(joytickFunc);

        glutMotionFunc(motionFunc);
        glutPassiveMotionFunc(passiveMotionFunc);
    }

    void WindowDispatcher::reshapeFunc(int width, int height) {
        getCurrentWindow()->onResize(width, height);
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

    void WindowDispatcher::closeFunc() {
        getCurrentWindow()->onClose();
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

        if (state == GLUT_UP)
            window->onMouseButtonUp(mouseButton, x, y);
        else
            window->onMouseButtonDown(mouseButton, x, y);
    }

    void WindowDispatcher::mouseWheelFunc(int wheelNumber, int direction, int x, int y) {
        getCurrentWindow()->onMouseWheel(wheelNumber, direction, x, y);
    }

    void WindowDispatcher::keyboardDownFunc(unsigned char key, int x, int y) {
        getCurrentWindow()->onKeyDown(0, key);
    }

    void WindowDispatcher::keyboardUpFunc(unsigned char key, int x, int y) {
        getCurrentWindow()->onKeyUp(0, key);
    }

    void WindowDispatcher::specialDown(int key, int x, int y) {
        getCurrentWindow()->onKeyDown(key, 0);
    }

    void WindowDispatcher::specialUp(int key, int x, int y) {
        getCurrentWindow()->onKeyUp(key, 0);
    }

    void WindowDispatcher::joystickFunc(unsigned int buttonMask, int x, int y, int z) {
    }

    void WindowDispatcher::motionFunc(int x, int y) {
        getCurrentWindow()->onMouseMove(x, y);
    }

    void WindowDispatcher::passiveMotionFunc(int x, int y) {
        getCurrentWindow()->onMouseMove(x, y);
    }

    MouseButton WindowDispatcher::getMouseButton(const int button) const {
        switch (button) {
            case GLUT_LEFT_BUTTON: return MouseButton::Left;
            case GLUT_RIGHT_BUTTON: return MouseButton::Right;
            case GLUT_MIDDLE_BUTTON: return MouseButton::Middle;
            default: return MouseButton::None;
        };
    }
}
