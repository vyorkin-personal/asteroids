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

	if (rotation < 0.0f)
	    rotation += 360.0f;
	else if (rotation > 360.0f)
	    rotation -= 360.0f;
    }

    Vector2f vector;
    float rotation;
    OffLimitBehavior offLimitBehavior;
};
