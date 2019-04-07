#include<iostream> 
#include<graphics.h>
using namespace std; 
const int MAXPOINTS = 20; 
int x_int(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
{ 
int num = (x1*y2 - y1*x2) * (x3-x4) - (x1-x2) * (x3*y4 - y3*x4); 
int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4); 
return num/den; 
} 
int y_int(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
{ 
int num = (x1*y2 - y1*x2) * (y3-y4) - (y1-y2) * (x3*y4 - y3*x4); 
int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4); 
return num/den; 
} 
void clip(int polypoints[][2], int &polysize, int x1, int y1, int x2, int y2) 
{ 
int newpoints[MAXPOINTS][2], newpolysize = 0; 
for (int i = 0; i < polysize; i++) 
{ 
int k = (i+1) % polysize; 
int ix = polypoints[i][0], iy = polypoints[i][1]; 
int kx = polypoints[k][0], ky = polypoints[k][1]; 
int ipos = (x2-x1) * (iy-y1) - (y2-y1) * (ix-x1); 
int kpos = (x2-x1) * (ky-y1) - (y2-y1) * (kx-x1); 
if (ipos < 0 && kpos < 0) 
{ 
newpoints[newpolysize][0] = kx; 
newpoints[newpolysize][1] = ky; 
newpolysize++; 
} 

else if (ipos >= 0 && kpos < 0) 
{ 
newpoints[newpolysize][0] = x_int(x1, y1, x2, y2, ix, iy, kx, ky); 
newpoints[newpolysize][1] = y_int(x1, y1, x2, y2, ix, iy, kx, ky); 
newpolysize++; 
newpoints[newpolysize][0] = kx; 
newpoints[newpolysize][1] = ky; 
newpolysize++; 
} 

else if (ipos < 0 && kpos >= 0) 
{ 

newpoints[newpolysize][0] = x_int(x1, y1, x2, y2, ix, iy, kx, ky); 
newpoints[newpolysize][1] = y_int(x1, y1, x2, y2, ix, iy, kx, ky); 
newpolysize++; 
}  
} 
polysize = newpolysize; 
for (int i = 0; i < polysize; i++) 
{ 
polypoints[i][0] = newpoints[i][0]; 
polypoints[i][1] = newpoints[i][1]; 
} 
} 
void suthHodgClip(int polypoints[][2], int polysize, int clippoints[][2], int clippersize) 
{ 
for (int i=0; i<clippersize; i++) 
{ 
int k = (i+1) % clippersize; 
clip(polypoints, polysize, clippoints[i][0], clippoints[i][1], clippoints[k][0], clippoints[k][1]); 
} 

for (int i=0; i <polysize; i++) 
{
int k=(i+1)%polysize;

line(polypoints[i][0],polypoints[i][1],polypoints[k][0],polypoints[k][1]);
}
} 
int main() 
{ 
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
int polysize = 3; 
int polypoints[20][2] = {{100,150}, {200,250}, {300,200}}; 
line(200,150,300,250);
line(300,250,400,200);
line(400,200,200,150);
int clippersize = 4; 
int clippoints[][2] = {{150,150}, {150,200}, {200,200}, {200,150} }; 
rectangle(150+100,150,200+100,200);
suthHodgClip(polypoints, polysize, clippoints, clippersize);
getch(); 
return 0; 
} 

