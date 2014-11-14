#include "components/Position.hpp"

Position::Position(const Vector2f& vector, const float angle, const OutOfBoundsAction outOfBoundsAction):
	vector{vector}, angle{angle}, outOfBoundsAction{outOfBoundsAction} {}

void Position::update(const Velocity& velocity, const float mass, const float deltaTime) {
	vector += velocity.linear * deltaTime / mass;
	angle += velocity.angular * deltaTime / (mass / 8.0f);

	adjustAngle();
}

void Position::adjustAngle() {
	if (angle < 0.0f)
		angle += 360.0f;
	else if (angle > 360.0f)
		angle -= 360.0f;
}
