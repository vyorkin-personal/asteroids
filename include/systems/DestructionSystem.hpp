#pragma once

#include "Base.hpp"
#include "components/Position.hpp"
#include "components/appearance/PlayerAppearance.hpp"
#include "factories/EntityFactory.hpp"
#include "events/CollisionEvent.hpp"
#include "events/ExplosionEvent.hpp"

class DestructionSystem: public System {
    public:
	DestructionSystem(EntityFactory* entityFactory);

	virtual void initialize() override;

	void onCollision(const CollisionEvent& event);

    private:
	void handlePlayerCollision(Entity* player);
	void handleProjectileCollision(Entity* asteroid, Entity* projectile);

	EntityFactory* entityFactory;
};

