#pragma once

#include "Base.hpp"

#include "components/Position.hpp"
#include "components/Cannon.hpp"

class CannonSystem: public System {
    public:
	virtual void initialize() override;
	virtual void processEntity(Entity* entity) override;
};
