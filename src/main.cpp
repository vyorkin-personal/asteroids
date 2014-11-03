#ifdef __APPLE__
#   include <OpenGL/gl.h>
#   include <OpenGL/glu.h>
#   include <GLUT/glut.h>
#else
#   include <GL/gl.h>
#   include <GL/glu.h>
#   include <GL/glut.h>
#endif

#include <cstdlib>

#include <World.hpp>

#include "math/Vector2f.hpp"

#include "components/Collidable.hpp"
#include "components/Momentum.hpp"
#include "components/Particle.hpp"
#include "components/Position.hpp"
#include "components/View.hpp"

#include "systems/CollisionSystem.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/ParticleSystem.hpp"
#include "systems/RenderingSystem.hpp"

#include "factories/EntityFactory.hpp"

#define WIDTH  640.0
#define HEIGHT 480.0

void serpinsky() {
    Vector2f points[3] = {
        {100.0F, 10.0F},
        {300.0F, 450.0F},
        {500.0F, 10.0F}
    };

    
    glBegin(GL_POINTS);

    int index = rand() % 3;
    Vector2f point = points[index];
    glVertex2f(point.x, point.y);

    for (int i = 0; i < 100000; i++) {
        index = rand() % 3;
        point.x = (point.x + points[index].x) / 2.0;
        point.y = (point.y + points[index].y) / 2.0;
        glVertex2f(point.x, point.y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    serpinsky();

    glFlush();
}

void initialize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(1.0F);
    glColor3f(1.0F, 0.0F, 0.0F);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("asteroids");
    glutFullScreen();
    glutDisplayFunc(display);
    initialize();
    glutMainLoop();
    return 0;
}
