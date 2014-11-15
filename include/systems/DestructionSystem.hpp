#pragma once

#include "Base.hpp"
#include "components/Position.hpp"
#include "factories/EntityFactory.hpp"
#include "events/CollisionEvent.hpp"
#include "events/ExplosionEvent.hpp"

class DestructionSystem: public System {
    public:
	DestructionSystem(EntityFactory* entityFactory);

	virtual void initialize() override;

	void onCollision(const CollisionEvent& event);

    private:
	EntityFactory* entityFactory;
};

