#include<graphics.h>
#include<stdio.h>
#include<math.h>
//#include<X11/Xlib.h>

static int xmin,ymin,xmax,ymax;
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000
void Line(int x1,int y1,int x2,int y2,int color,int shift){
    setcolor(color);
    line(x1+shift,y1,x2+shift,y2);
}
void Rec(int color,int shift){
	setcolor(color);
	rectangle(xmin+shift,ymin,xmax+shift,ymax);
}
int computeCode(int x, int y){
    int code = INSIDE;
    if (x < xmin)       // to the left of rectangle
        code |= LEFT;
    else if (x > xmax)  // to the right of rectangle
        code |= RIGHT;
    if (y < ymin)       // below the rectangle
        code |= BOTTOM;
    else if (y > ymax)  // above the rectangle
        code |= TOP;
    return code;
}
void cohen_suther(int x1,int y1,int x2,int y2){
    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    // Initialize line as outside the rectangular window
   int accept = 0;
    while (1)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle
            accept = 1;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle,
            // in same region
            break;
        }
        else
        {
            // Some segment of line lies within the
            // rectangle
            int code_out;
            double x, y;
 
            // At least one endpoint is outside the 
            // rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
 
            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }
 
            // Now intersection point x,y is found
            // We replace point outside rectangle
            // by intersection point
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
         Line(x1,y1,x2,y2,3,310);
        // Here the user can add code to display the rectangle
        // along with the accepted (portion of) lines
    }
    return;
}

void Liang_Brasky(int x1,int y1,int x2,int y2)
{   
	int xx1,xx2,yy1,yy2,dx,dy,i;
    float t1,t2,p[4],q[4],temp;
    
    dx=x2-x1;
    dy=y2-y1;
    
    p[0]=-dx;
    p[1]=dx;
    p[2]=-dy;
    p[3]=dy;
    
    q[0]=x1-xmin;
    q[1]=xmax-x1;
    q[2]=y1-ymin;
    q[3]=ymax-y1;
    
    for(i=0;i<4;i++)
    {
        if(p[i]==0)
        {
            //printf("line is parallel to one of the clipping boundary");
            if(q[i]>=0)
            {
                if(i<2)
                {
                    if(y1<ymin)
                    {
                        y1=ymin;
                    }
                
                    if(y2>ymax)
                    {
                        y2=ymax;
                    }
                
                     Line(x1,y1,x2,y2,3,310);
                }
                
                if(i>1)
                {
                    if(x1<xmin)
                    {
                        x1=xmin;
                    }
                    
                    if(x2>xmax)
                    {
                        x2=xmax;
                    }
                    
                    Line(x1,y1,x2,y2,3,310);
                }
            }
        }
    }
    
    t1=0;
    t2=1;
    
    for(i=0;i<4;i++)
    {
        temp=q[i]/p[i];
        
        if(p[i]<0)
        {
            if(t1<=temp)
                t1=temp;
        }
        else
        {
            if(t2>temp)
                t2=temp;
        }
    }
    
    if(t1<t2)
    {
        xx1 = x1 + t1 * p[1];
        xx2 = x1 + t2 * p[1];
        yy1 = y1 + t1 * p[3];
        yy2 = y1 + t2 * p[3];
         Line(xx1,yy1,xx2,yy2,3,310);
    }
}
int main(){
	printf("Enter the coordinates of line:");
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("Enter the digonal coordinates of cliiping window:");
	scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
	printf("Enter correct choice\n1. Liang Barsky \n2. cohen suther land\n");
	int key;
	int gd = DETECT,gm;
	scanf("%d",&key);
	//XInitThreads();
	initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE);
	Line(x1,y1,x2,y2,3,0);
    Rec(5,0);
    setcolor(0);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    Rec(2,310);
    if(key==1) Liang_Brasky(x1,y1,x2,y2);
    else  cohen_suther(x1,y1,x2,y2);
	delay(50000);
	closegraph();
	return 0;
}
