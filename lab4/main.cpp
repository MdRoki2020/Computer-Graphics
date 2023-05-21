#include<windows.h>
#include<stdio.h>
#include <GL/glut.h>
int x1,y1,x2,y2,pk,dy,dx,step;

void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0); // Set display window colour to white

glMatrixMode(GL_PROJECTION); // Set projection parameters
gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void drawShapes(void)
{
glClear(GL_COLOR_BUFFER_BIT); // Clear display window

//Set colour to black

glColor3f(1.0, 0.0, 0.0);
dy=(y2-y1);
dx =(x2-x1);
pk=((2*dy)-dx);
if(dx>dy){
step = dx;
}
else{
step = dy;

}
int x =x1,y=y1;
glBegin(GL_POINTS);
glVertex2i(x,y);

for( int i=0;i<step;i++){

if(pk<0){
 x = x+1;
 y=y;
 glVertex2i(x,y);
 pk=pk+(2*dy);

}
else{

  x=x+1;
  y=y+1;
  glVertex2i(x,y);
  pk= pk+(2*dy)-(2*dx);

}

}



glEnd();
glFlush(); // Process all OpenGL routines
}
int main(int argc, char  **argv)
{

    printf("Enter x1 value ");
    scanf("%d",&x1);
     printf("Enter y1 value ");
    scanf("%d",&y1);
     printf("Enter x2 value ");
    scanf("%d",&x2);
     printf("Enter y2 value ");
    scanf("%d",&y2);
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
