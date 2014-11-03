#pragma once

#include <System.hpp>
#include "components/View.hpp"

class RenderableSystem: public gfs::System {
    public:
	void initialize() {
	    watchComponents<View>();
	}

	bool onProcessing() {
	    glMatrixMode(GL_PROJECTION);
	    glLoadIdentity();
	    return true;
	}

	void processEntity(gfs::Entity* entity, const float delta) {
	    auto view = entity->getComponent<View>();
	    view->render(entity, delta);
	}
};
