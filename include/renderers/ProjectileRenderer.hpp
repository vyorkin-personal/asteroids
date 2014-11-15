#pragma once

#include "Base.hpp"
#include "components/Position.hpp"
#include "components/Geometry.hpp"
#include "renderers/Renderer.hpp"

class ProjectileRenderer: public Renderer {
    public:
        virtual void render(Entity* entity, const float delta) override;
};
