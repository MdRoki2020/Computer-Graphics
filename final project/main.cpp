#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

// Declare a global variable to store the current y-coordinate of the circle
    float centerY = 1.20f;


void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1.0, 1.0, 1.0);





    //up
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(0.5, 0.8, 1.0);
	glVertex3f(0.00f, 0.50f, 0.0f);
	glVertex3f(1.80f, 0.50f, 0.0f);
	glVertex3f(1.80f, 1.25f, 0.0f);
	glVertex3f(0.00f, 1.25f, 0.0f);

	glEnd();//End triangle coordinates





	//Red circle
    // Inside your rendering loop or update function
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0);
    float centerX = 0.45f;
    glVertex3f(centerX, centerY, 0.0f); // Center of the sun
    int numSegments = 360;
    float radius = 0.08f;
    float angle;
    for (int i = 0; i <= numSegments; i++)
    {
        angle = i * 2.0f * 3.14159f / numSegments;
        glVertex3f(centerX + radius * cos(angle), centerY + radius * sin(angle), 0.0f);
    }
    glEnd();

    // Update the centerY value to animate the vertical movement
    float speed = 0.00007f; // Adjust this value to control the speed of the animation
    centerY -= speed;

    // Reset the centerY value if it goes below a certain threshold
    if (centerY < 0.60f)
    {
        centerY = 1.20f; // Reset to the top
    }






    //down
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(0.00f, 0.00f, 0.0f);
	glVertex3f(1.80f, 0.00f, 0.0f);
	glVertex3f(1.80f, 0.50f, 0.0f);
	glVertex3f(0.00f, 0.50f, 0.0f);

	glEnd();//End triangle coordinates




    //first hill triange
	glBegin(GL_TRIANGLES);; //Begin GL_TRIANGLES coordinates
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(1.05f, 0.50f, 0.0f);
	glVertex3f(1.40f, 0.50f, 0.0f);
	glVertex3f(1.25f, 0.75f, 0.0f);
	glEnd(); //End quadrilateral coordinates



	//second hill triange
	glBegin(GL_TRIANGLES);; //Begin GL_TRIANGLES coordinates
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(1.40f, 0.50f, 0.0f);
	glVertex3f(1.63f, 0.50f, 0.0f);
	glVertex3f(1.50f, 0.70f, 0.0f);
	glEnd(); //End quadrilateral coordinates


	//third hill triange
	glBegin(GL_TRIANGLES);; //Begin GL_TRIANGLES coordinates
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(1.63f, 0.50f, 0.0f);
	glVertex3f(1.80f, 0.50f, 0.0f);
	glVertex3f(1.80f, 0.80f, 0.0f);
	glEnd(); //End quadrilateral coordinates





    //first house roof
    glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.95f, 0.46f, 0.79f, 1.0f);
	glVertex3f(0.10f, 0.65f, 0.0f);
	glVertex3f(0.45f, 0.65f, 0.0f);
	glVertex3f(0.55f, 0.70f, 0.0f);
	glVertex3f(0.10f, 0.70f, 0.0f);
	glEnd();//End triangle coordinates


	//first house quard
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.80f, 0.93f, 0.95f, 1.0f);
	glVertex3f(0.10f, 0.35f, 0.0f);
	glVertex3f(0.45f, 0.35f, 0.0f);
	glVertex3f(0.45f, 0.65f, 0.0f);
	glVertex3f(0.10f, 0.65f, 0.0f);
	glEnd();//End triangle coordinates


    //first house shadow
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(0.45f, 0.35f, 0.0f);
	glVertex3f(0.55f, 0.40f, 0.0f);
	glVertex3f(0.55f, 0.70f, 0.0f);
	glVertex3f(0.45f, 0.65f, 0.0f);
	glEnd();//End triangle coordinates


    //first house door
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.78f, 0.20f, 0.79f, 1.0f);
	glVertex3f(0.20f, 0.40f, 0.0f);
	glVertex3f(0.30f, 0.40f, 0.0f);
	glVertex3f(0.30f, 0.60f, 0.0f);
	glVertex3f(0.20f, 0.60f, 0.0f);
	glEnd();//End triangle coordinates


	//first house window
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.78f, 0.20f, 0.79f, 1.0f);
	glVertex3f(0.35f, 0.49f, 0.0f);
	glVertex3f(0.42f, 0.49f, 0.0f);
	glVertex3f(0.42f, 0.55f, 0.0f);
	glVertex3f(0.35f, 0.55f, 0.0f);
	glEnd();//End triangle coordinates






	//second house roof
    glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.95f, 0.46f, 0.79f, 1.0f);
	glVertex3f(0.55f, 0.60f, 0.0f);
	glVertex3f(0.80f, 0.60f, 0.0f);
	glVertex3f(0.85f, 0.65f, 0.0f);
	glVertex3f(0.55f, 0.65f, 0.0f);
	glEnd();//End triangle coordinates


	//second house quard
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.80f, 0.93f, 0.95f, 1.0f);
	glVertex3f(0.55f, 0.40f, 0.0f);
	glVertex3f(0.80f, 0.40f, 0.0f);
	glVertex3f(0.80f, 0.60f, 0.0f);
	glVertex3f(0.55f, 0.60f, 0.0f);
	glEnd();//End triangle coordinates



	//second house shadow
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(0.80f, 0.40f, 0.0f);
	glVertex3f(0.85f, 0.45f, 0.0f);
	glVertex3f(0.85f, 0.65f, 0.0f);
	glVertex3f(0.80f, 0.60f, 0.0f);
	glEnd();//End triangle coordinates


	//second house door
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.78f, 0.20f, 0.79f, 1.0f);
	glVertex3f(0.60f, 0.44f, 0.0f);
	glVertex3f(0.65f, 0.44f, 0.0f);
	glVertex3f(0.65f, 0.55f, 0.0f);
	glVertex3f(0.60f, 0.55f, 0.0f);
	glEnd();//End triangle coordinates


	//second house window
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.78f, 0.20f, 0.79f, 1.0f);
	glVertex3f(0.70f, 0.49f, 0.0f);
	glVertex3f(0.78f, 0.49f, 0.0f);
	glVertex3f(0.78f, 0.55f, 0.0f);
	glVertex3f(0.70f, 0.55f, 0.0f);
	glEnd();//End triangle coordinates






    //Third house roof
    glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.95f, 0.46f, 0.79f, 1.0f);
	glVertex3f(0.85f, 0.60f, 0.0f);
	glVertex3f(1.05f, 0.60f, 0.0f);
	glVertex3f(1.10f, 0.65f, 0.0f);
	glVertex3f(0.85f, 0.65f, 0.0f);
	glEnd();//End triangle coordinates

	//third house quard
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.80f, 0.93f, 0.95f, 1.0f);
	glVertex3f(0.85f, 0.45f, 0.0f);
	glVertex3f(1.05f, 0.45f, 0.0f);
	glVertex3f(1.05f, 0.60f, 0.0f);
	glVertex3f(0.85f, 0.60f, 0.0f);
	glEnd();//End triangle coordinates


	//third house shadow
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(1.05f, 0.45f, 0.0f);
	glVertex3f(1.10f, 0.50f, 0.0f);
	glVertex3f(1.10f, 0.65f, 0.0f);
	glVertex3f(1.05f, 0.60f, 0.0f);
	glEnd();//End triangle coordinates



	//third house window
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.78f, 0.20f, 0.79f, 1.0f);
	glVertex3f(0.93f, 0.50f, 0.0f);
	glVertex3f(1.00f, 0.50f, 0.0f);
	glVertex3f(1.00f, 0.55f, 0.0f);
	glVertex3f(0.93f, 0.55f, 0.0f);
	glEnd();//End triangle coordinates






