Draw line using DDA
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
void display()
{
int a;
	 int dx = X1 - X0; 
         int dy = Y1 - Y0;   
    // calculate steps required for generating pixels 
         int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
         float Xinc = dx / (float) steps; 
         float Yinc = dy / (float) steps; 
         float X = X0; 
         float Y = Y0; 
         for (int i = 0; i <= steps; i++) 
          { 
              glColor3f(0,1,0);
              glBegin(GL_POINTS);
		glVertex2f(X,Y);
              glEnd(); 
             // put pixel at (X,Y) 
              X += Xinc;           // increment in x at each step 
              Y += Yinc;           
                          
}
 glFlush(); 
}
int main(int argc,char **argv)
{
	// DDA
	int a; //case counter
	
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
glutCreateWindow("DDA");
init();
glutDisplayFunc(display);
glutMainLoop();
}
