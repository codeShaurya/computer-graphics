#include<stdio.h>
#include<graphics.h>
#include<math.h>

int main() {
	int gd = DETECT, gm;
	float x1 = 100, y1 = 100, x2 = 100, y2 = 200, x3 = 202, y3 = 202;
	int p1,p2;

	float a = 90.0;
	double PI=acos(-1);
	float r = PI*a/180;

	initgraph(&gd,&gm,NULL);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	int xc = (x1 + x2 + x3)/3;
	int yc = (y1 + y2 + y3)/3;
	
	float a1,b1,a2,b2,a3,b3;
	
	a1 = (x1 - xc) * cos(r) - (y1 - yc) * sin(r) + xc;
	b1 = (x1 - xc) * sin(r) + (y1 - yc) * cos(r) + yc;
	a2 = (x2 - xc) * cos(r) - (y2 - yc) * sin(r) + xc;
	b2 = (x2 - xc) * sin(r) + (y2 - yc) * cos(r) + yc;
	a3 = (x3 - xc) * cos(r) - (y3 - yc) * sin(r) + xc;
	b3 = (x3 - xc) * sin(r) + (y3 - yc) * cos(r) + yc;
	
	line(a1,b1,a2,b2);
	line(a2,b2,a3,b3);
	line(a3,b3,a1,b1);
	
	getch();
	closegraph();
	
	return 0;
}
