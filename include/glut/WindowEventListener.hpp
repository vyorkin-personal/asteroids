#pragma once

#include "Base.hpp"
#include "glut/MouseButton.hpp"

namespace glut {
    class WindowEventListener {
        protected:
            virtual void onInitialize() {}
            virtual void onIdle() {}
            virtual void onTimer(int value) {}
            virtual void onResize(const int width, const int height) {}
            virtual void onRender() {}
            virtual void onDestroy() {}
            virtual void onClose() {}
            virtual void onShow() {}
            virtual void onHide() {}

            virtual void onMouseEnter() {}
            virtual void onMouseLeave() {}
            virtual void onMouseButtonDown(const MouseButton button, const int x, const int y) {}
            virtual void onMouseButtonUp(const MouseButton button, const int x, const int y) {}
            virtual void onMouseMove(const int x, const int y) {}
            virtual void onMouseWheel(const int wheelNumber, const int direction, const int x, const int y) {}

            virtual void onKeyDown(const int keyCode, const char keyChar) {}
            virtual void onKeyUp(const int keyCode, const char keyChar) {}

            virtual void onJoystick(const unsigned int button, int x, int y, int z) {}
    };
}
