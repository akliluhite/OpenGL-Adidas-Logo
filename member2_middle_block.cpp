#include <GL/glut.h>

float angle = 0.0f;
float scaleValue = 1.0f;
float tx = 0.0f;
float ty = 0.0f;

bool isHovered = false;

void drawLogo() {

    if (isHovered)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.6f);
        glVertex2f(0.2f, -0.6f);
        glVertex2f(-0.25f, 0.4f);
        glVertex2f(-0.53f, 0.1f);
    glEnd();
}

void display() {

    if (isHovered)
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    else
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(tx, ty, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(scaleValue, scaleValue, 1.0f);

    drawLogo();

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {

    switch (key) {

        case 'a': tx -= 0.05f; break;
        case 'd': tx += 0.05f; break;
        case 'w': ty += 0.05f; break;
        case 's': ty -= 0.05f; break;

        case 'q': angle += 5.0f; break;
        case 'e': angle -= 5.0f; break;

        case '+': scaleValue += 0.1f; break;
        case '-': scaleValue -= 0.1f; break;

        case 'r':
            angle = 0.0f;
            scaleValue = 1.0f;
            tx = 0.0f;
            ty = 0.0f;
            break;
    }

    glutPostRedisplay();
}

void passiveMotion(int mouseX, int mouseY) {

    float x = (mouseX - 300) / 300.0f;
    float y = -(mouseY - 200) / 200.0f;

    if (x > -0.8f && x < 0.8f &&
        y > -0.7f && y < 0.9f)
    {
        isHovered = true;
    }
    else {
        isHovered = false;
    }

    glutPostRedisplay();
}

void init() {
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(700, 500);

    glutCreateWindow("Middle Stripe");

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutPassiveMotionFunc(passiveMotion);

    glutMainLoop();

    return 0;
}
