#include "scene/SceneManager.hpp"

SceneManager::SceneManager(glut::Window* window):
    window{window}, current{nullptr} {}

SceneManager::~SceneManager() {
    destroyAll();
}

void SceneManager::destroyAll() {
    for (auto& scene: scenes) {
        scenes.erase(scene);
        delete scene;
    }
    scenes.clear();
}

Scene* SceneManager::add(Scene* scene) {
    scenes.insert(scene);

    scene->onInitialize();
    scene->onResize(window->getSize());

    return scene;
}

void SceneManager::setCurrent(Scene* scene) {
    if (current != nullptr) {
        current->state = SceneState::Paused;
        current->onPause();
    }

    current = scene;
    current->state = SceneState::Playing;

    current->onPlay();
}
