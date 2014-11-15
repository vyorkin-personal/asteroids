#pragma once

#include "Base.hpp"

enum ExplosionKind { Small, Huge };

struct ExplosionEvent: public Event {
    ExplosionEvent(const Vector2f& vector, const ExplosionKind& kind):
        vector{vector}, kind{kind} {}

    Vector2f vector;
    ExplosionKind kind;
};
