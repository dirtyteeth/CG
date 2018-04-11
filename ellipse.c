#include<stdio.h>
#include<graphics.h>
#include<X11/Xlib.h>

void draw_ellipse(int xc,int yc, int x, int y){
	putpixel(xc + x,yc + y,BLACK);
	putpixel(xc + x,yc - y,BLACK);
	putpixel(xc - x,yc + y,BLACK);
	putpixel(xc - x,yc - y,BLACK);
}
int main(){
	XInitThreads();
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE);
	int ra = 100,rb = 50;
	int xc = 200,yc = 200;
	int x = 0,y = rb;	
	float p1 = rb*rb -ra*ra*rb + ra*ra/4;
	
	draw_ellipse(xc,yc,x,y);
	
	while(2*rb*rb*x <= 2*ra*ra*y){
		
			if(p1 < 0){
				x++;
				p1 += 2*rb*rb*x + rb*rb;
			}
			else{
				x++;
				y--;
				p1 += 2*rb*rb*x - 2*ra*ra*y + rb*rb;
			}
			draw_ellipse(xc,yc,x,y);
	}
	float p2 = rb*rb*(x + 0.5)*(x + 0.5) + ra*ra*(y - 1)*(y - 1) - ra*ra*rb*rb;

	while(y > 0){
			if(p2 > 0){
				y--;
				p2 += 0 - 2*ra*ra*y + ra*ra;
			}
			else{
				x++;
				y--;
				p2 += 2*rb*rb*x - 2*ra*ra*y + ra*ra;
			}
			draw_ellipse(xc,yc,x,y);
	}
	delay(50000);
	closegraph();
}
	
