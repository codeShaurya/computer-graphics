#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	for (int i=0;i<150;i++)
	{
		cleardevice();
		setcolor(rand()%16);
		rectangle(50+i,275,150+i,400);
		rectangle(150+i,350,200+i,400);
		circle(75+i,410,10);
		circle(175+i,410,10);
		floodfill(100+i,300,WHITE);
		floodfill(175+i,375,WHITE);
		floodfill(75+i,410,WHITE);
		floodfill(175+i,410,WHITE);
		delay(10);
	}
	getch();

	return 0;
}
