#include "renderers/AsteroidRenderer.hpp"

void AsteroidRenderer::render(Entity* entity, const float delta) {
	auto appearance = entity->getComponent<AsteroidAppearance>();

	glBegin(GL_LINE_LOOP);
	for (const auto& vertex: appearance->polygon.vertices)
		glVertex2f(vertex.x, vertex.y);
	glEnd();
}
