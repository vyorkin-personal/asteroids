#include "systems/ExplosionSystem.hpp"

void ExplosionSystem::initialize() {
	getEventBus()->subscribe<ExplosionEvent>(this, &ExplosionSystem::onExplosion);
}

void ExplosionSystem::onExplosion(const ExplosionEvent& e) {
}
