#pragma once

#include "Base.hpp"

struct AsteroidAppearance: public Component {
    AsteroidAppearance(const Polygon& polygon);

    Polygon polygon;
};
