#include "systems/DestructionSystem.hpp"

DestructionSystem::DestructionSystem(EntityFactory* entityFactory):
	entityFactory{entityFactory} {}

void DestructionSystem::initialize() {
	getEventBus()->subscribe<CollisionEvent>(
		this, &DestructionSystem::onCollision);
}

void DestructionSystem::onCollision(const CollisionEvent& e) {
	if (e.kind == CollisionKind::Projectile)
		handleProjectileCollision(e.asteroid, e.collider);
	else if (e.kind == CollisionKind::Player)
		handlePlayerCollision(e.collider);

	getEventBus()->emit(ExplosionEvent(
		e.asteroid->getComponent<Position>()->vector,
		ExplosionKind::Small));

	e.asteroid->destroy();
}

void DestructionSystem::handlePlayerCollision(Entity* player) {
	player->getComponent<PlayerAppearance>()->visible = false;
	player->getComponent<PlayerState>()->alive = false;
}

void DestructionSystem::handleProjectileCollision(Entity* asteroid, Entity* projectile) {
	const float bigMass = 30000.0f;

	const auto vector = asteroid->getComponent<Position>()->vector;
	const auto mass = asteroid->getComponent<Body>()->mass;
	const auto radius = asteroid->getComponent<Geometry>()->radius;

	if (mass > bigMass) {
		entityFactory->createAsteroid(vector, radius / 2.0f);
		entityFactory->createAsteroid(vector, radius / 2.0f);
	}

	projectile->destroy();
}
