#pragma once

#include "Base.hpp"

enum CollisionKind {
    AsteriodAsteroid,
    AsteroidProjectile,
    AsteroidPlayer
};

struct CollisionEvent: public Event {
    CollisionEvent(Entity* entity1, Entity* entity2, const CollisionKind kind):
        entity1{entity1}, entity2{entity2}, kind{kind} {}

    Entity* entity1;
    Entity* entity2;

    CollisionKind kind;
};
