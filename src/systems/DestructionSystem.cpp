#include "systems/DestructionSystem.hpp"

DestructionSystem::DestructionSystem(EntityFactory* entityFactory):
	entityFactory{entityFactory} {}

void DestructionSystem::initialize() {
	getEventBus()->subscribe<CollisionEvent>(this, &DestructionSystem::onCollision);
}

void DestructionSystem::onCollision(const CollisionEvent& e) {
	// TODO: Its totally wrong, it should be a point between
	const auto vector = e.entity1->getComponent<Position>()->vector;
	const auto mass = e.entity1->getComponent<Body>()->mass;
	const auto radius = e.entity1->getComponent<Geometry>()->radius;

	e.entity1->destroy();
	e.entity2->destroy();

	if (mass > 40000.0f) {
		entityFactory->createAsteroid(vector, mass / 3.2f, radius / 2.4f);
		entityFactory->createAsteroid(vector, mass / 2.8f, radius / 2.2f);
	}

	getEventBus()->emit(ExplosionEvent(vector, ExplosionKind::Small));
}
