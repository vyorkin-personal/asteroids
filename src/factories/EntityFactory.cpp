#include "factories/EntityFactory.hpp"

EntityFactory::EntityFactory(World* world, const Size& size):
    world{world}, size{size} {
    entityManager = world->getEntityManager();
    playerRenderer = new PlayerRenderer();
    asteroidRenderer = new AsteroidRenderer();
    projectileRenderer = new ProjectileRenderer();
}

EntityFactory::~EntityFactory() {
    delete projectileRenderer;
    delete asteroidRenderer;
    delete playerRenderer;
}

Entity* EntityFactory::createAsteriod() {
    auto entity = entityManager->create();

    entity->addToGroup("actors");
    entity->addComponents({
        new Position(Vector2f::Zero, 0.0f),
        new Momentum(Vector2f::Zero, 0.0f, 1.0f),
        new Body(10000.0f, 4.0f),
        new Geometry(0.5f),
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
        new Momentum(Vector2f(0.0f, 0.0f), 0.0f, 0.99f, 0.96f),
        new Geometry(0.5f),
        new Body(65000.0f, 1.0f),
        new Cannon(1.0f),
        new View(playerRenderer)
    });

    return entity;
}

Entity* EntityFactory::createProjectile() {
    auto entity = entityManager->create();

    entity->addComponents({
        new Position(Vector2f::Zero, 0.0f),
        new Momentum(Vector2f::Zero, 0.0f, 0.98f),
        new Geometry(0.1f),
        new Body(400.0f, 0.001f),
        new View(projectileRenderer)
    });

    return entity;
}
