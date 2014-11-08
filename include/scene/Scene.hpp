#pragma once

#include "Base.hpp"
#include "glut/WindowEventListener.hpp"
#include "scene/SceneState.hpp"

class Scene: public glut::WindowEventListener {
    public:
        Scene();

        SceneState getState() const {
            return state;
        }

    private:
        SceneState state;
};
