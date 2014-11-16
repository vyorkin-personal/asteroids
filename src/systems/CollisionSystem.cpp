#include "systems/CollisionSystem.hpp"

void CollisionSystem::process() {
    auto tagManager = world->getTagManager();
    auto groupManager = world->getGroupManager();
    auto eventBus = world->getEventBus();

    auto player = tagManager->get("player");
    auto asteroids = groupManager->getEntitiesInGroup("asteroids");
    auto projectiles = groupManager->getEntitiesInGroup("projectiles");

    for (auto& asteroid: asteroids) {
	/* if (hasCollision(asteroid, player)) { */
	/*     eventBus->emit(CollisionEvent(asteroid, */
	/* 	player, CollisionKind::AsteroidPlayer)); */
	/* } */

	/* for (auto& otherAsteroid: asteroids) { */
	/*     if (asteroid == otherAsteroid) continue; */

	/*     if (hasCollision(asteroid, otherAsteroid)) { */	
	/* 	eventBus->emit(CollisionEvent(asteroid, */
	/* 	    otherAsteroid, CollisionKind::AsteriodAsteroid)); */
	/*     } */
	/* } */

	for (auto& projectile: projectiles) {
	    if (hasCollision(asteroid, projectile)) {
		eventBus->emit(CollisionEvent(asteroid,
		    projectile, CollisionKind::AsteroidProjectile));
	    }
	}
    }
}

bool CollisionSystem::hasCollision(Entity* entity1, Entity* entity2) {
    const auto vector1 = entity1->getComponent<Position>()->vector;
    const auto radius1 = entity1->getComponent<Geometry>()->radius;

    const auto vector2 = entity2->getComponent<Position>()->vector;
    const auto radius2 = entity2->getComponent<Geometry>()->radius;

    const float minDistance = radius1 + radius2;
    const float distance = vector1.distance(vector2);

    return distance < minDistance;
}
