#pragma once

#include "Base.hpp"
#include "glut/MouseButton.hpp"

namespace glut {
    class WindowEventListener {
        public:
            virtual void onInitialize() {}
            virtual void onIdle() {}
            virtual void onTimer(int value) {}
            virtual void onResize(const Size& size) {}
            virtual void onRender() {}
            virtual void onDestroy() {}
            virtual void onShow() {}
            virtual void onHide() {}

            virtual void onMouseEnter() {}
            virtual void onMouseLeave() {}
            virtual void onMouseButtonDown(const MouseButton button, const Point2i& position) {}
            virtual void onMouseButtonUp(const MouseButton button, const Point2i& position) {}
            virtual void onMouseMove(const Point2i& position) {}

            virtual void onKey(const int keyCode, const char keyChar) {}
    };
}
