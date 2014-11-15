#include "factories/EntityFactory.hpp"

EntityFactory::EntityFactory(World* world, const Rectanglef& worldBounds):
    world{world}, worldBounds{worldBounds},
    randomGenerator(randomDevice()) {

    playerRenderer = new PlayerRenderer();
    asteroidRenderer = new AsteroidRenderer();
    projectileRenderer = new ProjectileRenderer();
    particleRenderer = new ParticleRenderer();

    dumper = new EntityManagerDumper(world->getEntityManager());
    
    x_distribution = FloatDistribution(worldBounds.leftBottom.x, worldBounds.rightTop.x);
    y_distribution = FloatDistribution(worldBounds.leftBottom.y, worldBounds.rightTop.y);
    radian_distribution = FloatDistribution(0.0f, 2.0f * M_PI);
    velocity_distribution = FloatDistribution(-100.0f, 100.0f);
    radius_distribution = FloatDistribution(0.8f, 2.4f);
    color_distribution = FloatDistribution(0.1f, 1.0f);
}

EntityFactory::~EntityFactory() {
    delete particleRenderer;
    delete projectileRenderer;
    delete asteroidRenderer;
    delete playerRenderer;
    delete dumper;
}

Entity* EntityFactory::createAsteriod() {
    auto entity = world->createEntity();
    entity->addToGroup("asteroids");

    auto velocity = Velocity(getRandomVector(), getRandomVelocity());
    auto geometry = new Geometry(getRandomRadius());
    auto position = new Position(getRandomVector(), getRandomAngle());
    auto polygon = generateConvexPolygon(geometry->radius);

    entity->addComponents({
        position,
        new Momentum(velocity, Dumping(0.999f, 0.999f)),
        new Body(40000.0f, 4.0f),
        geometry,
        new AsteroidAppearance(polygon),
        new View(asteroidRenderer)
    });

    return entity;
}

Entity* EntityFactory::createPlayer() {
    auto entity = world->createEntity();

    entity->setTag("player");

    entity->addComponents({
        new Position(),
        new Momentum(Velocity::Zero, Dumping(0.99f, 0.96f)),
        new Geometry(0.4f),
        new Body(100000.0f, 1.0f),
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

Entity* EntityFactory::createProjectile(Momentum* momentum, Position* position) {

    auto entity = world->createEntity();
    entity->addToGroup("projectiles");

    const float speed = 100.0f;
    const float angle = position->angle * M_PI / 180.0f + M_PI / 2.0f;

    const auto projectileLinearVelocity = Vector2f(cos(angle) * speed, sin(angle) * speed);
    auto projectileVelocity = Velocity(projectileLinearVelocity, 0.0f);

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

void EntityFactory::createExplosion(const Vector2f& vector, const int numParticles) {
    for (int i = 0; i < numParticles; i++) {
        auto entity = world->createEntity();
        entity->addToGroup("particles");

        auto velocity = Velocity(getRandomVector(), getRandomVelocity());
        auto position = new Position(vector,
            getRandomAngle(),
            OutOfBoundsAction::DESTROY
        );

        entity->addComponents({
            position,
            new Momentum(velocity, Dumping(0.99f, 0.99f)),
            new Body(800.0f, 4.0f),
            new Geometry(0.001f),
            new Particle(Color4f(1.0f, 1.0f, 1.0f, 1.0f), 1200.0f),
            new View(particleRenderer)
        });

    }
}

Polygon EntityFactory::generateConvexPolygon(const float radius) {
    auto polygon = Polygon();

    float angle = 0.0f;
    while (angle < 2.0f * M_PI) { 
        const float x = radius + radius * cos(angle);
        const float y = radius + radius * sin(angle);
        polygon.vertices.push_back(Vector2f(x, y));
        angle += getRandomAngle() / 4.0f;
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

float EntityFactory::getRandomRadius() {
    return radius_distribution(randomGenerator);
}

Color4f EntityFactory::getRandomColor() {
    return Color4f(
        color_distribution(randomGenerator),
        color_distribution(randomGenerator),
        color_distribution(randomGenerator),
        1.0f
    );
}
