#pragma once

#include "Base.hpp"

class InputSystem: public System {
    public:
	virtual void initialize() override {
	    watchTags({"player"});
	}

	virtual void processEntity(Entity* entity) override;
};
