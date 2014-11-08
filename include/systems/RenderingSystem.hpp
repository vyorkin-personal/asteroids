#pragma once

#include "Base.hpp"
#include "components/View.hpp"

class RenderableSystem: public System {
    public:
	void initialize() {
	    watchComponents<View>();
	}

	bool onProcessing();
	void processEntity(Entity* entity);
};
