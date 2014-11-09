#pragma once

#include "Base.hpp"
#include "scene/Scene.hpp"

class SceneManager {
    public:
        ~SceneManager();

        Scene* add(Scene* scene);
        void destroyAll();

        void setCurrent(Scene* scene);
        Scene* getCurrent() const {
            return current;
        }

    private:
        Scene* current;
        SceneSet scenes;
};
