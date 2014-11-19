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
#include "LevelState.hpp"

class Level {
    public:
        Level(World* world, const Rectanglef& worldBounds);
        ~Level();

        void start(const LevelSettings& settings = LevelSettings::initial);
        void restart();
        void next();

        void update(const float deltaTime);

        const Rectanglef& getWorldBounds() const {
            return worldBounds;
        }

        LevelState getState() const {
            return state;
        }

    private:
        void createSystems();
        void createObjects();
        void processState();

        World* world;
        GroupManager* groupManager;
        TagManager* tagManager;

        EntityFactory* entityFactory;
        Entity* player;

        Rectanglef worldBounds;
        LevelSettings settings;
        LevelState state;
};
