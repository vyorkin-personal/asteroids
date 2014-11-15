#include "systems/ParticleSystem.hpp"

void ParticleSystem::initialize() {
    watchComponents<Particle>();
}

void ParticleSystem::processEntity(Entity* entity) {
    auto particle = entity->getComponent<Particle>();

    particle->age += getDelta();
    particle->color.a -= 0.06;

    if (particle->age > particle->lifetime)
        entity->destroy();
}
