#include<windows.h>
#include <GL/glut.h>


void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0); // Set display window colour to white

glMatrixMode(GL_PROJECTION); // Set projection parameters
gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}

void drawShapes(void)
{
glClear(GL_COLOR_BUFFER_BIT); // Clear display window

//Set colour to black

glColor3f(0.0, 0.0, 0.0);
//Adjust the point size
glPointSize(10.0);

// Draw a couple of points

//Set colour to red
glColor3f(1.0, 1.0, 0.0);

// Draw a line
glBegin(GL_POLYGON);
glVertex2i(53, 42);
glVertex2i(56, 34);
glVertex2i(59, 42);
glVertex2i(67, 45);
glVertex2i(59, 48);
glVertex2i(56, 56);
glVertex2i(53, 48);
glVertex2i(45, 45);

glEnd();


glColor3f(1.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex2i(63, 52);
glVertex2i(66, 44);
glVertex2i(69, 52);
glVertex2i(77, 55);
glVertex2i(69, 58);
glVertex2i(66, 66);
glVertex2i(63, 58);
glVertex2i(55, 55);

glEnd();


glColor3f(0.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex2i(75, 42);
glVertex2i(78, 34);
glVertex2i(81, 42);
glVertex2i(87, 45);
glVertex2i(81, 48);
glVertex2i(78, 56);
glVertex2i(75, 48);
glVertex2i(67, 45);

glEnd();

glColor3f(0.1, 1.0, 0.1);
glBegin(GL_POLYGON);
glVertex2i(64, 31);
glVertex2i(67, 23);
glVertex2i(70, 31);
glVertex2i(78, 34);
glVertex2i(70,37);
glVertex2i(67, 45);
glVertex2i(64, 37);
glVertex2i(56, 34);

glEnd();

glFlush(); // Process all OpenGL routines
}
int main(int argc, char* argv[])
{
glutInit(&argc, argv); // Initalise GLUT
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // Set display mode

glutInitWindowPosition(100, 100); // Set window position
glutInitWindowSize(350, 350); // Set window size
glutCreateWindow("An Example OpenGL Program"); // Create display window

init(); // Execute initialisation procedure
glutDisplayFunc(drawShapes); // Send graphics to display window
glutMainLoop(); // Display everything and wait

return 0;
}
