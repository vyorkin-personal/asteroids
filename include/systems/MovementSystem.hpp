#pragma once 

#include "Base.hpp"
#include "components/Position.hpp"
#include "components/Momentum.hpp"
#include "components/Body.hpp"
#include "components/Geometry.hpp"

class MovementSystem: public System {
    public:
	virtual void initialize() override;
	virtual void processEntity(Entity* entity) override;

	void handleScreenBounds(Entity* entity,
	    Position* position, const float radius);

    private:
	Size size;
};
