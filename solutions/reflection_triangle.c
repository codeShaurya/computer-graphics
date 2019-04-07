#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main()
{
 int gd=DETECT,gm;
 float x1=100,y1=100,x2=100,y2=200,x3=200,y3=200;
 initgraph(&gd,&gm,NULL);
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x1,y1);
float a1,b1,a2,b2,a3,b3;
a1=-x1+450;
a2=-x2+450;
a3=-x3+450;
b1=y1;
b2=y2;
b3=y3;
line(a1,b1,a2,b2);
line(a2,b2,a3,b3);
line(a3,b3,a1,b1);
a1=x1;
a2=x2;
a3=x3;
b1=-y1+450;
b2=-y2+450;
b3=-y3+450;
line(a1,b1,a2,b2);
line(a2,b2,a3,b3);
line(a3,b3,a1,b1);
a1=y1;
b1=x1-10;
a2=y2;
b2=x2-10;
a3=y3;
b3=x3-10;
line(a1,b1,a2,b2);
line(a2,b2,a3,b3);
line(a3,b3,a1,b1);
getch();
}
