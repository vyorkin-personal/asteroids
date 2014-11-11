#pragma once

#include "Base.hpp"
#include "events/KeyEvent.hpp"

struct KeyUpEvent: public KeyEvent {
    KeyUpEvent(const int keyCode, const char keyChar):
        KeyEvent(keyCode, keyChar) {}
};
