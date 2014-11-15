#include "scene/Scene.hpp"

Scene::Scene(SceneManager* sceneManager):
	sceneManager{sceneManager},
	state{SceneState::Paused} {}
