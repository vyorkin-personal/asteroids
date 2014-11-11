#include "components/Momentum.hpp"

void Momentum::update(const float rotation, const float delta) {
	if (damping <= 0.0F) return;

	velocity.x += abs(cos(rotation) * damping * delta);
	velocity.y += abs(sin(rotation) * damping * delta);
}
