#pragma once

#include "Base.hpp"

struct Momentum: public Component {
    Momentum(const Vector2f& velocity, const float angularVelocity, const float& damping):
	velocity{velocity}, angularVelocity{angularVelocity}, damping{damping} {}

    void damp(const float rotation, const float delta) {
	if (damping <= 0.0F) return;

	const auto xd = abs(cos(rotation) * damping * delta);
	const auto yd = abs(sin(rotation) * damping * delta);

	velocity.x += getDampingValue(velocity.x, xd);
	velocity.y += getDampingValue(velocity.y, yd);
    }

    Vector2f velocity;
    float angularVelocity;
    float damping;

    private:
	float getDampingValue(const float coord, const float val) {
	    if (coord > val)
		return -val;
	    else if (coord < -val)
		return val;
	    else
		return -coord;
	}
};
