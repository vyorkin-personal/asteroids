#include "systems/DestructionSystem.hpp"

DestructionSystem::DestructionSystem(EntityFactory* entityFactory):
	entityFactory{entityFactory} {}

void DestructionSystem::initialize() {
	getEventBus()->subscribe<CollisionEvent>(this, &DestructionSystem::onCollision);
}

void DestructionSystem::onCollision(const CollisionEvent& e) {
	// TODO: Its totally wrong

	const auto vector = e.entity1->getComponent<Position>()->vector;
	const auto mass = e.entity1->getComponent<Body>()->mass;
	const auto radius = e.entity1->getComponent<Geometry>()->radius;

	e.entity1->destroy();
	e.entity2->destroy();

	if (mass > 40000.0f) {
		entityFactory->createAsteroid(vector, radius / 1.7f);
		entityFactory->createAsteroid(vector, radius / 2.3f);
	}

	getEventBus()->emit(ExplosionEvent(vector, ExplosionKind::Small));
}
