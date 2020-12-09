Draw circle using polar equations:
Code 
 
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int xc,yc,r;
 
void display()
{
	int x,y,i;
	float theta;
	glPointSize(5.0);
	for(i=0;i<360;i++)
	{
		theta = (i*3.14)/180;
		x = (int)( xc + (r*cos(theta)) );
		y = (int)( yc + (r*sin(theta)) );
		glBegin(GL_POINTS);
		glVertex2f(x,y);
		glEnd();
		glFlush();}	
	glFlush();
}
int main(int argc, char** argv) 
{
printf("Enter the value of cordinates of circle : ");
	scanf("%d %d",&xc, &yc);
	printf("Enter the radius of circle : ");
	scanf("%d",&r);
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Circle Algorithm(using Polar Equations)");
	glClearColor(1,1,1,1);
	gluOrtho2D(0,200,0,200);
	glutDisplayFunc(display);
	glutMainLoop();
 	return 0;
}
