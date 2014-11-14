#pragma once

#include "Base.hpp"
#include "common/Dumping.hpp"

struct Velocity {
    Velocity(const Vector2f& linear, const float angular);

    Vector2f linear;
    float angular;

    const static Velocity Zero;

    void dump(const Dumping& dumping);
};
