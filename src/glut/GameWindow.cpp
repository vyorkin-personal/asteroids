#include "glut/GameWindow.hpp"

namespace glut {
    GameWindow::GameWindow(SceneManager* sceneManager):
	sceneManager{sceneManager} {}

    void GameWindow::onRender() {
        sceneManager->renderScene();
    }
}
