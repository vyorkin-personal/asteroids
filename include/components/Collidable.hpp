#pragma once

#include <Component.hpp>

struct Collidable: public gfs::Component {
    Collidable(float r): radius{r} {}

    float radius;
};
