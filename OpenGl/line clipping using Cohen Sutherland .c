1)	Write an interactive program for line clipping using Cohen Sutherland line clipping algorithm.
Cohen-Sutherland algorithm divides a two-dimensional space into 9 regions and then efficiently determines the lines and portions of lines that are inside the given rectangular area.
The algorithm can be outlines as follows:-

Nine regions are created, eight "outside" regions and one 
"inside" region.

For a given line extreme point (x, y), we can quickly
find its region's four bit code. Four bit code can 
be computed by comparing x and y with four values 
(x_min, x_max, y_min and y_max).

If x is less than x_min then bit number 1 is set.
If x is greater than x_max then bit number 2 is set.
If y is less than y_min then bit number 3 is set.
If y is greater than y_max then bit number 4 is set

There are three possible cases for any given line.
1.	Completely inside the given rectangle : Bitwise OR of region of two end points of line is 0 (Both points are inside the rectangle)
2.	Completely outside the given rectangle : Both endpoints share at least one outside region which implies that the line does not cross the visible region. (bitwise AND of endpoints != 0).
3.	Partially inside the window : Both endpoints are in different regions. In this case, the algorithm finds one of the two points that is outside the rectangular region. The intersection of the line from outside point and rectangular window becomes new corner point and the algorithm repeats

Code

#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

void display();                                                 

float xmin=-100;                                      
float ymin=-100;
float xmax=100;
float ymax=100;
float xd1,yd1,xd2,yd2;               //line points  


void init(void)
{

    glClearColor(0.0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);

}

int code(float x,float y)             //  hume region code mil rha ........
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=c|2;
    if(x<xmin)c=c|1;
    return c;
}

void cohen_Line(float x1,float y1,float x2,float y2)
{
    int c1=code(x1,y1);                  // 1st point region code milega.
    int c2=code(x2,y2);                  // 2nd point region code milega .
    float m=(y2-y1)/(x2-x1);
    while((c1|c2)>0)                                                             
    {
        if((c1 & c2)>0)                             // if line is outside .....
        {
           exit(0);
        }

    float xi=x1;float yi=y1;                    
    int c=c1;
    if(c==0)                              // if line is inside.....
    {
         c=c2;
         xi=x2;
         yi=y2;
    }
    float x,y;
    if((c & 8)>0)     // idhar se sari if conditon for partially line ke liya
    {
       y=ymax;
       x=xi+ 1.0/m*(ymax-yi);
    }
    else
      if((c & 4)>0)
      {
          y=ymin;
          x=xi+1.0/m*(ymin-yi);
      }
      else
       if((c & 2)>0)
       {
           x=xmax;
           y=yi+m*(xmax-xi);
       }
       else
       if((c & 1)>0)
       {
           x=xmin;
           y=yi+m*(xmin-xi);
       }

       if(c==c1)
       {
           xd1=x;
           yd1=y;
           c1=code(xd1,yd1);
       }

       if(c==c2)
       {
           xd2=x;
           yd2=y;
           c2=code(xd2,yd2);
       }
}

 display();

}

void mykey(unsigned char key,int x,int y)       
// yha par hmne keybord function use kiya hai jo ki hme clipped line dega ...
{
    if(key=='d')
    {  
        cohen_Line(xd1,yd1,xd2,yd2);
        glFlush();
    }
}
void display()
{

   glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);

   glBegin(GL_LINE_LOOP);
   glVertex2i(xmin,ymin);
   glVertex2i(xmin,ymax);
   glVertex2i(xmax,ymax);
   glVertex2i(xmax,ymin);
   glEnd();
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);
   glVertex2i(xd1,yd1);
   glVertex2i(xd2,yd2);
   glEnd();
   glFlush();


}


int main(int argc,char** argv)
{
    printf("Enter line co-ordinates:");
    scanf("%f %f %f %f",&xd1,&yd1,&xd2,&yd2);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Clipping");
    glutDisplayFunc(display);
    glutKeyboardFunc(mykey);
    init();
    glutMainLoop();
    return 0;
} 
    
