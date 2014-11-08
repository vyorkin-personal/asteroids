#pragma once

#include "Base.hpp"

class InputSystem: public System {
    public:
	void initialize() {
	    watchTags({"player"});
	}

	void processEntity(Entity* entity);
};
