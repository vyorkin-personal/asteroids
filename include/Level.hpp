#pragma once

#include "Base.hpp"

#include "systems/CollisionSystem.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/RenderingSystem.hpp"
#include "systems/InputSystem.hpp"
#include "systems/CannonSystem.hpp"
#include "systems/ExplosionSystem.hpp"
#include "systems/DestructionSystem.hpp"
#include "systems/ParticleSystem.hpp"

#include "factories/EntityFactory.hpp"

#include "LevelSettings.hpp"

class Level {
    public:
        Level(World* world, const Rectanglef& worldBounds);
        ~Level();

        void start(const LevelSettings& settings = LevelSettings::initial);
        void restart();

        const Rectanglef& getWorldBounds() const {
            return worldBounds;
        }

    private:
        void createSystems();
        void createObjects();

        World* world;
        EntityFactory* entityFactory;
        Rectanglef worldBounds;
        LevelSettings settings;
};
