#pragma once

#include "Base.hpp"
#include "glut/WindowEventListener.hpp"
#include "scene/SceneManager.hpp"
#include "scene/SceneState.hpp"

class Scene: public glut::WindowEventListener {
    public:
        Scene(SceneManager* sceneManager);
        virtual ~Scene() = default;

        SceneState getState() const {
            return state;
        }

        virtual void onPlay() {}
        virtual void onPause() {}

    protected:
        SceneManager* sceneManager;

    private:
        SceneState state;

        friend SceneManager;
};
