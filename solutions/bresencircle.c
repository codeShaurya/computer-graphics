#include<stdio.h>
#include<graphics.h>
void plotpoint(int x0,int y0,int x,int y)
{
 putpixel(x0+x,y0+y,WHITE);
putpixel(x0-x,y0+y,WHITE);
putpixel(x0+x,y0-y,WHITE);
putpixel(x0-x,y0-y,WHITE);
putpixel(x0+y,y0+x,WHITE);
putpixel(x0-y,y0+x,WHITE);
putpixel(x0+y,y0-x,WHITE);
putpixel(x0-y,y0-x,WHITE);

}
void bresencircle(int x0,int y0,int r)
{
int p=1-r;
int x=0;
int y=r;
plotpoint(x0,y0,x,y);
while(x<y)
{
  x++;
  if(p<0)
  p+=2*x+1;	
  else{
  y--;
  p+=2*(x-y)+1;
}
 plotpoint(x0,y0,x,y);

}


}
int main()
{
 int gd=DETECT,gm,r=10,x0=50,y0=30;
initgraph(&gd,&gm,NULL);
 bresencircle(x0,y0,r);
 delay(1000);
 //closegraph();
 return 0;



}
