#pragma once

#include "Base.hpp"
#include "renderers/Renderer.hpp"

struct View: public Component {
    View(Renderer* renderer);

    Renderer* renderer;
};
