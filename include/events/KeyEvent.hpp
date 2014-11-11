#pragma once

#include "Base.hpp"

struct KeyEvent: public Event {
    KeyEvent(const int keyCode, const char keyChar):
        keyCode{keyCode}, keyChar{keyChar} {}

    int keyCode;
    char keyChar;
};
