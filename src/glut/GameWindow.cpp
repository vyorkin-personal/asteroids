#include "glut/GameWindow.hpp"

namespace glut {
    GameWindow::GameWindow() {
        sceneManager = new SceneManager();
    }

    GameWindow::~GameWindow() {
        delete sceneManager;
    }

    void GameWindow::onInitialize() {
        sceneManager->initialize();
    }

    void GameWindow::onResize(const Size& size) {
        getCurrentScene()->onResize(size);
    }

    void GameWindow::onRender() {
        getCurrentScene()->onRender();
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

    void GameWindow::onMouseButtonDown(const MouseButton button, const int x, const int y) {
        getCurrentScene()->onMouseButtonDown(button, x, y);
    }

    void GameWindow::onMouseButtonUp(const MouseButton button, const int x, const int y) {
        getCurrentScene()->onMouseButtonUp(button, x, y);
    }

    void GameWindow::onMouseMove(const int x, const int y) {
        getCurrentScene()->onMouseMove(x, y);
    }

    void GameWindow::onMouseWheel(const int wheelNumber, const int direction, const int x, const int y) {
        getCurrentScene()->onMouseWheel(wheelNumber, direction, x, y);
    }

    void GameWindow::onKeyDown(const int keyCode, const char keyChar) {
        getCurrentScene()->onKeyDown(keyCode, keyChar);
    }

    void GameWindow::onKeyUp(const int keyCode, const char keyChar) {
        getCurrentScene()->onKeyUp(keyCode, keyChar);
    }

    void GameWindow::onJoystick(const unsigned int button, int x, int y, int z) {
        getCurrentScene()->onJoystick(button, x, y);
    }
}
