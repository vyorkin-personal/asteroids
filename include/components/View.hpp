#pragma once

#include "Base.hpp"
#include "renderers/Renderer.hpp"

struct View: public Component {
    View(Renderer* renderer);

    void render(Entity* entity, const float delta);

    Renderer* renderer;
};
