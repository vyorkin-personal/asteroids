#pragma once

#include "Base.hpp"
#include "glut/MouseButton.hpp"
#include "glut/WindowEventListener.hpp"
#include "glut/WindowParameters.hpp"

namespace glut {
    class Window: public WindowEventListener {
        public:
            void initialize(const WindowParameters& params);

            void setTitle(const char* title);

            Size getSize() const;
            void setSize(const Size& size);
            Point2i getPosition() const;
            void setPosition(const Point2i& position);

            void setFullscreen(const bool enable);
            void show();
            void hide();
            void destroy();

            int getId() const {
                return id;
            }

            bool isVisible() const {
                return visible;
            }

            bool isFullscreen() const {
                return fullscreen;
            }

        private:
            int id;
            bool fullscreen;
            bool visible;

            WindowParameters params;
            unsigned int clearFlag;

            void render();

            friend WindowManager;
            friend WindowDispatcher;
    };
}
