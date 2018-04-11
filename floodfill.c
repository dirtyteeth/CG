#include<stdio.h>
#include<graphics.h>

void flood4(int x,int y,int fill,int old){
	int c=getpixel(x,y);
	if(c==old){
		putpixel(x,y,fill);
		delay(5);
		flood4(x+1,y,fill,old);
		flood4(x-1,y,fill,old);
		flood4(x,y+1,fill,old);
		flood4(x,y-1,fill,old);
}
}


int main(){
	int gd=DETECT,gm,x1,x2,y1,y2;
	int points[]={320,150,420,300,250,300,320,150};
	printf("enter the x and y coordinates for the diagonals of the rectangle: ");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	initgraph(&gd,&gm,NULL);
	rectangle(x1,y1,x2,y2);
	flood4(x1+1,y1+1,4,0);
	drawpoly(4,points);
	flood4(300,298,4,0);
	delay(10000);
	closegraph();
	return 0;
}
