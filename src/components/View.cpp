#include "components/View.hpp"

View::View(Renderer* renderer):
	renderer{renderer} {}

void View::render(Entity* entity, const float delta) {
	renderer->render(entity, delta);
}
