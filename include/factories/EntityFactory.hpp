#pragma once

#include "Base.hpp"

#include "components/Collidable.hpp"
#include "components/Momentum.hpp"
#include "components/Particle.hpp"
#include "components/Position.hpp"
#include "components/View.hpp"

class EntityFactory {
    public:
	EntityFactory(EntityManager* entityManager);

	Entity* createAsteriod();
	Entity* createPlayer();

    private:
	EntityManager* entityManager;
};
