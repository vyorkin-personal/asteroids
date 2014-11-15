#pragma once

#include "Base.hpp"
#include "glut/Window.hpp"
#include "scene/Scene.hpp"
#include "scene/SceneManager.hpp"

#include "events/KeyEvent.hpp"

#include "Level.hpp"
#include "LevelSettings.hpp"

class LevelScene: public Scene {
    public:
        LevelScene(SceneManager* sceneManager, World* world, Level* level);
        ~LevelScene();

        virtual void onInitialize() override;
        virtual void onPlay() override;
        virtual void onPause() override;

        virtual void onRender(const float deltaTime) override;
        virtual void onResize(const Size2i& size) override;
        virtual void onKeyDown(const int keyCode, const char keyChar) override;
        virtual void onKeyUp(const int keyCode, const char keyChar) override;

    private:
        void setOrtho(const float aspectRatio);
        Rectanglef getViewVolume(const float aspectRatio) const;

        World* world;
        Level* level;
};
