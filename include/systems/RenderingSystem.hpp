#pragma once

#include "Base.hpp"
#include "components/View.hpp"

class RenderingSystem: public System {
    public:
	virtual void initialize() override {
	    watchComponents<View>();
	}

	virtual bool onProcessing() override;
	virtual void processEntity(Entity* entity) override;
};
