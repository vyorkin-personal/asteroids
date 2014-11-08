#include "systems/ParticleSystem.hpp"

void ParticleSystem::processEntity(Entity* entity) {
    auto particle = entity->getComponent<Particle>();

    // ...
}
