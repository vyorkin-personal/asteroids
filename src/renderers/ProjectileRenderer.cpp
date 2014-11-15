#include "renderers/ProjectileRenderer.hpp"

void ProjectileRenderer::render(Entity* entity, const float delta) {
    const auto position = entity->getComponent<Position>();
    const auto geometry = entity->getComponent<Geometry>();

    glPushMatrix();

    glTranslatef(position->vector.x, position->vector.y, 0.0f);
    glRotatef(position->angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-geometry->radius, -geometry->radius, 0.0f);

	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.5f);
	glEnd();

	glPopMatrix();
}
