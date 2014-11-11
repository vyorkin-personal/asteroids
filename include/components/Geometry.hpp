#pragma once

#include "Base.hpp"

struct Geometry: public Component {
    Geometry(float radius): radius{radius} {}

    float radius;
};
