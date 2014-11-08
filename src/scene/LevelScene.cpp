#include "scenes/LevelScene.hpp"

LevelScene::LevelScene(World* world): world{world} {}

void LevelScene::onInitialize() {
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

void LevelScene::onIdle() {
    world->process();
}

void LevelScene::onRender() {
}

void LevelScene::onResize(const Point2i& size) {
    glViewport(0, 0, size.width, size.height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, size.width, 0.0, size.height);
}
