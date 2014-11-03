#pragma once

#include <System.hpp>
#include "components/View.hpp"

class RenderableSystem: public gfs::System {
    public:
	void initialize() {
	    watchComponents<View>();
	}

	void processEntity(gfs::Entity* entity, const float delta) {
	    auto view = entity->getComponent<View>();

	    // ...
	}
};
