#pragma once

#include "Base.hpp"
#include "components/Collidable.hpp"
#include "components/Position.hpp"

class CollisionSystem: public System {
    public:
	virtual void initialize() override {
	    watchComponents<Position, Collidable>();
	}

	virtual void processEntity(Entity* entity) override;
};
