#include "systems/CannonSystem.hpp"

void CannonSystem::initialize() {
	watchComponents<Cannon, Position>();
}

void CannonSystem::processEntity(Entity* entity) {
}
