#include "renderers/ParticleRenderer.hpp"

void ParticleRenderer::render(Entity* entity, const float delta) {
	auto color = entity->getComponent<Particle>()->color;

	glColor4f(color.r, color.g, color.b, color.a);
	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.0f);
	glEnd();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}
