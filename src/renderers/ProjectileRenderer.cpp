#include "renderers/ProjectileRenderer.hpp"

void ProjectileRenderer::render(Entity* entity, const float delta) {
	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.5f);
	glEnd();
}
