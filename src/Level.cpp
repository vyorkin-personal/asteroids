#include "Level.hpp"

Level::Level(World* world, const Rectanglef& worldBounds):
	world{world}, worldBounds{worldBounds} {
	entityFactory = new EntityFactory(world, worldBounds);
}

Level::~Level() {
	delete entityFactory;
}

void Level::start(const LevelSettings& settings) {
	this->settings = settings;
	createSystems();
	createObjects();
}

void Level::restart() {
	world->reset();
	createObjects();
}

void Level::createSystems() {
    auto systemManager = world->getSystemManager();
    systemManager->add(new MovementSystem(worldBounds));
    systemManager->add(new RenderingSystem());
    systemManager->add(new InputSystem());
    systemManager->add(new CollisionSystem());
    systemManager->add(new ExplosionSystem(entityFactory));
    systemManager->add(new CannonSystem(entityFactory));
    systemManager->add(new DestructionSystem(entityFactory));
    systemManager->add(new ParticleSystem());
}

void Level::createObjects() {
    entityFactory->createPlayer();
    for (int i = 0; i <= settings.numAsteroids; i++)
        entityFactory->createAsteroid();
}
