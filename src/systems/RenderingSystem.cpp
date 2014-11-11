#include "systems/RenderingSystem.hpp"

void RenderingSystem::initialize() {
    watchComponents<View, Position>();
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

    auto vec = position->vector;

    glScalef(0.2f, 0.2f, 0.0f);
    glTranslatef(vec.x - 0.5f, vec.y - 0.5f, 0.0f);
    glRotatef(position->rotation, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.5f, -0.5f, 0.0f);

    position->rotation += 1.5f;
    
    view->renderer->render(entity, getDelta());
}
