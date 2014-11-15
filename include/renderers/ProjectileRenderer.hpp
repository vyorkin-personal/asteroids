#pragma once

#include "Base.hpp"
#include "renderers/Renderer.hpp"

class ProjectileRenderer: public Renderer {
    public:
        virtual void render(Entity* entity, const float delta) override;
};
