#pragma once

#include "Base.hpp"

struct Body: public Component {
    Body(const float mass, const float gravity);

    float mass;
    float gravity;
};
