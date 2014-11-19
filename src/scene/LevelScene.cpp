#include "scene/LevelScene.hpp"

LevelScene::LevelScene(SceneManager* sceneManager, EventBus* eventBus, Level* level):
    Scene(sceneManager), eventBus{eventBus}, level{level} {}

LevelScene::~LevelScene() {
    delete level;
}

void LevelScene::onInitialize() {
    level->start();
}

void LevelScene::onPlay() {
    glEnable(GL_LINE_SMOOTH);               
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glPointSize(4.0f);
}

void LevelScene::onPause() {
}

void LevelScene::onRender(const float deltaTime) {
    level->update(deltaTime);
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
    auto viewVolume = Rectanglef(level->getWorldBounds());
    if (aspectRatio >= 1.0f) {
        viewVolume.leftBottom.x *= aspectRatio;
        viewVolume.rightTop.x *= aspectRatio;
    } else {
        viewVolume.leftBottom.y /= aspectRatio;
        viewVolume.rightTop.y /= aspectRatio;
    }
    return viewVolume;
}

void LevelScene::onKeyDown(const int keyCode, const char keyChar) {
    eventBus->emit(KeyDownEvent(keyCode, keyChar));

    switch (keyChar) {
        case 'r':
            level->restart();
            break;
        case 27:
            exit(0);
            break;
    }
}

void LevelScene::onKeyUp(const int keyCode, const char keyChar) {
    eventBus->emit(KeyUpEvent(keyCode, keyChar));
}
