#include "factories/EntityFactory.hpp"

EntityFactory::EntityFactory(EntityManager* entityManager):
    entityManager{entityManager} {}

Entity* EntityFactory::createAsteriod() {
    auto entity = entityManager->create();
    /*
    entity->addComponents({
	new Position(),
	new Momentum(),
	new Collidable()
	new View()
    });
    */

    return entity;
}


Entity* EntityFactory::createPlayer() {
    auto entity = entityManager->create();
    return entity;
}
