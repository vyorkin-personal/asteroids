#include "systems/InputSystem.hpp"

void InputSystem::initialize() {
	auto events = getEventBus();

	watchTags({"player"});

	events->subscribe<KeyDownEvent>(this, &InputSystem::onKeyDown);
	events->subscribe<KeyUpEvent>(this, &InputSystem::onKeyUp);
}

void InputSystem::onKeyDown(const KeyDownEvent& e) {
	specialKeys[e.keyCode] = true;
	keys[(int)e.keyChar] = true;
}

void InputSystem::onKeyUp(const KeyUpEvent& e) {
	specialKeys[e.keyCode] = false;
	keys[(int)e.keyChar] = false;
}

void InputSystem::processEntity(Entity* entity) {
	for (auto& entity: getEntities()) {
		auto position = entity->getComponent<Position>();
		auto momentum = entity->getComponent<Momentum>();

		auto rotation = position->rotation;
		auto dt = getDelta();

		if (specialKeys[Keys::Forward])
			momentum->updateLinear(rotation, dt);
		else if (specialKeys[Keys::Backward])
			momentum->updateLinear(rotation, -dt);

		if (specialKeys[Keys::Right])
			momentum->updateAngular(-dt);
		else if (specialKeys[Keys::Left])
			momentum->updateAngular(dt);

		if (specialKeys[Keys::Fire])
			entity->getComponent<Cannon>()->trigger = true;
	}
}
