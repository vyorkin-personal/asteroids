#include "systems/MovementSystem.hpp"

MovementSystem::MovementSystem(const Size& size): size{size} {}

void MovementSystem::processEntity(Entity* entity) {
    auto position = entity->getComponent<Position>();
    auto momentum = entity->getComponent<Momentum>();

    position->move(momentum->velocity);
    position->rotate(momentum->angularVelocity);
}

