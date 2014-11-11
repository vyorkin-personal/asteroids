#pragma once

#include "Base.hpp"

struct Momentum: public Component {
    Momentum(const Vector2f& velocity, const float angularVelocity,
	const float linearDumping, const float angularDumping = 1.0f);

    void updateLinear(const float rotation, const float delta);
    void updateAngular(const float delta);

    void dump() {
	velocity *= linearDumping;
	angularVelocity *= angularDumping;
    }

    Vector2f velocity;
    float angularVelocity;

    float linearDumping;
    float angularDumping;
};
