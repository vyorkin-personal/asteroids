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

    systemManager->add(new MovementSystem());
    systemManager->add(new RenderingSystem());
    systemManager->add(new InputSystem());
    systemManager->add(new CollisionSystem());
    systemManager->add(new ExplosionSystem());
    systemManager->add(new CannonSystem(entityFactory));

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
    aspectRatio = (float)size.x / (float)size.y;

    glViewport(0, 0, size.x, size.y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, size.x, 0.0, size.y);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void LevelScene::reset() {
    entityFactory->createPlayer();
    /* for (int i = 0; i <= 10; i++) */
    /*     entityFactory->createAsteriod(); */
}

void LevelScene::onKeyDown(const int keyCode, const char keyChar) {
    world->getEventBus()->emit(KeyDownEvent(keyCode, keyChar));

    switch (keyChar) {
        case 27:
            exit(0);
            break;
    }
}

void LevelScene::onKeyUp(const int keyCode, const char keyChar) {
    world->getEventBus()->emit(KeyUpEvent(keyCode, keyChar));
}
