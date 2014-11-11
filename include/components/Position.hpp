#pragma once

#include "Base.hpp"

enum OffLimitBehavior { DESTROY, LOOP };

struct Position: public Component {
    Position(const Vector2f& vector, const float rotation,
	const OffLimitBehavior offLimitBehavior = OffLimitBehavior::LOOP):
	vector{vector}, rotation{rotation},
	offLimitBehavior{offLimitBehavior} {}

    void move(const Vector2f& velocity) {
	vector += velocity;
    }
    
    void rotate(const float speed) {
	rotation += speed;
    }

    Vector2f vector;
    float rotation;
    OffLimitBehavior offLimitBehavior;
};
