#pragma once

#include "Base.hpp"
#include "glut/WindowEventListener.hpp"
#include "scene/SceneState.hpp"

class Scene: public glut::WindowEventListener {
    public:
        Scene();
        virtual ~Scene() = default;

        SceneState getState() const {
            return state;
        }

        virtual void onPlay() {}
        virtual void onPause() {}

    private:
        SceneState state;

        friend SceneManager;
};
