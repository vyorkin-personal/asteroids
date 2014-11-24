#include "Level.hpp"

Level::Level(World* world, const Rectanglef& worldBounds):
    world{world}, worldBounds{worldBounds} {

    entityFactory = new EntityFactory(world, worldBounds);
    groupManager = world->getGroupManager();
    tagManager = world->getTagManager();
}

Level::~Level() {
    delete entityFactory;
}

void Level::start(const LevelSettings& settings) {
    this->settings = settings;
    createSystems();
    restart();
}

void Level::restart() {
    world->reset();
    createObjects();
    state = LevelState::Playing;
}

void Level::next() {
    settings.numAsteroids += 4;
    restart();
}

void Level::update(const float deltaTime) {
    world->setDelta(deltaTime);
    world->process();

    processState();

    if (state == LevelState::Won)
	next();
    else if (state == LevelState::Lost)
	restart();
}

void Level::processState() {
    if (!player->getComponent<PlayerState>()->alive)
	state = LevelState::Lost;
    else if (groupManager->isEmptyGroup("asteroids"))
	state = LevelState::Won;
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
    player = entityFactory->createPlayer();

    for (int i = 0; i <= settings.numAsteroids; i++)
        entityFactory->createAsteroid();
}
