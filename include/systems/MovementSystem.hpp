#pragma once 

#include "Base.hpp"
#include "components/Position.hpp"
#include "components/Momentum.hpp"

class MovementSystem: public System {
    public:
	void initialize() {
	    watchComponents<Position, Momentum>();
	}

	void processEntity(Entity* entity);
};
