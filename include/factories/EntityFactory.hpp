#pragma once

#include "Base.hpp"

#include "components/Collidable.hpp"
#include "components/Momentum.hpp"
#include "components/Particle.hpp"
#include "components/Position.hpp"
#include "components/Cannon.hpp"
#include "components/View.hpp"

#include "renderers/PlayerRenderer.hpp"
#include "renderers/AsteroidRenderer.hpp"

class EntityFactory {
    public:
	EntityFactory(World* world, const Size& size);
	~EntityFactory();

	Entity* createAsteriod();
	Entity* createPlayer();

    private:
	World* world;
	EntityManager* entityManager;
	PlayerRenderer* playerRenderer;
	AsteroidRenderer* asteroidRenderer;
	Size size;
};
