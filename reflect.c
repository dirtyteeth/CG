#include<stdio.h>
#include<graphics.h>
#include<X11/Xlib.h>

void reflectxy(int *arr, int cx, int cy, int n,int flag){
	if(flag == 1) {
		for(int i = 0; i < n; i+=2)
		arr[i] = 2*cx - arr[i];}
	else if(flag == 3){
		for(int i = 1; i < n; i+=2)
		arr[i] = 2*cy - arr[i];}
	else{
		for(int i = 0; i < n; i+=2){
			int temp = arr[i];
			arr[i] = arr[i+1] - cy + cx;
			arr[i+1] = temp - cx + cy;}}}
int main(){
	int *ln, *tr, *sq;
	ln = malloc(4*sizeof(int)); tr = malloc(8*sizeof(int)); sq = malloc(10*sizeof(int));
	printf("Enter the coordinates of line(4), triangle(8), square(10)\n");
	for(int i = 0; i < 22; i++){
		if(i < 4) scanf("%d",&ln[i]);
		else if(i >= 4 && i < 12) scanf("%d",&tr[i - 4]);
		else scanf("%d",&sq[i - 12]);}
	XInitThreads();
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int xx = getmaxx(),yy = getmaxy();
	setbkcolor(WHITE); setcolor(BLACK);
	setlinestyle(3,1,1);
	line(0,yy/2,xx,yy/2); line(xx/2,0,xx/2,yy); line(0,0,xx,yy);
	setlinestyle(0,1,1);
	for(int i = 1; i <= 3; i++){
	line(ln[0],ln[1],ln[2],ln[3]);
	drawpoly(4,tr); drawpoly(5,sq);
	reflectxy(ln,xx/2,yy/2,4,i); reflectxy(tr,xx/2,yy/2,8,i); reflectxy(sq,xx/2,yy/2,10,i);}
	line(ln[0],ln[1],ln[2],ln[3]);
	drawpoly(4,tr); drawpoly(5,sq);
	delay(500000);
	closegraph();}
	
		
	

