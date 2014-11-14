#pragma once

#include "Base.hpp"

struct Dumping {
    Dumping(const float linear, const float angular);

    float linear;
    float angular;

    const static Dumping Zero;
    const static Dumping One;
};
