#pragma once

#include "Base.hpp"

class EntityFactory {
    public:
	EntityFactory(EntityManager* entityManager);

	Entity* createAsteriod();
	Entity* createPlayer();
};
