#pragma once 

#include "Base.hpp"
#include "components/Position.hpp"
#include "components/Momentum.hpp"

class MovementSystem: public System {
    public:
	virtual void initialize() override {
	    watchComponents<Position, Momentum>();
	}

	virtual void processEntity(Entity* entity) override;
};
