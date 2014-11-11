#pragma once

#include "Base.hpp"
#include "components/Particle.hpp"

class ParticleSystem: public System {
    public:
	virtual void initialize() override;
	virtual void processEntity(Entity* entity) override;
};
