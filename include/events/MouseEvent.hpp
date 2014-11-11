#pragma once

#include "Base.hpp"
#include "glut/MouseButton.hpp"

struct MouseEvent: public Event {
    MouseEvent(const MouseButton button, const Point2i& position):
        button{button}, position{position}

    MouseButton button;
    Point2i position;
};
