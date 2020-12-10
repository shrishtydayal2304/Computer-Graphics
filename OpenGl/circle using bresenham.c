2)	Draw circle using bresenham
Code 

#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include<stdio.h>
int xc,yc,R;

void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int p,q,h;
    p = 0;
    q = R;
    h = 1-R;

  //Plot first point //
  plot_point( p, q);
  int k;
  /* Find all vertices till x=y */
  while(p < q)
  {
    p = p + 1;
    if(h < 0)
      h = h + 2*p+1;
    else
    {
      q = q - 1;
      h = h + 2*(p - q) + 1;
    }
    plot_point( p, q);
  }
  glFlush();
}

void init()
{
    glClearColor(0.364, 0.913, 0.976, 0.976);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,200,0,200);
}
int main(int argc,char** argv)
{
   
    printf("enter the co-ord. of center: ");
    scanf("%d %d",&xc,&yc);
    printf("\nenter radius of circle : ");
    scanf("%d", &R);

    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowSize(700,600);
	glutInitWindowPosition(200,200);

	glutCreateWindow("Circle Midpoint");
    init();
	glClearColor(0,0,0,0);
	glutDisplayFunc(display);
	glutMainLoop();
