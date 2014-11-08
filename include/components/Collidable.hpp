#pragma once

#include "Base.hpp"

struct Collidable: public Component {
    Collidable(float radius): radius{radius} {}

    float radius;
};
