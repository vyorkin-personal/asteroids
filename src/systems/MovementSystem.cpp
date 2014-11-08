#include "systems/MovementSystem.hpp"

void MovementSystem::processEntity(Entity* entity) {
    auto position = entity->getComponent<Position>();
    auto momentum = entity->getComponent<Momentum>();

    // ... handle movement somehow ...
}

