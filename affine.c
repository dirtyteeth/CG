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
	int *ln, *tr, *sq;
	ln = malloc(4*sizeof(int)); tr = malloc(8*sizeof(int)); sq = malloc(10*sizeof(int));
	float **mat1,**mat2;
	mat1 = malloc(3*sizeof(*mat1));
	mat2 = malloc(3*sizeof(*mat2));
	for(int i = 0; i < 3; i++){
		mat1[i] = malloc(sizeof(float));
		mat2[i] = malloc(3*sizeof(float));}
	printf("Enter the coordinates of line(4), triangle(8), square(10)\n");
	for(int i = 0; i < 22; i++){
		if(i < 4) scanf("%d",&ln[i]);
		else if(i >= 4 && i < 12) scanf("%d",&tr[i - 4]);
		else scanf("%d",&sq[i - 12]);}
	printf("Enter the affine transformation matrix\n");
		for(int i = 0; i < 6; i++)
			scanf("%f",&mat2[i/3][i%3]);
		mat2[2][0] = 0; mat2[2][1] = 0; mat2[2][2] = 1;
	printf("Enter 1 for line 2 for triangle 3 for square\n");
	int check;
	scanf("%d",&check);
	XInitThreads();
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE); setcolor(BLACK);
	if(check == 1){
	line(ln[0],ln[1],ln[2],ln[3]);
	for(int j = 0; j < 4; j+=2){
	mat1[0][0] = ln[j]; mat1[1][0] = ln[j+1]; mat1[2][0] = 1;
	mat_multiply(mat1,mat2);
	ln[j] = mat1[0][0];ln[j+1] = mat1[1][0];}
	line(ln[0],ln[1],ln[2],ln[3]);}
	else if(check == 2){
	drawpoly(4,tr);				
	for(int j = 0; j < 8; j+=2){
	mat1[0][0] = tr[j]; mat1[1][0] = tr[j+1]; mat1[2][0] = 1;
	mat_multiply(mat1,mat2);
	tr[j] = mat1[0][0];tr[j+1] = mat1[1][0];}
	drawpoly(4,tr);}
	else{
	drawpoly(5,sq);
	for(int j = 0; j < 10; j+=2){
	mat1[0][0] = sq[j]; mat1[1][0] = sq[j+1]; mat1[2][0] = 1;
	mat_multiply(mat1,mat2);
	sq[j] = mat1[0][0];sq[j+1] = mat1[1][0];}
	drawpoly(5,sq);}
	delay(50000);
	closegraph();
}

