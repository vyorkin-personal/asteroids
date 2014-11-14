#pragma once

#include "Base.hpp"
#include "common/Velocity.hpp"

enum OutOfBoundsAction { DESTROY, LOOP };

struct Position: public Component {
    Position(const Vector2f& vector = Vector2f::Zero, const float angle = 0.0f,
	const OutOfBoundsAction outOfBoundsAction = OutOfBoundsAction::LOOP);

    void update(const Velocity& velocity, const float mass, const float deltaTime);

    Vector2f vector;
    float angle;
    OutOfBoundsAction outOfBoundsAction;

    private:
	void adjustAngle();
};
