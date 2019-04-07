#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int r[1000][1000] = {0}, g[1000][1000] = {0}, b[1000][1000] = {0};
int xi[20];

// Source Light
int xl = 100, yl = 100, zl = 10;

// Viewer Position
int xv = 100, yv = 40, zv = 100;

void normalize(vector<double> &a)
{
    double sum = 0;
    for (int i = 0; i < a.size(); i++)
        sum += a[i] * a[i];
    sum = sqrt(sum);
    for (int i = 0; i < a.size(); i++)
        a[i] /= sum;
}

double dot(vector<double> a, vector<double> b)
{
    double ans = 0;
    for (int i = 0; i < 3; i++)
        ans += a[i] * b[i];
    return ans;
}

int lc(int x1, int y1, int x2, int y2)
{
    int i, xi;
    for (i = 0; i < y2 - y1; i++)
    {
        /*  xi = x1 + (x1 - x2) * (i) / (y1 - y2);
        r[xi][y1 + i] = r[x1][y1] + (r[x2][y2] - r[x1][y1]) * (i) / (y2 - y1);
        g[xi][y1 + i] = g[x1][y1] + (g[x2][y2] - g[x1][y1]) * (i) / (y2 - y1);
        b[xi][y1 + i] = b[x1][y1] + (b[x2][y2] - b[x1][y1]) * (i) / (y2 - y1); */
    }
    return 0;
}

int main()
{
    int n, i, j, k, dy, dx, x, y, temp;
    int gd = DETECT, gm = 0;

    int a[20][2], xi[20];
    float slope[20];
    int ymin = INT_MAX, ymax = INT_MIN;

    printf("Enter no of vertex : ");
    scanf("%d", &n);

    printf("Enter vertices in clockwise or counterclockwise: ");
    for (i = 0; i < n; i++)
    {
        printf("Enter %d vertex: ", i + 1);
        int o, p;
        cin >> o >> p;
        a[i][0] = o;
        a[i][1] = p;

        printf("Enter r, g, b colors: ", i + 1);
        cin >> r[o][p] >> g[o][p] >> b[o][p];

        if (p > ymax)
            ymax = p;

        if (p < ymin)
            ymin = p;
    }

    initgraph(&gd, &gm, NULL);
    a[n][0] = a[0][0];
    a[n][1] = a[0][1];

    for (i = 0; i < n; i++)
    {
        if (a[i + 1][1] > a[i][1])
            lc(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
        else
            lc(a[i + 1][0], a[i + 1][1], a[i][0], a[i][1]);
    }

    for (i = 0; i < n; i++)
    {
        dy = a[i + 1][1] - a[i][1];
        dx = a[i + 1][0] - a[i][0];

        if (dy == 0)
            slope[i] = 1.0;
        else if (dx == 0)
            slope[i] = 0.0;
        else if ((dy != 0) && (dx != 0))
            slope[i] = (float)dy / dx;
    }

    for (y = ymin + 1; y < ymax; y++)
    {
        k = 0;
        for (i = 0; i < n; i++)
        {
            if (((a[i][1] <= y) && (a[i + 1][1] > y)) || ((a[i][1] > y) && (a[i + 1][1] <= y)))
            {
                xi[k] = (int)(a[i][0] + ((y - a[i][1]) / slope[i]));
                k++;
            }
        }
        for (j = 0; j < k - 1; j++)
        {
            for (i = 0; i < k - 1; i++)
            {
                if (xi[i] > xi[i + 1])
                {
                    temp = xi[i];
                    xi[i] = xi[i + 1];
                    xi[i + 1] = temp;
                }
            }
        }

        setcolor(3);
        for (i = 0; i < k - 1; i += 2)
        {
            int xb = xi[i];
            int xa = xi[i + 1];
            int yi = y;

            if (xb > 0 && xb < 201 && xa > 0 && xa < 201)
            {
                for (int xx = xb + 1; xx < xa; xx++)
                {
                    /* r[xx][yi] = r[xb][yi] + (r[xa][yi] - r[xb][yi]) * (xx - xb) / (xa - xb);
                    g[xx][yi] = g[xb][yi] + (g[xa][yi] - g[xb][yi]) * (xx - xb) / (xa - xb);
                    b[xx][yi] = b[xb][yi] + (b[xa][yi] - b[xb][yi]) * (xx - xb) / (xa - xb); */

                    double yy = yi;

                    vector<double> light;

                    light.push_back(xl - xx);
                    light.push_back(yl - yy);
                    light.push_back(zl - 0);

                    normalize(light);

                    vector<double> view;
                    view.push_back(xv - xx);
                    view.push_back(yv - yy);
                    view.push_back(zv - 0);

                    normalize(view);

                    vector<double> normal;
                    normal.push_back(0);
                    normal.push_back(0);
                    normal.push_back(1);

                    normalize(normal);

                    double cur_int = 0;
                    // Ambient => FIXED
                    cur_int += 20.0;

                    // Diffused
                    double ct1 = dot(light, normal);
                    cur_int += 40.0 * ct1;

                    // Specular
                    vector<double> half(3);
                    for (int pp = 0; pp < 3; pp++)
                    {
                        half[pp] = light[pp] + view[pp];
                    }
                    normalize(half);

                    double ct2 = dot(half, normal);
                    cur_int += 200.0 * pow(ct2, 4);

                    r[xx][yi] = int(cur_int);
                }
            }
        }
    }

    FILE *fp;
    fp = fopen("pf.ppm", "w");
    fprintf(fp, "P3# CREATOR: GIMP PNM Filter Version 1.1\n200 200\n255\n");
    for (i = 0; i < 200; i++)
    {
        for (j = 0; j < 200; j++)
        {
            fprintf(fp, "%d %d %d \t", r[i][j], g[i][j], b[i][j]);
        }
        fprintf(fp, "\n");
    }

    return 0;
}

/*
50 50 
200 10 50
100 75
50 200 10
200 10
10 50 200*/

/*
5
20 100 
20 10 100
40 140
30 200 100
50 160
0 50 200
30 180
200 50 100
10 190
255 0 10
*/

/* 
3
20 10
255 0 0
180 100
0 255 0
70 180
0 0 255

*/