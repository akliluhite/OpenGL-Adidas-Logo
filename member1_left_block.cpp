#include <GL/glut.h>

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
        glVertex2f(-0.7f, -0.6f);
        glVertex2f(-0.33f, -0.6f);
        glVertex2f(-0.55f, -0.15f);
        glVertex2f(-0.75f, -0.45f);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(700, 500);

    glutCreateWindow("Member 1 - Left Stripe");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
