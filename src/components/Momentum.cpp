#include "components/Momentum.hpp"

Momentum::Momentum(const Vector2f& velocity, const float angularVelocity,
	const float linearDumping, const float angularDumping):
	velocity{velocity}, angularVelocity{angularVelocity},
	linearDumping{linearDumping}, angularDumping{angularDumping} {}

void Momentum::updateLinear(const float rotation, const float delta) {
	const float angle = rotation * M_PI / 180.0f + M_PI / 2.0f;

	velocity.x += cos(angle) * delta;
	velocity.y += sin(angle) * delta;
}

void Momentum::updateAngular(const float delta) {
	angularVelocity += delta;
}
