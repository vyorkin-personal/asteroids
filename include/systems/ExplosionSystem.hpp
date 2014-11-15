#pragma once

#include "Base.hpp"
#include "factories/EntityFactory.hpp"
#include "events/ExplosionEvent.hpp"

class ExplosionSystem: public System {
    public:
	ExplosionSystem(EntityFactory* entityFactory);

	virtual void initialize() override;
	void onExplosion(const ExplosionEvent& e);

    private:
	EntityFactory* entityFactory;
};
