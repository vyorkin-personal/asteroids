#include "factories/EntityFactory.hpp"

EntityFactory::EntityFactory(World* world, const Size& size):
    world{world}, size{size} {
    entityManager = world->getEntityManager();
    playerRenderer = new PlayerRenderer();
    asteroidRenderer = new AsteroidRenderer();
}

EntityFactory::~EntityFactory() {
    delete asteroidRenderer;
    delete playerRenderer;
}

Entity* EntityFactory::createAsteriod() {
    auto entity = entityManager->create();
    entity->addComponents({
        new Position(Vector2f::Zero, 0.0f),
        new Momentum(Vector2f::Zero, 0.0f, 0.0f),
        new Collidable(0.5f),
        new View(asteroidRenderer)
    });

    return entity;
}

Entity* EntityFactory::createPlayer() {
    auto entity = entityManager->create();

    entity->setTag("player");
    entity->addToGroup("actors");

    entity->addComponents({
        new Position(Vector2f(0.3f, 0.5f), 0.5f),
        new Momentum(Vector2f(0.0f, 0.0f), 0.1f, 1.0f),
        new Collidable(0.5f),
        new View(playerRenderer)
    });

    return entity;
}
