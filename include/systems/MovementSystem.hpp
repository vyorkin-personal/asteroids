#pragma once 

#include "Base.hpp"
#include "components/Position.hpp"
#include "components/Momentum.hpp"

class MovementSystem: public System {
    public:
	MovementSystem(const Size& size);

	virtual void initialize() override {
	    watchComponents<Position, Momentum>();
	}

	virtual void processEntity(Entity* entity) override;

    private:
	Size size;
};
