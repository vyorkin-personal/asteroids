#include "systems/CollisionSystem.hpp"

void CollisionSystem::initialize() {
	watchComponents<Position, Geometry>();
}

void CollisionSystem::processEntity(Entity* entity) {
    auto position = entity->getComponent<Position>();
    auto geometry = entity->getComponent<Geometry>();
    
    // ... handle collisions ...
}
