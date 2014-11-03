#pragma once

#include <Component.hpp>
#include "math/Vector2f.hpp"

struct Position: public gfs::Component {
    Position(const Vector2f& vec, const float rot):
	vector{vec}, rotation{rot} {}

    void move(const Vector2f& velocity, const float delta) {
	vector.x += velocity.x * delta;
	vector.y += velocity.y * delta;
    }
    
    void rotate(const float speed, const float delta) {
	rotation += speed * delta;
    }

    Vector2f vector;
    float rotation;
};
