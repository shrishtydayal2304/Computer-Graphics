WAP to draw a Bezier curve.
Bezier curves are used in computer graphics to draw shapes, for CSS animation and in many other places.
They are a very simple thing, worth to study once and then feel comfortable in the world of vector graphics and advanced animations.
Control points
A bezier curve is defined by control points.
There may be 2, 3, 4 or more.
For instance, two points curve:
Three points curve:
Four points curve:
If you look closely at these curves, you can immediately notice:
1.	Points are not always on curve. That’s perfectly normal, later we’ll see how the curve is built.
2.	The curve order equals the number of points minus one. For two points we have a linear curve (that’s a straight line), for three points – quadratic curve (parabolic), for four points – cubic curve. 
Because of that last property, in computer graphics it’s possible to optimize intersection tests. If convex hulls do not intersect, then curves do not either. So checking for the convex hulls intersection first can give a very fast “no intersection” result. Checking the intersection or convex hulls is much easier, because they are rectangles, triangles and so on (see the picture above), much simpler figures than the curve.
Code

#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
void bezierCoefficients(int n,int *c)
{
	int k,i;
	for(k=0;k<=n;k++)
	{
		c[k]=1;
		for(i=n;i>=k+1;i--)
		c[k]*=i;
		for(i=n-k;i>=2;i--)
			c[k]/=i;

	}
}
/*float power(float u,int k)
{
	float temp=1;
	for(;k>0;k--)
	{
		temp*=u;
	}
	return temp;
}*/
void display()
{

	int cp[4][2]={{10,10},{100,200},{200,50},{300,300}};
int c[4],k,n=3;
float x,y,u,blend;
bezierCoefficients(n,c);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glLineWidth(5.0);
	glBegin(GL_LINE_STRIP);

	for(u=0;u<1.0;u+=0.01)
	{x=0;y=0;
		for(k=0;k<4;k++)
		{
			blend=c[k]*pow(u,k)*pow(1-u,n-k);
			x+=cp[k][0]*blend;
			y+=cp[k][1]*blend;
		}
		glVertex2f(x,y);

	}
	glEnd();
	glFlush();
}
void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
		glColor3f(1.0,0.0,0.0);
		glPointSize(5.0);
		gluOrtho2D(0.0,250.0,0.0,300.0);
}
int main(int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);

	glutCreateWindow("Bezier Curve");
	glutDisplayFunc(display);
	myinit();

	glutMainLoop();
	return 0;

}
