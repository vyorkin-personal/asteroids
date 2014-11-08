#pragma once

#include "Base.hpp"
#include "glut/Window.hpp"
#include "scene/SceneManager.hpp"

namespace glut {
    class GameWindow: public Window {
        public:
            GameWindow(SceneManager* sceneManager);
            virtual void onRender() override;
    };
}
