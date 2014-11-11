#pragma once

#include "Base.hpp"
#include "events/ExplosionEvent.hpp"

class ExplosionSystem: public System {
    public:
	virtual void initialize() override;
	void onExplosion(const ExplosionEvent& e);
};
