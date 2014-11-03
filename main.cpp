#ifdef __APPLE__
#   include <OpenGL/gl.h>
#   include <OpenGL/glu.h>
#   include <GLUT/glut.h>
#else
#   include <GL/gl.h>
#   include <GL/glu.h>
#   include <GL/glut.h>
#endif

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // shit goes here!

    glFlush();
}

void initialize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(6.0F);
    glColor3f(1.0F, 1.0F, 1.0F);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("asteroids");
    glutFullScreen();
    glutDisplayFunc(display);
    initialize();
    glutMainLoop();
    return 0;
}
