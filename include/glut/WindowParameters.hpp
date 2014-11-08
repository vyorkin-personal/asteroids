#pragma once

#include "Base.hpp"
#include "math/Vector2.hpp"
#include "math/Color4.hpp"

namespace glut {
    struct WindowParameters {
        WindowParameters(const char* title, const Point2i& position,
            const Size& size, const bool fullscreen = true);

        const int WIDTH_DEFAULT = 800;
        const int HEIGHT_DEFAULT = 600;
        const int POSITION_X_DEFAULT = 10;
        const int POSITION_Y_DEFAULT = 10;

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
