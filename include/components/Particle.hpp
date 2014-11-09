#pragma once

#include "Base.hpp"

struct Particle: public Component {
    Particle(const Color4f& color, const float lifetime = 1.0F):
	color{color}, age{0.0f}, lifetime{lifetime} {}

    Color4f color;
    float age;
    float lifetime;
};
