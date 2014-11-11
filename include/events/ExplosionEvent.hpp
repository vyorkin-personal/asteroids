#pragma once

#include "Base.hpp"

enum ExplosionKind { Small, Huge };

struct ExplosionEvent: public Event {
    ExplosionEvent(const Vector2f& position, const ExplosionKind& kind):
        position{position}, kind{kind} {}

    Vector2f position;
    ExplosionKind kind;
};
