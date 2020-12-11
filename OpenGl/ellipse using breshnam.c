3)	Draw ellipse using breshnam
Code
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
int rx,ry;
void ellipse(int rx, int ry) 
{ 
    float dx, dy, d1, d2, x, y; 
    x = 0; 
    y = ry; 
  
    // Region 1 
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx); 
    dx = 2 * ry * ry * x; 
    dy = 2 * rx * rx * y; 

    while (dx < dy) { 
        // 4-way symmetry 
        glBegin(GL_POINTS);
        glVertex2f(x,y); 
        glVertex2f(-x,y); 
        glVertex2f(x,-y); 
        glVertex2f(-x,-y); 
	glEnd();

        if (d1 < 0) { 
            x++; 
            dx = dx + (2 * ry * ry); 
            d1 = d1 + dx + (ry * ry); 
        } 
        else { 
            x++; 
            y--; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d1 = d1 + dx - dy + (ry * ry); 
        } 
    } 

    // Region 2   
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry); 
  
    while (y >= 0) { 
  
	glBegin(GL_POINTS);
        glVertex2f(x,y); 
        glVertex2f(-x,y); 
        glVertex2f(x,-y); 
        glVertex2f(-x,-y); 
	glEnd();
  
        if (d2 > 0) { 
            y--; 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + (rx * rx) - dy; 
        } 
        else { 
            y--; 
            x++; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + dx - dy + (rx * rx); 
        } 
    } 
} 

void display()  
{  
	glClear(GL_COLOR_BUFFER_BIT);
  	glColor3f(0.5,0.5,1 );  
	glPointSize(1);  
	ellipse(rx,ry);
	glFlush();
}
int main(int argc, char** argv) 
{	
	printf("Enter the value of rx : ");
	scanf("%d",&rx);
	printf("Enter the value of ry : ");
	scanf("%d",&ry);

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600,600);
	glutInitWindowPosition (200,200);
	glutCreateWindow ("Ellipse algo");
	glClearColor(0,0,0,1);
	gluOrtho2D(-100,100,-100,100);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
