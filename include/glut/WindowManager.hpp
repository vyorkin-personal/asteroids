#pragma once

#include "Base.hpp"
#include "glut/Window.hpp"
#include "glut/WindowParameters.hpp"

namespace glut {
    class WindowManager final {
        public:
            ~WindowManager();

            Window* add(Window* window, const WindowParameters& params);
            void destroy(Window* window);
            void destroy(const int windowId);
            void destroyAll();

            Window* getCurrent() const;
            void setCurrent(Window* window);

        private:
            unsigned int getDisplayModeFlags() const;

            WindowMap windows;

            friend WindowDispatcher;
    };
}

