#include "renderers/PlayerRenderer.hpp"

void PlayerRenderer::render(Entity* entity, const float delta) {
    const auto position = entity->getComponent<Position>();
    const auto geometry = entity->getComponent<Geometry>();
	auto appearance = entity->getComponent<PlayerAppearance>();

    glPushMatrix();

    glTranslatef(position->vector.x, position->vector.y, 0.0f);
    glRotatef(position->angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-geometry->radius, -geometry->radius, 0.0f);

	glBegin(GL_POLYGON);
	glVertex2f(appearance->a.x, appearance->a.y);
	glVertex2f(appearance->b.x, appearance->b.y);
	glVertex2f(appearance->c.x, appearance->c.y);
	glEnd();

    glPopMatrix();
}
