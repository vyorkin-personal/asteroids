#pragma once

#include "Base.hpp"

class Renderer {
    public:
        virtual ~Renderer() = default;
        virtual void render(Entity* entity, const float delta) = 0;
};
