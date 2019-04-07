#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main()
{
   cout<< "Enter two points" << endl;
   int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  cout<< "enter the slope of two points" << endl;
    int m1,m2; cin>>m1>>m2;
    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL); 
    for(int i=0;i<=1000;i++)
    {
        float u = 0.001*i;
       int x = (2*u*u*u-3*u*u+1)*x1+(-2*u*u*u+3*u*u)*x2+(u*u*u-2*u*u+u)* m1*x1+(u*u*u-u*u)* m2*x2;
     int y = (2*u*u*u-3*u*u+1)*y1+(-2*u*u*u+3*u*u)*y2+(u*u*u-2*u*u+u)* m1*y1+(u*u*u-u*u)* m2*ys2;
   putpixel(x,y,WHITE);
   
   }
   delay(1000);
  return 0;
}
