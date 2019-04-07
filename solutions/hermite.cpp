#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);
 double x1=10,x2=100,y1=10,y2=100;
 double slope1=.9,slope2=2.8;
 double u,x,y;
 for(u=0;u<1;u+=0.001)
{
 x=  (2*u*u*u-3*u*u+1)*x1+(-2*u*u*u+3*u*u)*x2+(u*u*u-2*u*u+u)* slope1*x1+(u*u*u-u*u)* slope2*x2;
 y = (2*u*u*u-3*u*u+1)*y1+(-2*u*u*u+3*u*u)*y2+(u*u*u-2*u*u+u)* slope1*x1+(u*u*u-u*u)* slope2*x2;
 putpixel(x,y,WHITE);
}
getch();
return 0;
}
