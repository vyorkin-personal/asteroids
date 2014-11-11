#pragma once

#include "Base.hpp"
#include "components/Momentum.hpp"
#include "components/Position.hpp"
#include "events/KeyEvent.hpp"

class InputSystem: public System {
    public:
	virtual void initialize() override;

	void onKey(const KeyEvent& e);
};
