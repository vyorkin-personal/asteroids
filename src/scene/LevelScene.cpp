#include "scene/LevelScene.hpp"

LevelScene::LevelScene(const Rectanglef& worldBounds):
    worldBounds{worldBounds} {

    world = new World();
    entityFactory = new EntityFactory(world, worldBounds);
}

LevelScene::~LevelScene() {
    delete entityFactory;
    delete world;
}

void LevelScene::onInitialize() {
    auto systemManager = world->getSystemManager();

    systemManager->add(new MovementSystem(worldBounds));
    systemManager->add(new RenderingSystem());
    systemManager->add(new InputSystem());
    systemManager->add(new CollisionSystem(world->getGroupManager()));
    systemManager->add(new ExplosionSystem());
    systemManager->add(new CannonSystem(entityFactory));

    prepare();
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

void LevelScene::onResize(const Size2i& size) {
    glViewport(0, 0, size.x, size.y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    setOrtho((float)size.x / (float)size.y);
}

void LevelScene::setOrtho(const float aspectRatio) {
    const auto volume = getViewVolume(aspectRatio);

    glOrtho(volume.leftBottom.x, volume.rightTop.x,
        volume.leftBottom.y, volume.rightTop.y, -1.0, 1.0);
}

Rectanglef LevelScene::getViewVolume(const float aspectRatio) const {
    auto viewVolume = Rectanglef(worldBounds);
    if (aspectRatio >= 1.0f) {
        viewVolume.leftBottom.x *= aspectRatio;
        viewVolume.rightTop.x *= aspectRatio;
    } else {
        viewVolume.leftBottom.y /= aspectRatio;
        viewVolume.rightTop.y /= aspectRatio;
    }
    return viewVolume;
}

void LevelScene::prepare() {
    entityFactory->createPlayer();
    for (int i = 0; i <= 40; i++)
        entityFactory->createAsteriod();
}

void LevelScene::reset() {
    world->reset();
    prepare();
}

void LevelScene::onKeyDown(const int keyCode, const char keyChar) {
    world->getEventBus()->emit(KeyDownEvent(keyCode, keyChar));

    switch (keyChar) {
        case 'r':
            reset();
            break;
        case 27:
            exit(0);
            break;
    }
}

void LevelScene::onKeyUp(const int keyCode, const char keyChar) {
    world->getEventBus()->emit(KeyUpEvent(keyCode, keyChar));
}
