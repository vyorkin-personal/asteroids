#include "systems/CollisionSystem.hpp"

CollisionSystem::CollisionSystem(GroupManager* groupManager):
    groupManager{groupManager} {}

void CollisionSystem::process() {
    auto projectiles = groupManager->getEntitiesInGroup("projectiles");
    auto asteroids = groupManager->getEntitiesInGroup("asteroids");

    for (auto& projectile: projectiles) {
	for (auto& asteroid: asteroids) {
	}
    }
}
