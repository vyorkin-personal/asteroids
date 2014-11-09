#include "glut/Window.hpp"

namespace glut {
    void Window::initialize(const int id, const WindowParameters& params) {
        this->id = id;
        this->params = params;
        this->clearFlag = params.getClearFlag();
        this->visible = true;

        if (params.fullscreen)
            setFullscreen();

        glutInitDisplayMode(params.getDisplayModeFlag());
        onInitialize();
    }

    void Window::setTitle(const char* title) {
        glutSetWindowTitle(title);
    }

    Size Window::getSize() const {
        return Size(
            glutGet(GLUT_WINDOW_WIDTH),
            glutGet(GLUT_WINDOW_HEIGHT)
        );
    }

    void Window::setSize(const Size& size) {
        glutReshapeWindow(size.width, size.height);
    }

    Point2i Window::getPosition() const {
        return Point2i(
            glutGet(GLUT_WINDOW_X),
            glutGet(GLUT_WINDOW_Y)
        );
    }

    void Window::setPosition(const Point2i& position) {
        glutPositionWindow(position.x, position.y);
    }

    void Window::setFullscreen(const bool enable) {
        if (enable) {
            glutFullScreen();
        } else {
            setSize(getSize());
            setPosition(getPosition());
        }

        fullscreen = enable;
    }

    void Window::show() {
        glutShowWindow();
    }

    void Window::hide() {
        glutHideWindow();
    }

    void Window::destroy() {
        glutDestroyWindow(id);
    }

    void Window::render() {
        glClear(clearFlag);

        onRender();

        if (params.doubleBuffer)
            glutSwapBuffers();
        else
            glFlash();
    }
}
