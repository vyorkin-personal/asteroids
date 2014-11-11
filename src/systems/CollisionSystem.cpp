#include "systems/CollisionSystem.hpp"

void CollisionSystem::initialize() {
	watchComponents<Position, Collidable>();
}

void CollisionSystem::processEntity(Entity* entity) {
    auto position = entity->getComponent<Position>();
    auto collidable = entity->getComponent<Collidable>();
    
    // ... handle collisions ...
}
