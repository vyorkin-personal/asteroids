#pragma once

#include "Base.hpp"
#include "scene/Scene.hpp"

#include "systems/CollisionSystem.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/ParticleSystem.hpp"
#include "systems/RenderingSystem.hpp"
#include "systems/InputSystem.hpp"

#include "factories/EntityFactory.hpp"

class LevelScene: public Scene {
    public:
        LevelScene();
        ~LevelScene();

        virtual void onInitialize() override;
        virtual void onPlay() override;
        virtual void onPause() override;

        virtual void onRender() override;
        virtual void onResize(const Size& size) override;

        void reset();

    private:
        EntityFactory* entityFactory;
        World* world;
};
