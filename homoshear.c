#include<graphics.h>
#include<stdio.h>
#include<X11/Xlib.h>

void mat_multiply(float **mat1,float **mat2){
	float sum[3] = {0,0,0};
	for(int k = 0; k < 3; k++){
		for(int j = 0; j < 1; j++){
			float temp = 0;
			for(int i = 0; i < 3; i++){
				temp += mat2[k][i]*mat1[i][j];
			}
			sum[k] = temp;
		}}
		for(int i = 0; i < 3; i++) mat1[i][0] = sum[i];}
int main(){
	int *tr,*sq,*tr2,*sq2;
	tr = malloc(8*sizeof(int)); sq = malloc(10*sizeof(int));
	tr2 = malloc(8*sizeof(int)); sq2 = malloc(10*sizeof(int));
	float **mat1,**mat2;
	mat1 = malloc(3*sizeof(*mat1));
	mat2 = malloc(3*sizeof(*mat2));
	for(int i = 0; i < 3; i++){
		mat1[i] = malloc(sizeof(float));
		mat2[i] = malloc(3*sizeof(float));}
	printf("Enter the coordinates of triangle(8), square(10)\n");
	for(int i = 0; i < 18; i++){
		if(i < 8) scanf("%d",&tr[i]);
		else scanf("%d",&sq[i - 8]);}
	printf("Enter the shx and shy\n");
	float shx,shy;
	scanf("%f%f",&shx,&shy);
	printf("Enter 1 for triangle and 2 for square\n");
	int flag;
	scanf("%d",&flag);
	XInitThreads();
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int xx = getmaxx(),yy = getmaxy();
	setbkcolor(WHITE); setcolor(BLACK);
	setlinestyle(3,1,1);
	line(0,yy/2,xx,yy/2); line(xx/2,0,xx/2,yy);
	setlinestyle(0,1,3);
	if(flag == 1)
			drawpoly(4,tr); 
		else
			drawpoly(5,sq);
	for(int i = 1; i <= 2; i++){
		if(i == 1){
		mat2[0][0] = 1; mat2[0][1] = shx; mat2[0][2] = -shx*yy/2; 
		mat2[1][0] = 0; mat2[1][1] = 1; mat2[1][2] = 0;
		mat2[2][0] = 0; mat2[2][1] = 0; mat2[2][2] = 1;}
		else{
		mat2[0][0] = 1; mat2[0][1] = 0; mat2[0][2] = 0; 
		mat2[1][0] = shy; mat2[1][1] = 1; mat2[1][2] = -shy*xx/2;
		mat2[2][0] = 0; mat2[2][1] = 0; mat2[2][2] = 1;}
				
		for(int j = 0; j < 8; j+=2){
			mat1[0][0] = tr[j]; mat1[1][0] = tr[j+1]; mat1[2][0] = 1;
			mat_multiply(mat1,mat2);
			tr2[j] = (int)mat1[0][0];tr2[j+1] = (int)mat1[1][0];}
		for(int j = 0; j < 10; j+=2){
			mat1[0][0] = sq[j]; mat1[1][0] = sq[j+1]; mat1[2][0] = 1;
			mat_multiply(mat1,mat2);
			sq2[j] = (int)mat1[0][0];sq2[j+1] = (int)mat1[1][0];}
		setlinestyle(i - 1,1,1);
		if(flag == 1)
			drawpoly(4,tr2); 
		else
			drawpoly(5,sq2);
	}
	delay(50000);
	closegraph();
}
