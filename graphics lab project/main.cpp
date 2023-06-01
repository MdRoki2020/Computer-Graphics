#include <GL/glut.h>
#include <cmath> // Include the cmath library for cos and sin functions

float sunPositionY = 0.8; // Y position of the sun

void init(void)
{
    glClearColor(1.0, 0.0, 0.0, 0.0); // Set background color to red
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void drawTree()
{
    glColor3f(0.0, 1.0, 0.0); // Set color to green

    // Draw tree trunk
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.2);
    glVertex2f(0.35, 0.2);
    glVertex2f(0.35, 0.6);
    glVertex2f(0.3, 0.6);
    glEnd();

    // Draw tree top
    glColor3f(0.0, 0.5, 0.0); // Set color to dark green
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2, 0.6);
    glVertex2f(0.4, 0.6);
    glVertex2f(0.3, 0.8);
    glEnd();
}

void drawSun()
{
    glColor3f(1.0, 1.0, 0.0); // Set color to yellow

    // Draw sun
    int numSegments = 100;
    float radius = 0.1;
    float angle;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.8, sunPositionY); // Center point of the sun
    for (int i = 0; i <= numSegments; i++)
    {
        angle = i * 2.0f * 3.14159f / numSegments;
        glVertex2f(0.8 + radius * cos(angle), sunPositionY + radius * sin(angle));
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw tree
    drawTree();

    // Draw sun
    drawSun();

    glutSwapBuffers();
}

void update(int value)
{
    // Update sun position
    sunPositionY -= 0.01;
    if (sunPositionY < -0.1)
    {
        sunPositionY = 0.8; // Reset sun position when it reaches the bottom
    }

    glutPostRedisplay(); // Mark the window for redrawing

    // Call the update function again after 10 milliseconds
    glutTimerFunc(10, update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tree and Sun");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
