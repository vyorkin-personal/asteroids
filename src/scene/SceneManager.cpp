#include "scene/SceneManager.hpp"

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
