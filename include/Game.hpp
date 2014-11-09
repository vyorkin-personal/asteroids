#pragma once

#include "Base.hpp"
#include "glut/GameWindow.hpp"
#include "glut/Application.hpp"
#include "scene/SceneManager.hpp"
#include "scene/LevelScene.hpp"

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
