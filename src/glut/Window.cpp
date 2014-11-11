#include "glut/Window.hpp"

namespace glut {
    void Window::initialize(const WindowParameters& params) {
        this->params = params;
        this->size = params.size;
        this->position = params.position;
        this->clearFlag = params.getClearFlag();
        this->visible = true;

        if (params.fullscreen)
            setFullscreen(true);

        glutInitDisplayMode(params.getDisplayModeFlag());
        onInitialize();

        elapsedTime = glutGet(GLUT_ELAPSED_TIME);
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
        glutReshapeWindow(size.x, size.y);
        this->size = size;
    }

    Point2i Window::getPosition() const {
        return Point2i(
            glutGet(GLUT_WINDOW_X),
            glutGet(GLUT_WINDOW_Y)
        );
    }

    void Window::setPosition(const Point2i& position) {
        glutPositionWindow(position.x, position.y);
        this->position = position;
    }

    void Window::setFullscreen(const bool enable) {
        if (enable) {
            position = getPosition();
            size = getSize();
            glutFullScreen();
        } else {
            setSize(size);
            setPosition(position);
        }

        fullscreen = enable;
    }

    void Window::toggleFullscreen() {
        setFullscreen(!isFullscreen());
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

        const auto time = glutGet(GLUT_ELAPSED_TIME);
        onRender(time - elapsedTime);
        elapsedTime = time;

        if (params.doubleBuffer)
            glutSwapBuffers();
        else
            glFlush();
    }
}
