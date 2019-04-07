#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int main(){

  int gd=DETECT,gm=0;
  cout<<"Enter the number of vertices"<<endl;
  int n;
  cin>>n;
  int a[n+1][2];
  float slope[n+1];
  vector<int> xk(20);
  int ymin=INT_MAX,ymax=INT_MIN;
  for(int i=0;i<n;i++){
    int p,q;
    cin>>p>>q;
    a[i][0]=p;
    a[i][1]=q;
    if(q<ymin)
      ymin=q;
    if(q>ymax)
      ymax=q;
  }
  a[n][0]=a[0][0];
  a[n][1]=a[0][1];
  initgraph(&gd, &gm, NULL);

  for(int i=0;i<n;i++){
    int dy=a[i+1][1]-a[i][1];
    int dx = a[i + 1][0] - a[i][0];
    if(dy=0)
      slope[i]=1.0;
    if(dx=0)
      slope[i]=0.0;
    if(dy!=0&&dx!=0)
      slope[i]=(float)dx/dy;
    line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);

  }
  for(int y=ymin;y<=ymax;y++){
    int k=0;
    for (int i = 0; i < n; i++)
    {
      if (((a[i][1] <= y) && (a[i + 1][1] > y)) || ((a[i][1] > y) && (a[i + 1][1] <= y)))
      {
        xk[k] = (int)(a[i][0] + slope[i] * (y - a[i][1]));
        k++;
      }
    }
    // for(int n=0;n<k;n++){
    //   cout<<xk[n]<<" ";
    // }
    for (int j = 0; j < k - 1; j++)
    {
      for (int i = 0; i < k - 1; i++)
      {
        if (xk[i] > xk[i + 1])
        {
          int temp = xk[i];
          xk[i] = xk[i + 1];
          xk[i + 1] = temp;
        }
      }

    }
      for (int i = 0; i < k; i += 2)
      {
        line(xk[i], y, xk[i + 1], y);
        delay(100);
      }


  }

  getch();

  return 0;
}