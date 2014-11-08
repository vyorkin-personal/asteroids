#pragma once

#include "Base.hpp"

struct Position: public Component {
    Position(const Vector2f& vector, const float rotation):
	vector{vector}, rotation{rotation} {}

    void move(const Vector2f& velocity) {
	vector += velocity;
    }
    
    void rotate(const float speed) {
	rotation += speed;
    }

    Vector2f vector;
    float rotation;
};
