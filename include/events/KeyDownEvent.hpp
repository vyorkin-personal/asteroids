#pragma once

#include "Base.hpp"
#include "events/KeyEvent.hpp"

struct KeyDownEvent: public KeyEvent {
    KeyDownEvent(const int keyCode, const char keyChar):
        KeyEvent(keyCode, keyChar) {}
};
