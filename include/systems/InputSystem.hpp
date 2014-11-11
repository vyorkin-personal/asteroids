#pragma once

#include "Base.hpp"

#include "components/Momentum.hpp"
#include "components/Position.hpp"
#include "components/Cannon.hpp"

#include "events/KeyEvent.hpp"
#include "events/KeyUpEvent.hpp"
#include "events/KeyDownEvent.hpp"

enum Keys {
    Fire = 32,
    Forward = GLUT_KEY_UP,
    Backward = GLUT_KEY_DOWN,
    Left = GLUT_KEY_LEFT,
    Right = GLUT_KEY_RIGHT
};

class InputSystem: public System {
    public:
	virtual void initialize() override;

	void onKeyDown(const KeyDownEvent& e);
	void onKeyUp(const KeyUpEvent& e);

	virtual void processEntity(Entity* entity) override;

    private:
	bool keys[256];
	bool specialKeys[256];
};
