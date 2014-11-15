#pragma once

#include "Base.hpp"
#include "renderers/Renderer.hpp"
#include "components/Particle.hpp"

class ParticleRenderer: public Renderer {
    public:
        virtual void render(Entity* entity, const float delta) override;
};
