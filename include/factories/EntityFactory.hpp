#pragma once

#include "Base.hpp"

#include "components/Geometry.hpp"
#include "components/Momentum.hpp"
#include "components/Body.hpp"
#include "components/Particle.hpp"
#include "components/Position.hpp"
#include "components/Cannon.hpp"
#include "components/View.hpp"

#include "renderers/PlayerRenderer.hpp"
#include "renderers/AsteroidRenderer.hpp"
#include "renderers/ProjectileRenderer.hpp"

class EntityFactory {
    public:
	EntityFactory(World* world, const Size& size);
	~EntityFactory();

	Entity* createAsteriod();
	Entity* createPlayer();
	Entity* createProjectile();

    private:
	World* world;
	EntityManager* entityManager;

	PlayerRenderer* playerRenderer;
	AsteroidRenderer* asteroidRenderer;
	ProjectileRenderer* projectileRenderer;

	Size size;
};
