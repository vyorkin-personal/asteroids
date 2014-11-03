#pragma once

#include <Component.hpp>

struct Particle: public gfs::Component {
    Particle(float life = 1.0F):
	lifetime{life} {}

    float age;
    float lifetime;
};
