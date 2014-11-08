#include "systems/CollisionSystem.hpp"

void CollisionSystem::processEntity(Entity* entity) {
    auto position = entity->getComponent<Position>();
    auto collidable = entity->getComponent<Collidable>();
    
    // ... handle collisions ...
}
