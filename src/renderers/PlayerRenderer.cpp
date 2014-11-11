#include "renderers/PlayerRenderer.hpp"

void PlayerRenderer::render(Entity* entity, const float delta) {
	glBegin(GL_POLYGON);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.5f, 1.0f);
	glVertex2f(1.0f, 0.0f);
	glEnd();
}
