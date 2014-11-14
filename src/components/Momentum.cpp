#include "components/Momentum.hpp"

Momentum::Momentum(const Velocity& velocity, const Dumping& dumping):
	velocity{velocity}, dumping{dumping} {}

void Momentum::move(const float angle, const float deltaTime) {
	const auto a = angle * M_PI / 180.0f + M_PI / 2.0f;
	velocity.linear += Vector2f(cos(a), sin(a)) * deltaTime;
}

void Momentum::rotate(const float deltaTime) {
	velocity.angular += deltaTime;
}

void Momentum::dump() {
	velocity.dump(dumping);
}
