#include<iostream>
#include<graphics.h>
using namespace std;

void drawcar(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5,
 int x6, int y6, int cx1, int cy1, int cx2, int cy2, int r, int left, int top, int right, 
 int bottom){

	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x4, y4);
	line(x2, y2, x5, y5);
	line(x3, y3, x6, y6);

	rectangle(left, top, right, bottom);	
	circle(cx1, cy1, r);
	circle(cx2, cy2, r);
	
	line(0,200,640,200);
	
}

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "");

	drawcar(33, 170, 50, 152, 80, 152, 100, 170, 50, 170, 80, 170,45, 192, 85, 192, 8, 25, 170, 105, 184);

	for (int i = 0; i < 490; i += 2){
		drawcar(33 + i, 170, 50 + i, 152, 80 + i, 152, 100 + i, 170, 50 + i, 170, 80 + i, 170,45 + i, 192, 85 + i, 192, 8, 25 + i, 170, 105 + i, 184);
		delay(10);

		if (i == 478)
			break;
		cleardevice();
	}

	getch();
	closegraph();
	return 0;
}