//////////





    //first tree first triangle
	glBegin(GL_TRIANGLES);; //Begin GL_TRIANGLES coordinates
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.30f, 0.60f, 0.0f);
	glVertex3f(1.45f, 0.60f, 0.0f);
	glVertex3f(1.37f, 0.70f, 0.0f);
	glEnd(); //End quadrilateral coordinates

    //first tree second triangle
	glBegin(GL_TRIANGLES);; //Begin GL_TRIANGLES coordinates
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.30f, 0.65f, 0.0f);
	glVertex3f(1.45f, 0.65f, 0.0f);
	glVertex3f(1.37f, 0.75f, 0.0f);
	glEnd(); //End quadrilateral coordinates


	//first tree stand
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.79f, 0.60f, 0.80f, 1.0f);
	glVertex3f(1.35f, 0.45f, 0.0f);
	glVertex3f(1.40f, 0.45f, 0.0f);
	glVertex3f(1.40f, 0.60f, 0.0f);
	glVertex3f(1.35f, 0.60f, 0.0f);
	glEnd();//End triangle coordinates





    //second tree first triangle
	glBegin(GL_TRIANGLES);; //Begin GL_TRIANGLES coordinates
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.55f, 0.55f, 0.0f);
	glVertex3f(1.70f, 0.55f, 0.0f);
	glVertex3f(1.63f, 0.65f, 0.0f);
	glEnd(); //End quadrilateral coordinates

    //second tree second triangle
	glBegin(GL_TRIANGLES);; //Begin GL_TRIANGLES coordinates
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.55f, 0.60f, 0.0f);
	glVertex3f(1.70f, 0.60f, 0.0f);
	glVertex3f(1.63f, 0.70f, 0.0f);
	glEnd(); //End quadrilateral coordinates


	//second tree stand
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.79f, 0.60f, 0.80f, 1.0f);
	glVertex3f(1.60f, 0.45f, 0.0f);
	glVertex3f(1.65f, 0.45f, 0.0f);
	glVertex3f(1.65f, 0.55f, 0.0f);
	glVertex3f(1.60f, 0.55f, 0.0f);
	glEnd();//End triangle coordinates








/* don't wait!
* start processing buffered OpenGL routines
*/
glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.10, 1.80, 0.00, 1.25, 0.00, 10.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/


int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (800, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Lab Project");
init ();
glutDisplayFunc(display);
glutIdleFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}
