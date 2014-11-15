#include "systems/ExplosionSystem.hpp"

ExplosionSystem::ExplosionSystem(EntityFactory* entityFactory):
	entityFactory{entityFactory} {}

void ExplosionSystem::initialize() {
	getEventBus()->subscribe<ExplosionEvent>(this, &ExplosionSystem::onExplosion);
}

void ExplosionSystem::onExplosion(const ExplosionEvent& e) {
	const int numParticles = e.kind == ExplosionKind::Small ? 100 : 500;
	entityFactory->createExplosion(e.vector, numParticles);
}
