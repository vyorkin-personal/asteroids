#pragma once

#include "Base.hpp"

class View: public Component {
    public:
	virtual void render(Entity* entity, const float delta) = 0;
};
