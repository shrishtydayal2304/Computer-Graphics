3)	Draw line using breshnam

Code
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
float X1,X0,Y1,Y0;
void init()
{
glClearColor(0.0,0.0,1.0,1.0); //Blue background
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,700,0,700);
}
void display(){
float x,y;
int dx,dy,end,p;
    dx = abs(X0 - X1);
      dy = abs(Y0 - Y1);
      p = 2 * dy - dx;
      if(X0 > X1)
      {
            x = X1;
            y = Y1;
            end = X0;
      }
      else
      {
            x = X0;
            y = Y0;
            end = X1;
      }
       glColor3f(0,1,0);
              glBegin(GL_POINTS);
		glVertex2f(x,y);
              glEnd(); 
      while(x < end)
      {
            x = x + 1;
            if(p < 0)
            {
                  p = p + 2 * dy;
            }
            else
            {
                  y = y + 1;
                  p = p + 2 * (dy - dx);
            }
             glColor3f(0,1,0);
              glBegin(GL_POINTS);
		glVertex2f(x,y);
              glEnd(); 
      }
    glFlush(); 
  
}
int main(int argc,char **argv)
{
	
	int a; 
	printf("Enter first point co-ordinates\n");
	printf("X0: ");
	scanf("%f",&X0);
	printf("Y0: ");
	scanf("%f",&Y0);
	printf("Enter second point co-ordinates\n");
	printf("X1: ");
	scanf("%f",&X1);
	printf("Y1: ");
	scanf("%f",&Y1);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(700,700);
glutCreateWindow("breh");
init();
glutDisplayFunc(display);
glutMainLoop();
}

 
 

