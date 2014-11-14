#include "systems/MovementSystem.hpp"

MovementSystem::MovementSystem(const Rectanglef& worldBounds):
    worldBounds{worldBounds} {}

void MovementSystem::initialize() {
    watchComponents<Position, Momentum, Geometry, Body>();
}

void MovementSystem::processEntity(Entity* entity) {
    auto position = entity->getComponent<Position>();
    auto momentum = entity->getComponent<Momentum>();
    auto geometry = entity->getComponent<Geometry>();
    auto body = entity->getComponent<Body>();

    position->update(momentum->velocity, body->mass, getDelta());
    momentum->dump();

    handleScreenBounds(entity, position, geometry->radius); 
}

void MovementSystem::handleScreenBounds(Entity* entity,
    Position* position, const float radius) {

    if (position->outOfBoundsAction == OutOfBoundsAction::LOOP) {

        if (position->vector.x > worldBounds.rightTop.x)
            position->vector.x = worldBounds.leftBottom.x;
        else if (position->vector.x < worldBounds.leftBottom.x)
            position->vector.x = worldBounds.rightTop.x;
        
        if (position->vector.y > worldBounds.rightTop.y)
            position->vector.y = worldBounds.leftBottom.y;
        else if (position->vector.y < worldBounds.leftBottom.y)
            position->vector.y = worldBounds.rightTop.y;

    } else if (position->outOfBoundsAction == OutOfBoundsAction::DESTROY) {

        if (position->vector.x > worldBounds.rightTop.x ||
            position->vector.x < worldBounds.leftBottom.x ||
            position->vector.y > worldBounds.rightTop.y ||
            position->vector.y < worldBounds.leftBottom.y) {

            entity->destroy();
        }
    }
}
