#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
int x=0,y,r, pk;
void init(void)
{
    glClearColor(1.0,1.1,1.0,1.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
    //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}
void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1 ,0, 1);
    glBegin(GL_POINTS);

    pk=(1-r);

    while(x<=y){
        if (pk<0)
        {
            x=x+1;
            y=y;
            pk=pk+(2*x)+1;
        }
        else
        {
            x=x+1;
            y=y-1;
            pk=pk+(2*x)+1-(2*y);
        }
    glVertex2i(x,y);
    glVertex2i(y,x);
    glVertex2i(x,-y);
    glVertex2i(y,-x);
    glVertex2i(-x,-y);
    glVertex2i(-y,-x);
    glVertex2i(-x,y);
    glVertex2i(-y,x);
    }
 glEnd();
// Write your Code
 glutSwapBuffers();
}
int main(int argc,char **argv)
{

    printf("Enter R value:");
    scanf("%d",&r);
    y=r;
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab 4");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
