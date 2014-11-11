#pragma once

#include "Base.hpp"
#include "renderers/Renderer.hpp"

class PlayerRenderer: public Renderer {
    public:
        virtual void render(Entity* entity, const float delta) override;
};
