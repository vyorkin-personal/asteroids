#pragma once

#include "Base.hpp"
#include "scene/Scene.hpp"
#include "glut/Window.hpp"

class SceneManager {
    public:
        SceneManager(glut::Window* window);
        ~SceneManager();

        Scene* add(Scene* scene);
        void destroyAll();

        void setCurrent(Scene* scene);
        Scene* getCurrent() const {
            return current;
        }

    private:
        glut::Window* window;
        Scene* current;
        SceneSet scenes;
};
