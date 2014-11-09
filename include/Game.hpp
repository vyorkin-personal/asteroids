#pragma once

#include "Base.hpp"

class Game {
    public:
        Game();
        ~Game();

        void initialize(int argc, char** argv);
        void start();

    private:
        glut::Application* application;
        glut::GameWindow* window;
};
