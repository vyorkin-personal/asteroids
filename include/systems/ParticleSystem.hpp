#pragma once

#include <System.hpp>
#include "components/Particle.hpp"

class ParticleSystem: public gfs::System {
    public:
	void initialize() {
	    watchComponents<Particle>();
	}
    
	void processEntity(gfs::Entity* entity, const double delta) {
	    auto particle = entity->getComponent<Particle>();

	    // ...
	}
};
