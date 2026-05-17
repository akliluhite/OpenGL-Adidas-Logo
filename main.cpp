#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);

    // Block 1 (Left)
    glBegin(GL_QUADS);
        glVertex2f(-0.7f, -0.6f);
        glVertex2f(-0.33f, -0.6f);
        glVertex2f(-0.55f, -0.15f);
        glVertex2f(-0.75f, -0.45f);
    glEnd();

    // Block 2 (Middle)
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.6f);
        glVertex2f(0.2f, -0.6f);
        glVertex2f(-0.25f, 0.4f);
        glVertex2f(-0.53f, 0.1f);
    glEnd();

    // Block 3 (Right)
    glBegin(GL_QUADS);
        glVertex2f(0.35f, -0.6f);
        glVertex2f(0.8f, -0.6f);
        glVertex2f(0.1f, 0.9f);
        glVertex2f(-0.2f, 0.6f);
    glEnd();

    glFlush();
}

void init() {
    // Background color = white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Set coordinate system
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 400);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Adidas Logo using OpenGL");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
