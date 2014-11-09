#pragma once

#include "Base.hpp"
#include "glut/MouseButton.hpp"
#include "glut/Window.hpp"
#include "glut/WindowManager.hpp"

namespace glut {
    class WindowDispatcher {
        public:
            static void initialize(WindowManager* windowManager);
            static void set(Window* window);

        private:
            static WindowManager* windowManager;

            static MouseButton getMouseButton(const int button);
            static Window* getCurrentWindow() {
                return windowManager->getCurrent();
            }

            static void reshapeFunc(int width, int height);
            static void displayFunc();
            static void visibilityFunc(int state);

            static void entryFunc(int state);
            static void mouseFunc(int button, int state, int x, int y);

            static void keyboardFunc(unsigned char key, int x, int y);
            static void specialFunc(int key, int x, int y);

            static void motionFunc(int x, int y);
            static void passiveMotionFunc(int x, int y);
            
            static void idleFunc();
            static void timerFunc(int value);

            static void setTimer();
    };
}
