#pragma once

#include "Base.hpp"

struct Cannon: public Component {
    Cannon(const float delayTime);

    void update(const float delta);
    bool isFiring() const {
	return ready && trigger;
    }

    float delayTime;
    float elapsedTime;

    bool ready;
    bool trigger;
};
