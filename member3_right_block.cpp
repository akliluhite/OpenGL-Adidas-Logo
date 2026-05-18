#include <GL/glut.h>

float angle = 0.0f;
float scaleValue = 1.0f;
float tx = 0.0f;
float ty = 0.0f;

bool isHovered = false;

// Expanded right block function with interactive color changes
void drawRightBlock() {
    if (isHovered)
        glColor3f(1.0f, 1.0f, 1.0f); // White when hovered
    else
        glColor3f(0.0f, 0.0f, 0.0f); // Black default

    glBegin(GL_QUADS);
        glVertex2f(0.35f, -0.6f);
        glVertex2f(0.8f, -0.6f);
        glVertex2f(0.1f, 0.9f);
        glVertex2f(-0.2f, 0.6f);
    glEnd();
}

void display() {
    if (isHovered)
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background on hover
    else
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background default

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Apply interactive transformations
    glTranslatef(tx, ty, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(scaleValue, scaleValue, 1.0f);

    drawRightBlock();

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Translation controls
        case 'a': tx -= 0.05f; break;
        case 'd': tx += 0.05f; break;
        case 'w': ty += 0.05f; break;
        case 's': ty -= 0.05f; break;

        // Rotation controls
        case 'q': angle += 5.0f; break;
        case 'e': angle -= 5.0f; break;

        // Scaling controls
        case '+': scaleValue += 0.1f; break;
        case '-': scaleValue -= 0.1f; break;

        // Reset control
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
    // Convert screen coordinates to normalized OpenGL coordinates (-1 to 1)
    float x = (mouseX - 350) / 350.0f; 
    float y = -(mouseY - 250) / 250.0f;

    // Direct bounding box check tailored for the Right Block dimensions
    if (x > -0.2f && x < 0.8f && y > -0.6f && y < 0.9f) {
        isHovered = true;
    } else {
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
    glutInitWindowSize(700, 500); // 700x500 window
    glutCreateWindow("Right Block Interaction");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(passiveMotion);
    glutMainLoop();

    return 0;
}
