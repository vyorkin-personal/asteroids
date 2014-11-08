#pragma once

#include "Base.hpp"
#include "components/Collidable.hpp"
#include "components/Position.hpp"

class CollisionSystem: public System {
    public:
	void initialize() {
	    watchComponents<Position, Collidable>();
	}

	void processEntity(Entity* entity);
};
