#include "renderers/AsteroidRenderer.hpp"

void AsteroidRenderer::render(Entity* entity, const float delta) {
    const auto position = entity->getComponent<Position>();
    const auto geometry = entity->getComponent<Geometry>();
	auto appearance = entity->getComponent<AsteroidAppearance>();

    glPushMatrix();

    glTranslatef(position->vector.x, position->vector.y, 0.0f);
    glRotatef(position->angle, 0.0f, 0.0f, 1.0f);

	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	for (const auto& vertex: appearance->polygon.vertices)
		glVertex2f(vertex.x, vertex.y);
	glEnd();

    glPopMatrix();
}
