void drawMiddleBlock() {

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);

        glVertex2f(-0.2f, -0.6f);
        glVertex2f(0.2f, -0.6f);
        glVertex2f(-0.25f, 0.4f);
        glVertex2f(-0.53f, 0.1f);

    glEnd();
}