#include<stdio.h>
#include<graphics.h>
void midpointellipse(int xc,int yc,int rx,int ry)
{
  int x=0,y=ry;
  float p=(ry*ry)+((1/4)*rx*rx)-(rx*rx*ry);
  float pp;
//putpixel(xc+x,yc-y,WHITE);
  while(2*ry*ry*x<2*rx*rx*y)
{
putpixel(xc+x,yc+y,WHITE);
  putpixel(xc+x,yc-y,WHITE);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc-x,yc-y,WHITE);
	 x++;
	 if(p<0)
	{
	 p+=(2*ry*ry*x)+(ry*ry);
	}
	else
	{
	 y--;
	 p+=(2*ry*ry*x)-(2*rx*rx*y)+(ry*ry);
	}
//putpixel(x,y,WHITE);

}
pp=((ry*ry)*(x+0.5)*(x+0.5))+((rx*rx)*(y-1)*(y-1))-(rx*rx*ry*ry);
while( 2*ry*ry*x>=2*rx*rx*y &&y>=0)
{
putpixel(xc+x,yc+y,WHITE);
putpixel(xc+x,yc-y,WHITE);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc-x,yc-y,WHITE);
 if(pp<0)
{
 y++;
 pp-=(2*rx*rx*y)+(rx*rx);
}
else
{
 x++;
 y--;
 pp+=(2*ry*ry*x)-(2*rx*rx*y)+(rx*rx);

}
//putpixel(x,y,WHITE);
}
}
int main()
{
 int gd=DETECT,gm,rx=40,ry=20,x0=80,y0=50;
initgraph(&gd,&gm,NULL);
 midpointellipse(x0,y0,rx,ry);
 delay(10000);
 //closegraph();
 return 0;
}
