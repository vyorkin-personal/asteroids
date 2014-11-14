#pragma once

#include "Base.hpp"

namespace glut {
    struct WindowParameters {
        WindowParameters() = default;
        WindowParameters(const char* title, const Point2i& position,
            const Size2i& size, const bool fullscreen = true);

        String title;
        Point2i position;
        Size2i size;

        Color4f clearColor;
        bool fullscreen;

        bool doubleBuffer;
        bool depthBuffer;
        bool stencilBuffer;
        bool accumBuffer;
        bool multisampling;

        unsigned int getDisplayModeFlag() const;
        unsigned int getClearFlag() const;

        static WindowParameters Default;
    };
}
