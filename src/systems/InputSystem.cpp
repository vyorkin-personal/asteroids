#include "systems/InputSystem.hpp"

#define STEP 0.1f

void InputSystem::initialize() {
	watchTags({"player"});
	getEventBus()->subscribe<KeyEvent>(this, &InputSystem::onKey);
}

void InputSystem::onKey(const KeyEvent& e) {
	for (auto& entity: getEntities()) {

		auto position = entity->getComponent<Position>();
		auto momentum = entity->getComponent<Momentum>();

		auto rotation = position->rotation;

		auto dt = getDelta();

		if (e.keyCode == GLUT_KEY_UP)
			momentum->update(rotation, dt * STEP);
		else if (e.keyCode == GLUT_KEY_DOWN)
			momentum->update(rotation, dt * -STEP);
	}
}
