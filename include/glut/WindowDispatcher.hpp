#pragma once

#include "Base.hpp"
#include "glut/Window.hpp"
#include "glut/WindowManager.hpp"

namespace glut {
    class WindowDispatcher final {
        public:
            WindowDispatcher(WindowManager* windowManager);
            void register(Window* window);

        private:
            WindowManager* windowManager;

            MouseButton getMouseButton(const int button) const;

            Window* getCurrentWindow() const {
                return windowManager->getCurrent();
            }

            static void reshapeFunc(int width, int height);
            static void displayFunc();
            static void visibilityFunc(int state);
            static void closeFunc();

            static void entryFunc(int state);
            static void mouseFunc(int button, int state, int x, int y);
            static void mouseWheelFunc(int wheelNumber, int direction, int x, int y);

            static void keyboardDownFunc(unsigned char key, int x, int y);
            static void keyboardUpFunc(unsigned char key, int x, int y);

            static void specialDown(int key, int x, int y);
            static void specialUp(int key, int x, int y);

            static void joystickFunc(unsigned int buttonMask, int x, int y, int z);

            static void motionFunc(int x, int y);
            static void passiveMotionFunc(int x, int y);
    };
}
