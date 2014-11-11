#include "glut/GameWindow.hpp"

namespace glut {
    GameWindow::GameWindow() {
        sceneManager = new SceneManager(this);
    }

    GameWindow::~GameWindow() {
        delete sceneManager;
    }

    void GameWindow::onResize(const Size& size) {
        getCurrentScene()->onResize(size);
    }

    void GameWindow::onRender(const float deltaTime) {
        getCurrentScene()->onRender(deltaTime);
    }

    void GameWindow::onDestroy() {
        sceneManager->destroyAll();
    }

    void GameWindow::onShow() {
        getCurrentScene()->onShow();
    }

    void GameWindow::onHide() {
        getCurrentScene()->onHide();
    }

    void GameWindow::onMouseEnter() {
        getCurrentScene()->onMouseEnter();
    }

    void GameWindow::onMouseLeave() {
        getCurrentScene()->onMouseLeave();
    }

    void GameWindow::onMouseButtonDown(const MouseButton button, const Point2i& position) {
        getCurrentScene()->onMouseButtonDown(button, position);
    }

    void GameWindow::onMouseButtonUp(const MouseButton button, const Point2i& position) {
        getCurrentScene()->onMouseButtonUp(button, position);
    }

    void GameWindow::onMouseMove(const Point2i& position) {
        getCurrentScene()->onMouseMove(position);
    }

    void GameWindow::onKeyDown(const int keyCode, const char keyChar) {
        if (keyChar == 'f')
            toggleFullscreen();

        getCurrentScene()->onKeyDown(keyCode, keyChar);
    }

    void GameWindow::onKeyUp(const int keyCode, const char keyChar) {
        getCurrentScene()->onKeyUp(keyCode, keyChar);
    }
}
