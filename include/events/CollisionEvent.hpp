#pragma once

#include "Base.hpp"

enum class CollisionKind { Asteroid, Projectile, Player };

struct CollisionEvent: public Event {
    CollisionEvent(Entity* asteroid, Entity* collider, const CollisionKind kind):
        asteroid{asteroid}, collider{collider}, kind{kind} {}

    Entity* asteroid;
    Entity* collider;

    CollisionKind kind;
};
