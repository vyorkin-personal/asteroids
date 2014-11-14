#include "factories/EntityFactory.hpp"

EntityFactory::EntityFactory(World* world, const Rectanglef& worldBounds):
    world{world}, worldBounds{worldBounds},
    randomGenerator(randomDevice()) {

    playerRenderer = new PlayerRenderer();
    asteroidRenderer = new AsteroidRenderer();
    projectileRenderer = new ProjectileRenderer();

    dumper = new EntityManagerDumper(world->getEntityManager());
    
    x_distribution = std::uniform_real_distribution<float>(worldBounds.leftBottom.x, worldBounds.rightTop.x);
    y_distribution = std::uniform_real_distribution<float>(worldBounds.leftBottom.y, worldBounds.rightTop.y);
    radian_distribution = std::uniform_real_distribution<float>(0.0f, 2.0f * M_PI);
    velocity_distribution = std::uniform_real_distribution<float>(4.0f, 20.0f);
}

EntityFactory::~EntityFactory() {
    delete projectileRenderer;
    delete asteroidRenderer;
    delete playerRenderer;
    delete dumper;
}

Entity* EntityFactory::createAsteriod() {
    auto entity = world->createEntity();
    entity->addToGroup("actors");

    auto velocity = Velocity(getRandomVector(), getRandomVelocity());
    auto position = new Position(getRandomVector(), getRandomAngle());
    auto geometry = new Geometry(1.0f);
    auto polygon = generateConvexPolygon(geometry->radius);

    entity->addComponents({
        position,
        new Momentum(velocity, Dumping::One),
        new Body(10000.0f, 4.0f),
        geometry,
        new AsteroidAppearance(polygon),
        new View(asteroidRenderer)
    });

    return entity;
}

Entity* EntityFactory::createPlayer() {
    auto entity = world->createEntity();

    entity->setTag("player");
    entity->addToGroup("actors");

    entity->addComponents({
        new Position(),
        new Momentum(Velocity::Zero, Dumping(0.99f, 0.96f)),
        new Geometry(0.5f),
        new Body(65000.0f, 1.0f),
        new Cannon(200.0f),
        new PlayerAppearance(
            Vector2f(0.0f, 0.0f),
            Vector2f(0.5f, 1.0f),
            Vector2f(1.0f, 0.0f)
        ),
        new View(playerRenderer)
    });

    return entity;
}

Entity* EntityFactory::createProjectile(Momentum* momentum, Position* position, const float radius) {
    auto entity = world->createEntity();

    const float speed = 100.0f;
	const float angle = position->angle * M_PI / 180.0f + M_PI / 2.0f;

    auto projectileVelocity = Velocity(Vector2f(
        cos(angle) * speed, sin(angle) * speed), 0.0f);

    auto projectilePosition = new Position(Vector2f(
        position->vector.x + cos(angle),
        position->vector.y + sin(angle)),
        position->angle, OutOfBoundsAction::DESTROY);

    entity->addComponents({
        projectilePosition,
        new Momentum(projectileVelocity, Dumping::One),
        new Geometry(0.01f),
        new Body(4000.0f, 1.0f),
        new View(projectileRenderer)
    });

    return entity;
}

Polygon EntityFactory::generateConvexPolygon(const float radius) {
    auto polygon = Polygon();

    float angle = 0.0f;
    while (angle < 2.0f * M_PI) { 
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        polygon.vertices.push_back(Vector2f(x, y));
        angle += getRandomAngle() / 5.0f;
    }
    return polygon;
}

Vector2f EntityFactory::getRandomVector() {
    return Vector2f(x_distribution(randomGenerator), y_distribution(randomGenerator));
}

float EntityFactory::getRandomAngle() {
    return radian_distribution(randomGenerator);
}

float EntityFactory::getRandomVelocity() {
    return velocity_distribution(randomGenerator);
}
