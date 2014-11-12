#include "systems/MovementSystem.hpp"

void MovementSystem::initialize() {
    watchComponents<Position, Momentum, Body>();
}

void MovementSystem::processEntity(Entity* entity) {
    auto position = entity->getComponent<Position>();
    auto momentum = entity->getComponent<Momentum>();
    auto geometry = entity->getComponent<Geometry>();
    auto body = entity->getComponent<Body>();

    const float dt = getDelta();

    position->move(momentum->velocity * dt / body->mass);
    position->rotate(momentum->angularVelocity * dt * 25.0 / body->mass);
    momentum->dump();

    handleScreenBounds(entity, position, geometry->radius); 
}


void MovementSystem::handleScreenBounds(Entity* entity,
    Position* position, const float radius) {

    if (position->offLimitBehavior != OffLimitBehavior::LOOP) return;

    if (position->vector.x > 10.0f)
        position->vector.x = -10.0f;
    else if (position->vector.x < -10.0f)
        position->vector.x = 10.0f;
    
    if (position->vector.y > 10.0f)
        position->vector.y = -10.0f;
    else if (position->vector.y < -10.0f)
        position->vector.y = 10.0f;
}
