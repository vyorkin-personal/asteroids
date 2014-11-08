#include "Base.hpp"
#include "math/Vector2.hpp"

#include "components/Collidable.hpp"
#include "components/Momentum.hpp"
#include "components/Particle.hpp"
#include "components/Position.hpp"
#include "components/View.hpp"

#include "systems/CollisionSystem.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/ParticleSystem.hpp"
#include "systems/RenderingSystem.hpp"
#include "systems/InputSystem.hpp"

#include "factories/EntityFactory.hpp"

#define WIDTH 800
#define HEIGHT 600

void keypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
    }
}

void update(int value) {
    glutPostRedisplay(); 
    glutTimerFunc(25, update, 0);
}

void resize(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, 0.0, height);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

void initialize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(1.0F);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    resize(WIDTH, HEIGHT);
}

int main(int argc, char * argv[]) {

    initialize();

    glutFullScreen();
    glutMainLoop();

    return 0;
}
