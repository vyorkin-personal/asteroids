#include "systems/DestructionSystem.hpp"

DestructionSystem::DestructionSystem(EntityFactory* entityFactory):
	entityFactory{entityFactory} {}

void DestructionSystem::initialize() {
	getEventBus()->subscribe<CollisionEvent>(this, &DestructionSystem::onCollision);
}

void DestructionSystem::onCollision(const CollisionEvent& e) {
	// TODO: Its totally wrong, it should be a point between
	const auto vector = e.entity1->getComponent<Position>()->vector;

	e.entity1->destroy();
	e.entity2->destroy();

	getEventBus()->emit(ExplosionEvent(vector, ExplosionKind::Small));
}
