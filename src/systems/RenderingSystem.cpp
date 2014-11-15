#include "systems/RenderingSystem.hpp"

void RenderingSystem::initialize() {
    watchComponents<View, Position, Geometry>();
}

bool RenderingSystem::onProcessing() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return true;
}

void RenderingSystem::processEntity(Entity* entity) {
    entity->getComponent<View>()->render(entity, getDelta());
}
