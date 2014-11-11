#pragma once

#include "Base.hpp"

struct Cannon: public Component {
    Cannon(const float cooldownTime):
	cooldownTime{cooldownTime} {}

    void cooldown(const float delta) {
	cooldownTime += delta;
    }

    float cooldownTime;
    bool on;
};
