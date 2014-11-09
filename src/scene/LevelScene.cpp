#include "scene/LevelScene.hpp"

LevelScene::LevelScene() {
    world = new World();
    entityFactory = new EntityFactory(world->getEntityManager());
}

LevelScene::~LevelScene() {
    delete entityFactory;
    delete world;
}

void LevelScene::onInitialize() {
    auto systemManager = world->getSystemManager();

    systemManager->add(new MovementSystem());
    systemManager->add(new RenderingSystem());
    systemManager->add(new InputSystem());

    reset();
}

void LevelScene::onPlay() {
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glPointSize(4.0f);
}

void LevelScene::onPause() {
}

void LevelScene::onRender() {
    world->process();

    glBegin(GL_POINTS);
    glVertex2i(200, 200);
    glEnd();
}

void LevelScene::onResize(const Size& size) {
    glViewport(0, 0, size.x, size.y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, size.x, 0.0, size.y);
}

void LevelScene::reset() {
    entityFactory->createPlayer();
    for (int i = 0; i <= 10; i++)
        entityFactory->createAsteriod();
}

void LevelScene::onKey(const int keyCode, const char keyChar) {
    switch (keyChar) {
        case 27:
            exit(0);
            break;
    }
}
