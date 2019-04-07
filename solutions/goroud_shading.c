#include<stdio.h>

int r[200][200] ={0}, g[200][200] = {0}, b[200][200] = {0};

int ma(int y[]){
	if(y[0]>y[1] && y[0]>y[2]) return 0;
	else if(y[1]>y[0] && y[1]>y[2]) return 1;
	else return 2; 
}

int mi(int y[]){
	if(y[0]<y[1] && y[0]<y[2]) return 0;
	else if(y[1]<y[0] && y[1]<y[2]) return 1;
	else return 2; 
}

int lc(int x1, int x2, int y1, int y2){
	int i, xi;
	for(i=0; i<y2-y1; i++){
		xi = x1 + (x1-x2)*(i)/(y1-y2);
		r[xi][y1+i] = r[x1][y1]+(r[x2][y2]-r[x1][y1])*(i)/(y2-y1);
		g[xi][y1+i] = g[x1][y1]+(g[x2][y2]-g[x1][y1])*(i)/(y2-y1);
		b[xi][y1+i] = b[x1][y1]+(b[x2][y2]-b[x1][y1])*(i)/(y2-y1);
	}
	return 0;
}

int gou(int x[], int y[]){
	if(y[0]<y[1]) 
		lc(x[0], x[1], y[0], y[1]);
	else
		lc(x[1], x[0], y[1], y[0]);
	if(y[2]<y[1]) 
		lc(x[2], x[1], y[2], y[1]);
	else 
		lc(x[1], x[2], y[1], y[2]);
	if(y[0]<y[2]) 
		lc(x[0], x[2], y[0], y[2]);
	else 
		lc(x[2], x[0], y[2], y[0]);
	
	int inma = ma(y), inmi = mi(y), inr = 3-inma-inmi;
	int ymax = y[inma], ymin = y[inmi], yi;

	for(yi = ymax-1; yi>=y[inr]; yi--){
		int xa = (yi-y[inma])*(x[inmi]-x[inma])/(y[inmi]-y[inma])+x[inma];
		int i, xb = (yi-y[inma])*(x[inr]-x[inma])/(y[inr]-y[inma])+x[inma];
		if(xa<xb){
			for(i=xa+1; i<xb; i++){
				r[i][yi] =  r[xa][yi]+(r[xb][yi]-r[xa][yi])*(i-xa)/(xb-xa);
				g[i][yi] =  g[xa][yi]+(g[xb][yi]-g[xa][yi])*(i-xa)/(xb-xa);
				b[i][yi] =  b[xa][yi]+(b[xb][yi]-b[xa][yi])*(i-xa)/(xb-xa);
			}
		}
		else{
			for(i=xb+1; i<xa; i++){
				r[i][yi] =  r[xb][yi]+(r[xa][yi]-r[xb][yi])*(i-xb)/(xa-xb);
				g[i][yi] =  g[xb][yi]+(g[xa][yi]-g[xb][yi])*(i-xb)/(xa-xb);
				b[i][yi] =  b[xb][yi]+(b[xa][yi]-b[xb][yi])*(i-xb)/(xa-xb);
			}
		} 
	}
	7678
	for(yi = y[inr]-1; yi>y[inmi]; yi--){
		int xa = (yi-y[inma])*(x[inmi]-x[inma])/(y[inmi]-y[inma])+x[inma];
		int i, xb = (yi-y[inr])*(x[inr]-x[inmi])/(y[inr]-y[inmi])+x[inr];
		if(xa<xb){
			for(i=gou
gouxa+1; i<xb; i++){
				r[i][yi] =  r[xa][yi]+(r[xb][yi]-r[xa][yi])*(i-xa)/(xb-xa);
				g[i][yi] =  g[xa][yi]+(g[xb][yi]-g[xa][yi])*(i-xa)/(xb-xa);
				b[i][yi] =  b[xa][yi]+(b[xb][yi]-b[xa][yi])*(i-xa)/(xb-xa);
			}
		}
		else{
			for(i=xb+1; i<xa; i++){
				r[i][yi] =  r[xb][yi]+(r[xa][yi]-r[xb][yi])*(i-xb)/(xa-xb);
				g[i][yi] =  g[xb][yi]+(g[xa][yi]-g[xb][yi])*(i-xb)/(xa-xb);
				b[i][yi] =  b[xb][yi]+(b[xa][yi]-b[xb][yi])*(i-xb)/(xa-xb);
			}
		} 
	}
	return 0;
}

int main(){
	int x[3], y[3], i, j;

	scanf("%d %d %d %d %d %d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
	scanf("%d %d %d", &r[x[0]][y[0]], &r[x[1]][y[1]], &r[x[2]][y[2]]);
	scanf("%d %d %d", &g[x[0]][y[0]], &g[x[1]][y[1]], &g[x[2]][y[2]]);
	scanf("%d %d %d", &b[x[0]][y[0]], &b[x[1]][y[1]], &b[x[2]][y[2]]);
	
	gou(x, y);

	FILE* fp; 
	fp = fopen("shading.ppm", "w");
	fprintf(fp, "P3# CREATOR: GIMP PNM Filter Version 1.1\n200 200\n200\n");
	
	for(i=0; i<200; i++){
		for(j=0; j<200; j++){
			fprintf(fp, "%d %d %d\t ", r[i][j], g[i][j], b[i][j]);
		}
		fprintf(fp, "\n");
	}	
	return 0;
}

/*50 50 100 75 100 50
200 10 50
50 200 10
10 50 200*/
