#include<stdio.h>
#include<graphics.h>

void dda(int x1, int y1, int x2, int y2) {
	int dx = x2-x1;
	int dy = y2-y1;

 	int po = (2 * dy) - dx;
	int X = x1, Y = y1;

	int i;
	for(i=1; i<dx; i++){
		if(po < 0){
			X ++;
			po = po + (2 * dy);
		}
		else {
			X ++;
			Y ++;
		 	po = po + (2 * dy) - (2 * dx);
		}
		putpixel(X,Y,WHITE);
	}
}
	
int main(){
 	int gd = DETECT, gm ,x1=2, x2=100, y1=5, y2=100, xfac=100, yfac=50;
 	initgraph(&gd, &gm, NULL);

	dda(x1,y1,x2,y2);
	dda(x1+xfac,y1+yfac,x2+xfac,y2+yfac);

	getch();
	closegraph();

	return 0;
}
