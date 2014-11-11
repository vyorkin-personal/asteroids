#pragma once

#include "Base.hpp"

struct Momentum: public Component {
    Momentum(const Vector2f& velocity, const float angularVelocity, const float& damping):
	velocity{velocity}, angularVelocity{angularVelocity}, damping{damping} {}

    void update(const float rotation, const float delta);

    Vector2f velocity;
    float angularVelocity;
    float damping;
};
