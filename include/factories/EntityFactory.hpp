#pragma once

#include "Base.hpp"

#include "common/Velocity.hpp"
#include "common/Dumping.hpp"

#include "components/Geometry.hpp"
#include "components/Momentum.hpp"
#include "components/Body.hpp"
#include "components/Particle.hpp"
#include "components/Position.hpp"
#include "components/Cannon.hpp"
#include "components/View.hpp"

#include "components/appearance/PlayerAppearance.hpp"
#include "components/appearance/AsteroidAppearance.hpp"

#include "renderers/PlayerRenderer.hpp"
#include "renderers/AsteroidRenderer.hpp"
#include "renderers/ProjectileRenderer.hpp"

class EntityFactory {
    public:
	EntityFactory(World* world, const Rectanglef& worldBounds);
	~EntityFactory();

	Entity* createAsteriod();
	Entity* createPlayer();
	Entity* createProjectile(Momentum* momentum, Position* position, const float radius);

    private:
	Polygon generateConvexPolygon(const float radius);
	Vector2f getRandomVector();
	float getRandomAngle();
	float getRandomVelocity();

	World* world;

	PlayerRenderer* playerRenderer;
	AsteroidRenderer* asteroidRenderer;
	ProjectileRenderer* projectileRenderer;

	Rectanglef worldBounds;

	EntityManagerDumper* dumper;

	std::random_device randomDevice;
	std::mt19937_64 randomGenerator;
	std::uniform_real_distribution<float> x_distribution;
	std::uniform_real_distribution<float> y_distribution;
	std::uniform_real_distribution<float> radian_distribution;
	std::uniform_real_distribution<float> velocity_distribution;
};
