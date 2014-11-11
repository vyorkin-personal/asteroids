#include "systems/RenderingSystem.hpp"

void RenderingSystem::initialize() {
    watchComponents<View, Position, Geometry>();
}

bool RenderingSystem::onProcessing() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPushMatrix();

    return true;
}

void RenderingSystem::onProcessed() {
    glPopMatrix();
}

void RenderingSystem::processEntity(Entity* entity) {
    auto view = entity->getComponent<View>();
    auto position = entity->getComponent<Position>();
    const auto geometry = entity->getComponent<Geometry>();
    const float radius = geometry->radius;
    const auto vec = position->vector;

    glScalef(0.1f, 0.1f, 0.0f);
    glTranslatef(vec.x - radius, vec.y - radius, 0.0f);
    glRotatef(position->rotation, 0.0f, 0.0f, 1.0f);
    glTranslatef(-radius, -radius, 0.0f);
    
    view->renderer->render(entity, getDelta());
}
