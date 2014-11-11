#pragma once

#include "Base.hpp"
#include "components/Collidable.hpp"
#include "components/Position.hpp"
#include "events/ExplosionEvent.hpp"

class CollisionSystem: public System {
    public:
	virtual void initialize() override;
	virtual void processEntity(Entity* entity) override;
};
