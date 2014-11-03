#pragma once

#include <System.hpp>

#include "components/Collidable.hpp"
#include "components/Position.hpp"

class CollisionSystem: public gfs::System {
    public:
	void initialize() {
	    watchComponents<Position, Collidable>();
	}

	void processEntity(gfs::Entity* entity, const float delta) {
	    auto position = entity->getComponent<Position>();
	    auto collidable = entity->getComponent<Collidable>();
	    
	    // ... handle collisions ...
	}
};
