#include "systems/CollisionSystem.hpp"

void CollisionSystem::process() {
    auto tagManager = world->getTagManager();
    auto groupManager = world->getGroupManager();

    auto player = tagManager->get("player");
    auto asteroids = groupManager->getEntitiesInGroup("asteroids");
    auto projectiles = groupManager->getEntitiesInGroup("projectiles");

    for (auto& asteroid: asteroids) {
	checkPlayer(asteroid, player);
	for (auto& otherAsteroid: asteroids)
	    checkAsteroid(asteroid, otherAsteroid);
	for (auto& projectile: projectiles)
	    checkProjectile(asteroid, projectile);
    }
}

void CollisionSystem::checkPlayer(Entity* asteroid, Entity* player) {
    if (hasCollision(asteroid, player)) {
	world->getEventBus()->emit(CollisionEvent(asteroid,
	    player, CollisionKind::Player));
    }
}

void CollisionSystem::checkProjectile(Entity* asteroid, Entity* projectile) {
    if (hasCollision(asteroid, projectile)) {
	world->getEventBus()->emit(CollisionEvent(asteroid,
	    projectile, CollisionKind::Projectile));
    }
}

void CollisionSystem::checkAsteroid(Entity* entity1, Entity* entity2) {
    if (entity1 == entity2) return;

    auto position1 = entity1->getComponent<Position>();
    auto position2 = entity2->getComponent<Position>();

    auto radius1 = entity1->getComponent<Geometry>()->radius;
    auto radius2 = entity2->getComponent<Geometry>()->radius;

    const float minDistance = radius1 + radius2;
    const float distance = position1->vector.distance(position2->vector);

    if (distance < minDistance) {
	auto momentum1 = entity1->getComponent<Momentum>();
	auto momentum2 = entity2->getComponent<Momentum>();

	const float dx = (position2->vector.x - position1->vector.x) / distance;
	const float dy = (position2->vector.y - position1->vector.y) / distance;
	const float adjust = (minDistance - distance) / 2.0f;

	position1->vector.x -= dx * adjust;
	position1->vector.y -= dy * adjust;
	position2->vector.x += dx * adjust;
	position2->vector.y += dy * adjust;

	float contrib1 = (momentum1->velocity.linear.x * dx) + (momentum1->velocity.linear.y * dy);
	float contrib2 = (momentum2->velocity.linear.x * dx) + (momentum2->velocity.linear.y * dy);

	momentum1->velocity.linear.x += contrib2 * dx;
	momentum1->velocity.linear.y += contrib2 * dy;
	momentum1->velocity.linear.x -= contrib1 * dx;
	momentum1->velocity.linear.y -= contrib1 * dy;

	momentum2->velocity.linear.x += contrib1 * dx;
	momentum2->velocity.linear.y += contrib1 * dy;
	momentum2->velocity.linear.x -= contrib2 * dx;
	momentum2->velocity.linear.y -= contrib2 * dy;
    }
}

bool CollisionSystem::hasCollision(Entity* entity1, Entity* entity2) {
    const auto vector1 = entity1->getComponent<Position>()->vector;
    const auto radius1 = entity1->getComponent<Geometry>()->radius;

    const auto vector2 = entity2->getComponent<Position>()->vector;
    const auto radius2 = entity2->getComponent<Geometry>()->radius;

    return hasCollision(vector1, radius1, vector2, radius2);
}

bool CollisionSystem::hasCollision(const Vector2f& vector1, const float radius1,
    const Vector2f& vector2, const float radius2) {

    const float minDistance = radius1 + radius2;
    const float distance = vector1.distance(vector2);

    return distance < minDistance;
}
