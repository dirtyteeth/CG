#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void linebres(int xa,int ya,int xb,int yb){
	int dx=abs(xa-xb),dy=abs(ya-yb);
	int p=2*dy-dx;
	int twody=2*dy,twodyx=2*(dy-dx);
	int x,y,xend;

	if(xa>xb){
	    x=xb;
	    y=yb;
	    xend=xa;
	}
	else{
	    x=xa;
	    y=ya;
	    xend=xb;
	}
	putpixel(x,y,WHITE);
	while(x<xend){
		x++;
		if(p<0)
		   p+=twody;
		else{
			y++;
			p+=twodyx;
		}
	putpixel(x,y,WHITE);
	}
}

int main(){
	int xa=100,xb=400,ya=100,yb=300;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	linebres(xa,ya,xb,yb);
       //	closegraph();
  getch();
return 0;
}
