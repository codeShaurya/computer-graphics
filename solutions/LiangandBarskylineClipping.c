#include<stdio.h>
#include<graphics.h>
float xmin=100,ymin=100,xmax=250,ymax=250;
float min(float a,float b)
{
   if(a<b)
return a;
else return b;
}
float max(float a,float b)
{
   if(a>b)
return a;
else return b;
}
void clipping(float x1,float y1,float x2,float y2)
{
    rectangle(xmin,ymin,xmax,ymax);
   int i;
   float dx=x2-x1;
   float dy=y2-y1;
   float p[5],q[5],r[5];
p[0]=-dx;
q[0]=x1-xmin;
p[1]=dx;
q[1]=xmax-x1;
p[2]=-dy;
q[2]=y1-ymin;
p[3]=dy;
q[3]=ymax-y1;
float u1=0,u2=1;
for(i=0;i<4;i++)
{
  if(p[i]==0 && q[i]<0)
  {
    printf("discarded\n");
  // return;
  } 
  else
  {
	if(p[i]<0)
	{
	    r[i]=q[i]/p[i];
	     u1=max(max(0,r[i]),u1);
	}
	if(p[i]>0)
	{
	 r[i]=q[i]/p[i];
	 u2=min(min(1,r[i]),u2);

	}
}
}

	if(u1>u2){
	printf("Eliminate the line as it is completely outside the window\n");
	}
	else if(u1==0)
	{
	x2 =x1 +(u2*dx);
	y2=y1+(u2*dy);
	printf("intersection pt1 are (%f %f), (%f %f)\n",x1,y1,x2,y2);
	//line(x1,y1,x2,y2);
       // return;
	}

	else
	{
	 float xx,yy;
	 xx=x1+(u1*dx);
	 yy=y1+(u1*dy);
	 x1=-x1+(u2*dx);
	 y1=y1+(u2*dy);
	 printf("intersection pt2 are (%f %f), (%f %f)\n",x1,y1,x2,y2);
	 
         //return;
	}
line(x1,y1,x2,y2);
}

void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);
 float x1=120,x2=300,y1=120,y2=300;
 clipping(x1,y1,x2,y2);
 getch();
}

