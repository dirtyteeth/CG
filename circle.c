#include<stdio.h>
#include<graphics.h>
#include<X11/Xlib.h>
void draw_circle(int xc,int yc,int x,int y){
	putpixel(xc + x,yc + y,BLACK);
	putpixel(xc + x,yc - y,BLACK);
	putpixel(xc - x,yc + y,BLACK);
	putpixel(xc - x,yc - y,BLACK);
	putpixel(xc + y,yc + x,BLACK);
	putpixel(xc + y,yc - x,BLACK);
	putpixel(xc - y,yc + x,BLACK);
	putpixel(xc - y,yc - x,BLACK);
}

int main(){
	XInitThreads();
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int xc = 200,yc = 200;
	int r = 50;
	int x = 0,y = r;
	float p = 5/4.0 -r;
	setbkcolor(WHITE);
	draw_circle(xc,yc,x,y);
	while(x <= y){
		if(p < 0){
			x++;
			p = p + 2*x + 1;
		}
		else{
			x++;
			y--;
			p = p + 2*x + 1 -2*y;
		}
		draw_circle(xc,yc,x,y);
	}
	delay(5000);
	closegraph();
} 
	

