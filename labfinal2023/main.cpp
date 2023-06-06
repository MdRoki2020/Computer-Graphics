#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

void drawCircle(float cx, float cy, float radius, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}



void display(void)
{
    /* clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT);

    /* draw white polygon (rectangle) with corners at
     * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
     */



     // 1
    glColor3f(0.94f, 0.06f, 0.81f);
    drawCircle(0.37f, 0.43f, 0.07f, 100);

    // 2
    glColor3f(0.94f, 0.06f, 0.81f);
    drawCircle(0.23f, 0.43f, 0.07f, 100);

    // Draw emoji
    glColor3f(1.0f, 1.0f, 0.0f);  // Color: Yellow
    drawCircle(0.30f, 0.45f, 0.05f, 100);



    // eye 2
    glColor3f(1.0f, 1.0f, 1.0f);  // Color: white
    drawCircle(0.33f, 0.50f, 0.03f, 100);


    // eye 1
    glColor3f(1.0f, 1.0f, 1.0f);  // Color: white
    drawCircle(0.27f, 0.50f, 0.03f, 100);



    // eye 2 irish
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.33f, 0.50f, 0.01f, 100);


    // eye 1 irish
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.27f, 0.50f, 0.01f, 100);


    glColor3f(00.f, 0.0f, 1.0f);
    drawCircle(0.37f, 0.40f, 0.02f, 100);

    // 2
    glColor3f(0.0f, 0.0f, 1.0f);
    drawCircle(0.23f, 0.40f, 0.02f, 100);






    glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.27f, 0.30f, 0.0f);
	glVertex3f(0.33f, 0.30f, 0.0f);
	glVertex3f(0.33f, 0.45f, 0.0f);
	glVertex3f(0.27f, 0.45f, 0.0f);

	glEnd();//End triangle coordinates


	// end
    glColor3f(1.0f, 1.0f, 0.0f);  // Color: Yellow
    drawCircle(0.30f, 0.30f, 0.03f, 100);


    //glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);   // Ocean blue color for the water

    glVertex2f(0.27,0.43);
    glVertex2f(0.33,0.43);
    glEnd();









    /* don't wait!
    * start processing buffered OpenGL routines
    */
    glFlush();
}

void init(void)
{
    /* select clearing (background) color */
    glClearColor(0.0, 0.0, 1.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 0.70, 0, 0.70, 0, 10.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("roki");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
