#pragma once

#include "Base.hpp"
#include "components/Position.hpp"
#include "components/Geometry.hpp"
#include "components/View.hpp"
#include "renderers/Renderer.hpp"

class RenderingSystem: public System {
    public:
	virtual void initialize() override;

	virtual bool onProcessing() override;
	virtual void onProcessed() override;
	virtual void processEntity(Entity* entity) override;
};
