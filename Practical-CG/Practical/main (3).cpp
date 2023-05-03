#include<iostream>
#include <stdio.h>
#include<conio.h>
#include<graphics.h>
using namespace std;

typedef unsigned int outcode;

enum { TOP = 0x8, BOTTOM = 0x4, RIGHT = 0X2, LEFT = 0x1};


outcode CompOutCode(double x, double y, double xmin, double xmax, double ymin, double ymax)
{
    outcode code = 0;
    if(y > ymax)
	code = code | TOP;
    else if(y < ymin)
	code = code | BOTTOM;
    if(x > xmax)
	code = code | RIGHT;
    else if(x < xmin)
	code = code | LEFT;
    return code;
}

void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1, double xmin, double xmax, double ymin, double ymax)
{
    outcode outcode0, outcode1, outcodeOut;
    int accept = 0;
    int done = 0;
    outcode0 = CompOutCode(x0,y0,xmin,xmax,ymin,ymax);
    outcode1 = CompOutCode(x1,y1,xmin,xmax,ymin,ymax);

    do{
	if(!(outcode0 | outcode1)) //TRIVIALLY ACCEPT AND EXIT
	{
	    accept = 1;
	    done = 1;
	}
	else if( outcode0 & outcode1){
	    done = 1;    //TRIVIAL REJECT AND EXIT
	}
	else{
	    double x,y;

	    outcodeOut = outcode0 ? outcode0 : outcode1;

	    if(outcodeOut & TOP) 
	    {
		x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
		y = ymax;
	    }
	    else if(outcodeOut & BOTTOM)
	    {
		x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
		y = ymin;
	    }
	    else if(outcodeOut & RIGHT)
	    {
		y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
		x = xmax;
	    }
	    else
	    {
		y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
		x = xmin;
	    }

	    if(outcodeOut == outcode0)
	    {
		x0 = x;
		y0 = y;
		outcode0 = CompOutCode(x0,y0,xmin,xmax,ymin,ymax);
	    }
	    else
	    {
		x1 = x;
		y1 = y;
		outcode1 = CompOutCode(x1,y1,xmin,xmax,ymin,ymax);
	    }
	}

	}while(done == 0);

	if(accept)
	{
		setcolor(GREEN);
		line(x0,y0,x1,y1);
	}
	    
}


int main()
{
    int gd = DETECT,gm,x0,y0,x1,y1;
    cout<<"Enter the coordinates of Lines:\n";
    cout<<"Enter x0: ";
    cin>>x0;
    cout<<"Enter y0: ";
    cin>>y0;
    cout<<"Enter x1: ";
    cin>>x1;
    cout<<"Enter y1: ";
    cin>>y1;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    rectangle(100,200,400,400);
    char str[10];
    sprintf(str, "(%d,%d)", x0, y0);
    outtextxy(x0-2*textheight(str), y0-2*textheight(str), str);
    sprintf(str, "(%d,%d)", x1, y1);
    outtextxy(x1+textheight(str), y1+textheight(str), str);
    setcolor(RED);
	line(x0,y0,x1,y1);
    CohenSutherlandLineClipAndDraw(x0,y0,x1,y1,100,400,200,400);
    getch();
    closegraph();
    return 0;
}

