#pragma once

#include "Base.hpp"

struct Particle: public Component {
    Particle(const Color4f& color, float lifetime = 1.0F):
	color{color}, lifetime{life}, age{0.0f} {}

    float Color4f color;
    float age;
    float lifetime;
};
