#include "systems/CannonSystem.hpp"

CannonSystem::CannonSystem(EntityFactory* entityFactory):
	entityFactory{entityFactory} {}

void CannonSystem::initialize() {
	watchComponents<Cannon>();
}

void CannonSystem::processEntity(Entity* entity) {
	auto cannon = entity->getComponent<Cannon>();
	const auto dt = getDelta();

	/*
	cannon->update(dt);

	if (cannon->isFiring()) {
		auto position = entity->getComponent<Position>();
		auto momentum = entity->getComponent<Momentum>();

		entityFactory->createProjectile();
	}
	*/
}
