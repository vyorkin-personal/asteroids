#pragma once

#include "Base.hpp"

#include "components/Position.hpp"
#include "components/Cannon.hpp"
#include "factories/EntityFactory.hpp"

class CannonSystem: public System {
    public:
	CannonSystem(EntityFactory* entityFactory);

	virtual void initialize() override;
	virtual void processEntity(Entity* entity) override;

    private:
	EntityFactory* entityFactory;
};
