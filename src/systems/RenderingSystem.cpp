#include "systems/RenderingSystem.hpp"

bool RenderingSystem::onProcessing() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    return true;
}

void RenderingSystem::processEntity(Entity* entity) {
    auto view = entity->getComponent<View>();
    view->render(entity, getDelta());
}
