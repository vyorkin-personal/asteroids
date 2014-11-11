#include "systems/ParticleSystem.hpp"

void ParticleSystem::initialize() {
    watchComponents<Particle>();
}

void ParticleSystem::processEntity(Entity* entity) {
    auto particle = entity->getComponent<Particle>();

    // ...
}
