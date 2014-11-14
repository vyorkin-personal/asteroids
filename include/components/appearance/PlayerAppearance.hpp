#pragma once

#include "Base.hpp"

struct PlayerAppearance: public Component {
    PlayerAppearance(const Vector2f& a, const Vector2f& b, const Vector2f& c);

    Vector2f a;
    Vector2f b;
    Vector2f c;
};
