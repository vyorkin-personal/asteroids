#pragma once 

#include <System.hpp>

#include "components/Position.hpp"
#include "components/Momentum.hpp"

class MovementSystem: public gfs::System {
    public:
	void initialize() {
	    watchComponents<Position, Momentum>();
	}

	void processEntity(gfs::Entity* entity, const float delta) {
	    auto position = entity->getComponent<Position>();
	    auto momentum = entity->getComponent<Momentum>();

	    // ... handle movement somehow ...
	}
};
