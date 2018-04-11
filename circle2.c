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
        int r = 100;
        int x = 0,y = r;
	int d = 3 -2*r;
	setbkcolor(WHITE);
	draw_circle(xc,yc,x,y);
	while(x <= y){
		if(d < 0){
			d += 4*x + 6;
			x++;
		}
		else{
			d += 4*(x - y) + 10;
			x++;
			y--;
		}
		
		draw_circle(xc,yc,x,y);
	}
	
	delay(50000);
	closegraph();
}

