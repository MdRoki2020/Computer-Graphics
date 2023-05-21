#include<windows.h>
#include <GL/glut.h>


void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0); // Set display window colour to white

glMatrixMode(GL_PROJECTION); // Set projection parameters
gluOrtho2D(-0.10, 1.0, -0.10, 1.0, -10.0, 10.0);
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
glColor3f(1.0, 0.0, 0.0);

// Draw a line
glBegin(GL_POLYGON);
glVertex2i(9.00, 10.50);
glVertex2i(9.50, 9.50);
glVertex2i(10.50, 9.00);
glVertex2i(9.50, 8.50);
glVertex2i(9.00, 7.50);
glVertex2i(8.50, 8.50);
glVertex2i(7.50, 9.00);
glVertex2i(8.50, 9.50);

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
