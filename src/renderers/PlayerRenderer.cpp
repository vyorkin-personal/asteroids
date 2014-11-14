#include "renderers/PlayerRenderer.hpp"

void PlayerRenderer::render(Entity* entity, const float delta) {
	auto appearance = entity->getComponent<PlayerAppearance>();

	glBegin(GL_POLYGON);
	glVertex2f(appearance->a.x, appearance->a.y);
	glVertex2f(appearance->b.x, appearance->b.y);
	glVertex2f(appearance->c.x, appearance->c.y);
	glEnd();
}
