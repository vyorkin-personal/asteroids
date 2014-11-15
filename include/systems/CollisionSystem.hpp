#pragma once

#include "Base.hpp"
#include "components/Geometry.hpp"
#include "components/Position.hpp"
#include "events/CollisionEvent.hpp"

class CollisionSystem: public System {
    public:
	virtual void process() override;

    private:
	bool hasCollision(Entity* entity1, Entity* entity2);

	GroupManager* groupManager;
};
