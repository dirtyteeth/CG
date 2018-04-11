#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
 double powe(double x,int y){
        double f=1;
        while(y--)
          f=f*x;
        return f;
 }
void beziercubic (int x[4], int y[4])
{
        int i;
    double t;


    for (t = 0.0; t < 1.0; t += 0.0005)
    {
        double xt = powe (1-t, 3) * x[0] + 3 * t * powe (1-t, 2) * x[1] +
                    3 * powe (t, 2) * (1-t) * x[2] + powe (t, 3) * x[3];

        double yt = powe (1-t, 3) * y[0] + 3 * t * powe (1-t, 2) * y[1] +
                    3 * powe (t, 2) * (1-t) * y[2] + powe (t, 3) * y[3];

        putpixel (xt, yt, WHITE);
    }

    for (i=0; i<4; i++)
        putpixel (x[i], y[i], YELLOW);
    return;
}
 void bezierquad (int x[4], int y[4])
{
        int i;
    double t;


    for (t = 0.0; t < 1.0; t += 0.0005)
    {
        double xt = powe (1-t, 2) * x[0] + 2 *t*(1-t) * x[1] +
                    powe (t, 2) * x[2];

        double yt = powe (1-t, 2) * y[0] + 2 *t*(1-t) * y[1] +
                    powe (t, 2) * y[2];

        putpixel (xt, yt, WHITE);
    }

    for (i=0; i<4; i++)
        putpixel (x[i], y[i], YELLOW);
    return;
}
 void bezierlinear (int x[4], int y[4])
{
        int i;
    double t;


    for (t = 0.0; t < 1.0; t += 0.0005)
    {
        double xt = (1-t) * x[0] + t*x[1];

        double yt = (1-t) * y[0] + t*y[1];

        putpixel (xt, yt, WHITE);
    }

    for (i=0; i<4; i++)
        putpixel (x[i], y[i], YELLOW);
    return;
}
void main()
{
    int x[4], y[4];
    int i;

    printf ("Enter the x- and y-coordinates of the four control points.\n");
    for (i=0; i<4; i++)
        scanf ("%d%d", &x[i], &y[i]);

 int gd = DETECT, gm;


    initgraph (&gd, &gm, "..\\bgi");

    bezierquad (x, y);
    beziercubic (x, y);
    bezierlinear (x, y);
    //{50,250},{70,200},{120,150},{150,225},{200,180};
     delay(500000);
    getch();
    closegraph();
   /* 50 250
        120 150
        150 225
        200 180
        */




}