#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
float p=-10.0;
void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  glOrtho(0, 100,0,100,0, 100);
  //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void Draw()
{
 glClear(GL_COLOR_BUFFER_BIT);
   glColor3f( 1 ,1, 0);
   glBegin(GL_QUADS);
   if(p<=100)
   p=p+0.005;
   else
   p=0;
   glutPostRedisplay ();
   glVertex2i (p+6,2);
   glVertex2i (p+13,2);
   glVertex2i (p+15,5);
   glVertex2i (p+3,5);
   glVertex2i (p+12,5);
   glVertex2i (p+12,10);
   glVertex2i (p+10,10);
   glVertex2i (p+10,5);
   glVertex2i (p+8,8);
   glVertex2i (p+10,8);
   glVertex2i (p+10,10);
   glVertex2i (p+8,8);
   glEnd();


// Write your Code


glutSwapBuffers();
}

int main(int argc,char **argv){


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
