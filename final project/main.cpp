#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

// Declare a global variable to store the current y-coordinate of the circle
float centerY = 1.20f;

float carX=0.10f;

float cloudX= 0.10f;



void drawOval(float cX, float cY, float rX, float rY, int numS)
{


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.5f, 0.0f);
    for (int i = 0; i <= numS; i++)
    {
        float angle = 2.0f * 3.14159f * i / numS;
        float x = cX + rX * cos(angle);
        float y = cY + rY * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}



void drawCircle(float centerX, float centerY, float radius, int numSegments)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; i++)
    {
        float angle = i * 2.0f * 3.14159f / numSegments;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}





void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1.0, 1.0, 1.0);

    //up
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(0.5f, 0.8f, 1.0f);
	glVertex3f(0.00f, 0.50f, 0.0f);
	glVertex3f(1.80f, 0.50f, 0.0f);
	glVertex3f(1.80f, 1.25f, 0.0f);
	glVertex3f(0.00f, 1.25f, 0.0f);

	glEnd();//End triangle coordinates






	//Red circle
    //Inside your rendering loop or update function
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.92f, 0.23f);  // Sun yellow color
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
    float speed = 0.00004f; // Adjust this value to control the speed of the animation
    centerY -= speed;

    // Reset the centerY value if it goes below a certain threshold
    if (centerY < 0.60f)
    {
        centerY = 1.20f; // Reset to the top
    }




    float x1=cloudX;

	// Draw cloud 1
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x1+0.15f, 1.05f, 0.05f, 100);
    drawCircle(x1+0.24f, 1.05f, 0.05f, 100);
    drawCircle(x1+0.20f, 1.10f, 0.05f, 100);


    // Draw cloud 2
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x1+0.86f, 0.95f, 0.05f, 100);
    drawCircle(x1+0.94f, 0.95f, 0.05f, 100);
    drawCircle(x1+0.90f, 1.00f, 0.05f, 100);


    cloudX+=0.00006f;
	if(cloudX>1.80){
	cloudX=0.10;
	}




    //down
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(0.00f, 0.00f, 0.0f);
	glVertex3f(1.80f, 0.00f, 0.0f);
	glVertex3f(1.80f, 0.50f, 0.0f);
	glVertex3f(0.00f, 0.50f, 0.0f);

	glEnd();//End triangle coordinates




    //Road
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(0.4f, 0.2f, 0.0f); // Brown color for road
	glVertex3f(0.10f, 0.05f, 0.0f);
	glVertex3f(1.80f, 0.05f, 0.0f);
	glVertex3f(1.80f, 0.20f, 0.0f);
	glVertex3f(0.10f, 0.20f, 0.0f);

	glEnd();//End triangle coordinates






	//line 1
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(1.0f, 1.0f, 1.0f); // White color
	glVertex3f(0.10f, 0.11f, 0.0f);
	glVertex3f(0.30f, 0.11f, 0.0f);
	glVertex3f(0.34f, 0.14f, 0.0f);
	glVertex3f(0.10f, 0.14f, 0.0f);

	glEnd();//End triangle coordinates



	//line 2
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(1.0f, 1.0f, 1.0f); // White color
	glVertex3f(0.60f, 0.11f, 0.0f);
	glVertex3f(0.85f, 0.11f, 0.0f);
	glVertex3f(0.89f, 0.14f, 0.0f);
	glVertex3f(0.65f, 0.14f, 0.0f);

	glEnd();//End triangle coordinates



	//line 3
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(1.0f, 1.0f, 1.0f); // White color
	glVertex3f(1.10f, 0.11f, 0.0f);
	glVertex3f(1.30f, 0.11f, 0.0f);
	glVertex3f(1.34f, 0.14f, 0.0f);
	glVertex3f(1.15f, 0.14f, 0.0f);

	glEnd();//End triangle coordinates



	//line 4
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(1.0f, 1.0f, 1.0f); // White color
	glVertex3f(1.55f, 0.11f, 0.0f);
	glVertex3f(1.80f, 0.11f, 0.0f);
	glVertex3f(1.80f, 0.14f, 0.0f);
	glVertex3f(1.60f, 0.14f, 0.0f);

	glEnd();//End triangle coordinates



	//signal light border
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(0.60f, 0.20f, 0.0f);
	glVertex3f(0.66f, 0.20f, 0.0f);
	glVertex3f(0.66f, 0.22f, 0.0f);
	glVertex3f(0.60f, 0.22f, 0.0f);

	glEnd();//End triangle coordinates




	//signal light stand
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(0.62f, 0.22f, 0.0f);
	glVertex3f(0.64f, 0.22f, 0.0f);
	glVertex3f(0.64f, 0.28f, 0.0f);
	glVertex3f(0.62f, 0.28f, 0.0f);

	glEnd();//End triangle coordinates



	//signal light plate
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(0.60f, 0.28f, 0.0f);
	glVertex3f(0.66f, 0.28f, 0.0f);
	glVertex3f(0.66f, 0.35f, 0.0f);
	glVertex3f(0.60f, 0.35f, 0.0f);

	glEnd();//End triangle coordinates




	//signal light 1
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
	glVertex3f(0.61f, 0.32f, 0.0f);
	glVertex3f(0.65f, 0.32f, 0.0f);
	glVertex3f(0.65f, 0.34f, 0.0f);
	glVertex3f(0.61f, 0.34f, 0.0f);

	glEnd();//End triangle coordinates




    //play ground up border
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.85f, 0.24f, 0.0f);
	glVertex3f(1.49f, 0.24f, 0.0f);
	glVertex3f(1.56f, 0.41f, 0.0f);
	glVertex3f(0.96f, 0.41f, 0.0f);

	glEnd();//End triangle coordinates


    //play ground up sub border




    //ground
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.85f, 0.25f, 0.0f);
	glVertex3f(1.50f, 0.25f, 0.0f);
	glVertex3f(1.56f, 0.40f, 0.0f);
	glVertex3f(0.95f, 0.40f, 0.0f);

	glEnd();//End triangle coordinates





	//ground circle..
	//drawOval(1.22,0.32,0.05,0.03,100);







		//Road tree stand
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
    glColor4f(0.79f, 0.60f, 0.80f, 1.0f);
    glVertex3f(0.23f, 0.05f, 0.0f);
	glVertex3f(0.27f, 0.05f, 0.0f);
	glVertex3f(0.27f, 0.20f, 0.0f);
	glVertex3f(0.23f, 0.20f, 0.0f);
	glEnd();//End triangle coordinates


    //road tree circle
    glColor3f(0.0f, 1.0f, 0.0f);  // Deep black color
    drawCircle(0.20f, 0.20f, 0.05f, 100);
    drawCircle(0.30f, 0.20f, 0.05f, 100);
    drawCircle(0.25f, 0.25f, 0.05f, 100);






    //Road tree stand
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
    glColor4f(0.79f, 0.60f, 0.80f, 1.0f);
    glVertex3f(1.57f, 0.20f, 0.0f);
	glVertex3f(1.62f, 0.20f, 0.0f);
	glVertex3f(1.62f, 0.30f, 0.0f);
	glVertex3f(1.57f, 0.30f, 0.0f);
	glEnd();//End triangle coordinates


    //road tree circle
    glColor3f(0.0f, 1.0f, 0.0f);  // Deep black color
    drawCircle(1.55f, 0.30f, 0.05f, 100);
    drawCircle(1.65f, 0.30f, 0.05f, 100);
    drawCircle(1.60f, 0.35f, 0.05f, 100);










	float x=carX;


    //car roof
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
    glColor3f(0.663f, 0.145f, 0.764f);  // Color: #a925c3 (Purple)
	glVertex3f(x+0.40f, 0.17f, 0.0f);
	glVertex3f(x+0.55f, 0.17f, 0.0f);
	glVertex3f(x+0.51f, 0.22f, 0.0f);
	glVertex3f(x+0.42f, 0.22f, 0.0f);

	glEnd();//End triangle coordinates


	//Draw car wheel 1
    glColor3f(0.1f, 0.1f, 0.1f);  // Deep black color
    drawCircle(x+0.42f, 0.12f, 0.02f, 100);


    //Draw car wheel 2
    glColor3f(0.1f, 0.1f, 0.1f);  // Deep black color
    drawCircle(x+0.54f, 0.12f, 0.02f, 100);


	//car body
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
    glColor3f(0.663f, 0.145f, 0.764f);  // Color: #a925c3 (Purple)
	glVertex3f(x+0.38f, 0.12f, 0.0f);
	glVertex3f(x+0.57f, 0.12f, 0.0f);
	glVertex3f(x+0.57f, 0.17f, 0.0f);
	glVertex3f(x+0.38f, 0.17f, 0.0f);

	glEnd();//End triangle coordinates


	//car glass 1
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
    glColor3f(0.941f, 0.929f, 0.945f);  // Color: #f0edf1 (Light Gray)
	glVertex3f(x+0.43f, 0.17f, 0.0f);
	glVertex3f(x+0.45f, 0.17f, 0.0f);
	glVertex3f(x+0.45f, 0.20f, 0.0f);
	glVertex3f(x+0.43f, 0.20f, 0.0f);

	glEnd();//End triangle coordinates


	//car glass 2
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
    glColor3f(0.941f, 0.929f, 0.945f);  // Color: #f0edf1 (Light Gray)
	glVertex3f(x+0.47f, 0.17f, 0.0f);
	glVertex3f(x+0.49f, 0.17f, 0.0f);
	glVertex3f(x+0.49f, 0.20f, 0.0f);
	glVertex3f(x+0.47f, 0.20f, 0.0f);

	glEnd();//End triangle coordinates



	//car light
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
    glColor3f(1.0f, 0.92f, 0.23f);  // Sun yellow color
	glVertex3f(x+0.57f, 0.15f, 0.0f);
	glVertex3f(x+0.59f, 0.15f, 0.0f);
	glVertex3f(x+0.59f, 0.17f, 0.0f);
	glVertex3f(x+0.57f, 0.17f, 0.0f);

	glEnd();//End triangle coordinates




	carX+=0.0001f;
	if(carX>1.80){
	carX=0.10;
	}




	//Road tree stand
	glBegin(GL_QUADS); //Begin POLOYGON coordinates
    glColor4f(0.79f, 0.60f, 0.80f, 1.0f);
    glVertex3f(0.97f, 0.05f, 0.0f);
	glVertex3f(1.02f, 0.05f, 0.0f);
	glVertex3f(1.02f, 0.20f, 0.0f);
	glVertex3f(0.97f, 0.20f, 0.0f);
	glEnd();//End triangle coordinates


    //road tree circle
    glColor3f(0.0f, 1.0f, 0.0f);  // Deep black color
    drawCircle(0.95f, 0.20f, 0.05f, 100);
    drawCircle(1.05f, 0.20f, 0.05f, 100);
    drawCircle(1.00f, 0.25f, 0.05f, 100);






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




    //01 hill triange
	glBegin(GL_TRIANGLES);; //Begin GL_TRIANGLES coordinates
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(0.60f, 0.40f, 0.0f);
	glVertex3f(0.95f, 0.55f, 0.0f);
	glVertex3f(0.85f, 0.70f, 0.0f);
	glEnd(); //End quadrilateral coordinates










    //first house roof
    glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor4f(0.95f, 0.46f, 0.79f, 1.0f);
	glVertex3f(0.10f, 0.65f, 0.0f);
	glVertex3f(0.45f, 0.65f, 0.0f);
	glVertex3f(0.55f, 0.70f, 0.0f);
	glVertex3f(0.10f, 0.70f, 0.0f);
	glEnd();//End triangle coordinates


	//first house border1
    glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(0.4078f, 0.4431f, 0.4431f);

	glVertex3f(0.10f, 0.65f, 0.0f);
	glVertex3f(0.45f, 0.65f, 0.0f);
	glVertex3f(0.45f, 0.67f, 0.0f);
	glVertex3f(0.10f, 0.67f, 0.0f);
	glEnd();//End triangle coordinates


	//first house border2
    glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(0.4078f, 0.4431f, 0.4431f);

	glVertex3f(0.45f, 0.65f, 0.0f);
	glVertex3f(0.55f, 0.70f, 0.0f);
	glVertex3f(0.55f, 0.72f, 0.0f);
	glVertex3f(0.45f, 0.67f, 0.0f);
	glEnd();//End triangle coordinates


	//first house border3
    glBegin(GL_QUADS); //Begin POLOYGON coordinates
	glColor3f(0.4078f, 0.4431f, 0.4431f);

	glVertex3f(0.10f, 0.70f, 0.0f);
	glVertex3f(0.55f, 0.70f, 0.0f);
	glVertex3f(0.55f, 0.72f, 0.0f);
	glVertex3f(0.10f, 0.72f, 0.0f);
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

	//first tree third triangle
	glBegin(GL_TRIANGLES);; //Begin GL_TRIANGLES coordinates
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.30f, 0.70f, 0.0f);
	glVertex3f(1.45f, 0.70f, 0.0f);
	glVertex3f(1.37f, 0.80f, 0.0f);
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


	//second tree third triangle
	glBegin(GL_TRIANGLES);; //Begin GL_TRIANGLES coordinates
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.55f, 0.65f, 0.0f);
	glVertex3f(1.70f, 0.65f, 0.0f);
	glVertex3f(1.63f, 0.75f, 0.0f);
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
