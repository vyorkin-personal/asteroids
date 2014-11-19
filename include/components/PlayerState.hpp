#pragma once

#include "Base.hpp"

struct PlayerState: public Component {
    PlayerState(): alive{true} {}

    bool alive;
};
