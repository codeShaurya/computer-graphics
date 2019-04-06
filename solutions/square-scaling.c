#include<stdio.h>
#include<graphics.h>

int main(){

  int gd=DETECT,gm,x1=100,y1=100,x2=200,y2=100;
  initgraph(&gd,&gm,NULL);

  line(x1,y1,x2,y2);
  line(x1*2,y1*2,x2*2,y2*2);

  x1=200,y1=100,x2=200,y2=200;
  line(x1,y1,x2,y2);
  line(x1*2,y1*2,x2*2,y2*2);

  x1=200,y1=200,x2=100,y2=200;
  line(x1,y1,x2,y2);
  line(x1*2,y1*2,x2*2,y2*2);

  x1=100,y1=200,x2=100,y2=100;
  line(x1,y1,x2,y2);
  line(x1*2,y1*2,x2*2,y2*2);

  getch();
  return 0;
}
