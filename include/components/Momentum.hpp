#pragma once

#include <cmath>
#include <Component.hpp>

#include "math/Vector2f.hpp"

struct Momentum: public gfs::Component {
    Momentum(const Vector2f& vel, const float angVel, const float& damp):
	velocity{vel}, angularVelocity{angVel}, damping{damp} {}

    void damp(const float rotation, const float delta) {
	if (damping <= 0.0F) return;

	auto xd = abs(cos(rotation) * damping * delta);
	auto yd = abs(sin(rotation) * damping * delta);

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
