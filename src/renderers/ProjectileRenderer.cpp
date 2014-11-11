#include "renderers/ProjectileRenderer.hpp"

void ProjectileRenderer::render(Entity* entity, const float delta) {
	glBegin(GL_POINTS);
	glVertex2f(0.5f, 0.5f);
	glEnd();
}
