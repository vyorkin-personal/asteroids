#include "systems/CollisionSystem.hpp"

CollisionSystem::CollisionSystem(GroupManager* groupManager):
    groupManager{groupManager} {}

void CollisionSystem::process() {
    auto projectiles = groupManager->getEntitiesInGroup("projectiles");
    auto asteroids = groupManager->getEntitiesInGroup("asteroids");

    for (auto& projectile: projectiles) {
	auto projectilePosition = projectile->getComponent<Position>();
	auto projectileGeometry = projectile->getComponent<Geometry>();
	const auto projectileRadius = projectileGeometry->radius;

	for (auto& asteroid: asteroids) {
	    auto asteroidPosition = asteroid->getComponent<Position>();
	    auto asteroidGeometry = asteroid->getComponent<Geometry>();
	    const auto asteroidRadius = asteroidGeometry->radius;

	    auto asteroidVector = asteroidPosition->vector;

	    const float minDistance = projectileRadius + asteroidRadius;
	    const float distance = asteroidVector.distance(projectilePosition->vector);

	    if (distance < minDistance) {
		asteroid->destroy();
		projectile->destroy();
	    }
	}
    }
}
