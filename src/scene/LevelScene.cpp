#include "scene/LevelScene.hpp"

LevelScene::LevelScene(const Size& size): size{size} {
    world = new World();
    entityFactory = new EntityFactory(world, size);
}

LevelScene::~LevelScene() {
    delete entityFactory;
    delete world;
}

void LevelScene::onInitialize() {
    auto systemManager = world->getSystemManager();

    systemManager->add(new MovementSystem(size));
    systemManager->add(new RenderingSystem());
    systemManager->add(new InputSystem());
    systemManager->add(new CannonSystem());
    systemManager->add(new CollisionSystem());
    systemManager->add(new ExplosionSystem());

    reset();
}

void LevelScene::onPlay() {
    glEnable(GL_LINE_SMOOTH);               
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

    glPointSize(4.0f);
}

void LevelScene::onPause() {
}

void LevelScene::onRender(const float deltaTime) {
    world->setDelta(deltaTime);
    world->process();
}

void LevelScene::onResize(const Size& size) {
    glViewport(0, 0, size.x, size.y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, size.x, 0.0, size.y);
}

void LevelScene::reset() {
    entityFactory->createPlayer();
    /* for (int i = 0; i <= 10; i++) */
    /*     entityFactory->createAsteriod(); */
}

void LevelScene::onKey(const int keyCode, const char keyChar) {
    world->getEventBus()->emit(KeyEvent(keyCode, keyChar));

    switch (keyChar) {
        case 27:
            exit(0);
            break;
    }
}
