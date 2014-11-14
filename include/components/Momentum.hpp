#pragma once

#include "Base.hpp"

#include "common/Velocity.hpp"
#include "common/Dumping.hpp"

struct Momentum: public Component {
    Momentum(const Velocity& velocity, const Dumping& dumping);

    void move(const float angle, const float deltaTime);
    void rotate(const float deltaTime);
    void dump();

    Velocity velocity;
    Dumping dumping;
};
