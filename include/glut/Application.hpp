#include "Base.hpp"
#include "glut/Window.hpp"
#include "glut/WindowManager.hpp"
#include "glut/WindowDispatcher.hpp"

namespace glut {
    class Application {
        public:
            Application();
            ~Application();

            void initialize(int argc, char* argv[]);
            void addWindow(Window* window, const WindowParameters& params = WindowParameters::Default);

        private:
            WindowManager* windowManager;
            WindowDispatcher* windowDispatcher;
    };
}
