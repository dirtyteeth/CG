#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#define round(a) ((int)(a+0.5))
void linedda(int xa,int ya,int xb,int yb){
       int dx=xb-xa,dy=yb-ya,steps,k;
       float xincr,yincr,x=xa,y=ya;

  if(abs(dx) > abs(dy)){
    steps=abs(dx);
  }
  else{
    steps=abs(dy);
  }

  xincr=dx/(float)steps;
  yincr=dy/(float)steps;

  putpixel(round(x),round(y),WHITE);
  for(k=0;k<steps;k++){
    x+=xincr;
    y+=yincr;
    putpixel(round(x),round(y),WHITE);
  }

}
int main(){
	  int xb=500,yb=400,xa=100,ya=100;

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	linedda(xa,ya,xb,yb);
      getch();
      closegraph();
return 0;
}

