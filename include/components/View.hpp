#pragma once

#include <Component.hpp>
#include <Entity.hpp>

class View: public gfs::Component {
    public:
	virtual void render(gfs::Entity* entity, const float delta) = 0;
};
