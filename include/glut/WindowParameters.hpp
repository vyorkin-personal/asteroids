#pragma once

#include "Base.hpp"

namespace glut {
    struct WindowParameters {
        WindowParameters() = default;
        WindowParameters(const char* title, const Point2i& position,
            const Size& size, const bool fullscreen = true);

        Point2i position;
        Size size;

        Color4f clearColor;
        bool fullscreen;

        bool doubleBuffer;
        bool depthBuffer;
        bool stencilBuffer;
        bool accumBuffer;
        bool multisampling;

        String title;

        unsigned int getDisplayModeFlag() const;
        unsigned int getClearFlag() const;

        static WindowParameters Default;
    };
}
