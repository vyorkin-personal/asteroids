#pragma once

#include "Base.hpp"
#include "components/Particle.hpp"

class ParticleSystem: public System {
    public:
	void initialize() {
	    watchComponents<Particle>();
	}
    
	void processEntity(Entity* entity)
};
