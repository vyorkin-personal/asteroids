#pragma once

#include "Base.hpp"
#include "scene/Scene.hpp"

class MenuScene: public Scene {
    public:
        MenuScene(SceneManager* sceneManager);

        virtual void onInitialize() override;
        virtual void onIdle() override;
        virtual void onRender(const float deltaTime) override;
};
