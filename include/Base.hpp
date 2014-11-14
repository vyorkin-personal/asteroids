#pragma once

#ifdef __APPLE__
#   include <OpenGL/gl.h>
#   include <OpenGL/glu.h>
#   include <GLUT/glut.h>
#else
#   include <GL/gl.h>
#   include <GL/glu.h>
#   include <GL/glut.h>
#endif

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>

#include <Gfs.hpp>

using namespace gfs;
using namespace gfs::event;
using namespace gfs::ecs;
using namespace gfs::math;

class Scene;
class SceneManager;
using SceneSet = std::set<Scene*>;

class MenuScene;
class LevelScene;

class EntityFactory;

namespace glut {
    struct WindowParameters;
    class WindowEventListener;
    class Window;
    class WindowManager;
    class WindowDispatcher;
    class GameWindow;
    class Application;

    using WindowMap = std::unordered_map<int, Window*>;
}

struct Velocity;
struct Dumping;

struct KeyEvent;
struct MouseEvent;
struct ExplosionEvent;

struct ShipAppearance;
struct AsteroidAppearance;

class Renderer;
class PlayerRenderer;
class AsteroidRenderer;
class ProjectileRenderer;

struct Geometry;
struct Momentum;
struct Particle;
struct Position;
struct Cannon;
struct View;

class CollisionSystem;
class InputSystem;
class MovementSystem;
class ParticleSystem;
class RenderingSystem;
class CannonSystem;
