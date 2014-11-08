#pragma once

#include "Base.hpp"
#include "scene/Scene.hpp"

class LevelScene: public Scene {
    public:
        LevelScene(World* world);

        virtual void onInitialize() override;
        virtual void onIdle() override;
        virtual void onRender() override;
        virtual void onResize(const Point2i& size) override;

    private:
        World* world;
};
