#pragma once

#include "Base.hpp"
#include "components/Geometry.hpp"
#include "components/Position.hpp"
#include "events/ExplosionEvent.hpp"

class CollisionSystem: public System {
    public:
	CollisionSystem(GroupManager* groupManager);

	virtual void process() override;

    private:
	GroupManager* groupManager;
};
