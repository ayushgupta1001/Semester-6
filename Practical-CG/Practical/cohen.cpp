#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
using namespace std;

static int TOP = 0x8, BOTTOM = 0x4, RIGHT = 0X2, LEFT = 0x1, xmin, xmax, ymin, ymax;


int getcode(int x, int y)
{
    int code = 0;
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

void main()
{
	int gd = DETECT, gm;
	initigraph(&gd, &gm, "C:\\TURBO\\BGI");
	setcolor(WHITE);
	
	cout<<"Enter MIN MAX values: ";
	cin>>xmin>>ymin>>xmax>>ymax;
	rectangle(xmin, ymin, xmax, ymax);
	
	int x1,y1,x2,y2;
	cout<<"Enter end points of line: ";
	cin>>x1>>y1>>x2>>y2;
	line(x1,y1,x2,y2);
	
	getch();
	
	int outcode1 = getcode(x1,y1);
	int outcode2 = getcode(x2,y2);
	
	int accept = 0;
	while(1)
	{
		float m = (float)(y2-y1)/(x2-x1);
		if(outcode1==0 && outcode2==0)
			{
				accept = 1;
				break;
			}
		else if((outcode1 & outcode2)!=0)
			{
				break;
			}
		else
			{
				int x,y;
				int temp;
				if(outcode1 == 0)
					temp = outcode2;
				else
					temp = outcode1;
				if(temp & TOP)
				{
					x = x1 + (ymax-y1)/m;
					y = ymax;	
				}
				
				if(temp & BOTTOM)
				{
					x = x1 + (ymin-y1)/m;
					y = ymin;
				}
				
				if(temp & RIGHT)
				{
					x = xmax;
					y = y1 + (xmax-x1)*m;
				}
				
				if(temp & LEFT)
				{
					x = xmin;
					y = y1 + (xmin-x1)*m;	
				}
				
				if(temp==outcode1)
					{
						x1 = x;
						y1 = y;
						outcode1 = getcode(x1,y1);
					}
				else
					{
						x2 = x;
						y2 = y;
						outcode2 = getcode(x2,y2);
					}
			}
	}
	
	cout<<"AFTER CLIPPLING ";
	if(accept)
		cleardevice();
		rectangle(xmin, ymin, xmax, ymax);
		setcolor(RED);
		line(x1,y1,x2,y2);
	getch();
	closegraph();	
	
}




















