#include "common/Velocity.hpp"

Velocity::Velocity(const Vector2f& linear, const float angular):
	linear{linear}, angular{angular} {}

void Velocity::dump(const Dumping& dumping) {
	linear *= dumping.linear;
	angular *= dumping.angular;
}

const Velocity Velocity::Zero = Velocity(Vector2f::Zero, 0.0f);
