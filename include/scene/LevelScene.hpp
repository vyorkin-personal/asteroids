#pragma once

#include "Base.hpp"
#include "glut/Window.hpp"
#include "scene/Scene.hpp"

#include "events/KeyEvent.hpp"

#include "systems/CollisionSystem.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/ParticleSystem.hpp"
#include "systems/RenderingSystem.hpp"
#include "systems/InputSystem.hpp"
#include "systems/CannonSystem.hpp"
#include "systems/ExplosionSystem.hpp"

#include "factories/EntityFactory.hpp"

class LevelScene: public Scene {
    public:
        LevelScene(const Size& size);
        ~LevelScene();

        virtual void onInitialize() override;
        virtual void onPlay() override;
        virtual void onPause() override;

        virtual void onRender(const float deltaTime) override;
        virtual void onResize(const Size& size) override;
        virtual void onKeyDown(const int keyCode, const char keyChar) override;
        virtual void onKeyUp(const int keyCode, const char keyChar) override;

        void reset();

    private:
        EntityFactory* entityFactory;
        World* world;

        Size size;
        float aspectRatio;
};
