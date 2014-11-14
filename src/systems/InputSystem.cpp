#include "systems/InputSystem.hpp"

void InputSystem::initialize() {
	watchTags({"player"});

	auto events = getEventBus();
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
	auto position = entity->getComponent<Position>();
	auto momentum = entity->getComponent<Momentum>();
	auto cannon = entity->getComponent<Cannon>();

	const auto dt = getDelta();

	cannon->trigger = keys[Keys::Fire];

	if (specialKeys[Keys::Forward])
		momentum->move(position->angle, dt);
	else if (specialKeys[Keys::Backward])
		momentum->move(position->angle, -dt);

	if (specialKeys[Keys::Right])
		momentum->rotate(-dt);
	else if (specialKeys[Keys::Left])
		momentum->rotate(dt);
}
