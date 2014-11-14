#include "systems/RenderingSystem.hpp"

void RenderingSystem::initialize() {
    watchComponents<View, Position, Geometry>();
}

bool RenderingSystem::onProcessing() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return true;
}

void RenderingSystem::onProcessed() {
}

void RenderingSystem::processEntity(Entity* entity) {
    const auto view = entity->getComponent<View>();
    const auto position = entity->getComponent<Position>();
    const auto geometry = entity->getComponent<Geometry>();

    glPushMatrix();

    glTranslatef(position->vector.x, position->vector.y, 0.0f);
    glRotatef(position->angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-geometry->radius, -geometry->radius, 0.0f);
    
    view->render(entity, getDelta());

    glPopMatrix();
}
