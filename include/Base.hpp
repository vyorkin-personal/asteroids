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

#include <Prerequisites.hpp>
#include <ecs/Entity.hpp>
#include <ecs/System.hpp>
#include <ecs/World.hpp>

namespace glut {
    class Application;
    class Window;
    class WindowManager;
    class WindowDispatcher;
    using WindowMap = std::unordered_map<int, Window*>;

    class Collidable;
    class Momentum;
    class Particle;
    class Position;
    class View;

    class CollisionSystem;
    class InputSystem;
    class MovementSystem;
    class ParticleSystem;
    class RenderingSystem;
}

using namespace gfs;
using namespace gfs::ecs;
using namespace gfs::math;
