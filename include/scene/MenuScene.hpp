#pragma once

#include "Base.hpp"
#include "scene/Scene.hpp"

class MenuScene: public Scene {
    public:
        virtual void onInitialize() override;
        virtual void onIdle() override;
        virtual void onRender() override;
};
