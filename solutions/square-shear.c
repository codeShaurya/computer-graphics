#include<stdio.h>
#include<graphics.h>

int main() {
	int gd=DETECT, gm;
	int x1=100, y1=100, x2=200, y2=100, x3=200, y3=200, x4=100, y4=200;
	initgraph(&gd, &gm, NULL);
	
	line(x1, y1, x2, y2);
	x3 = x3 + 2 * y3;
	
	line(x2, y2, x3, y3);
	x4 = x4 + 2 * y4;
	
	line(x3, y3, x4, y4);
	
	line(x4, y4, x1, y1);
	
	getch();
    return 0;
}
