#pragma once

#include "Base.hpp"

class Renderer {
    public:
        virtual void render(Entity* entity, const float delta) = 0;
};
