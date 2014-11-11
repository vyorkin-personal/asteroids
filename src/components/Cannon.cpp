#include "components/Cannon.hpp"

Cannon::Cannon(const float delayTime):
	delayTime{delayTime}, elapsedTime{0.0f} {}

void Cannon::update(const float delta) {
	elapsedTime += delta;
	ready = (elapsedTime > delayTime);

	if (isFiring())
		elapsedTime = 0.0f;
}
