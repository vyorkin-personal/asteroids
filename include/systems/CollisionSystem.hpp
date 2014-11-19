#pragma once

#include "Base.hpp"
#include "components/Geometry.hpp"
#include "components/Position.hpp"
#include "components/Momentum.hpp"
#include "events/CollisionEvent.hpp"

class CollisionSystem: public System {
    public:
	virtual void process() override;

    private:
	void checkPlayer(Entity* asteroid, Entity* player);
	void checkAsteroid(Entity* asteroid1, Entity* asteroid2);
	void checkProjectile(Entity* asteroid, Entity* projectile);

	bool hasCollision(Entity* entity1, Entity* entity2);
	bool hasCollision(const Vector2f& vector1, const float radius1,
	    const Vector2f& vector2, const float radius2);
};
