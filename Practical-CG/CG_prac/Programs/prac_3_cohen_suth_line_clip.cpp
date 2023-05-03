// Cohen Sutherland Line Clipping

#include<iostream.h>
#include<conio.h>
#include<graphics.h>

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;

int x_max = 10, y_max = 8, x_min = 4, y_min = 4;

// assigning region code
int computeCode(double x, double y)
{
    int code = INSIDE;

    if (x < x_min)       
	code |= LEFT;
    else if (x > x_max)  
	code |= RIGHT;
    if (y < y_min)     
	code |= BOTTOM;
    else if (y > y_max) 
	code |= TOP;

    return code;
}
void cohenSthAlgo(double x1, double y1,
			 double x2, double y2)
{
    // region codes (P1 & P2)
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    int accept = 0;

    while (1)
    {
	if ((code1 == 0) && (code2 == 0))
	{
	    accept = 1;
	    break;
	}
	else if (code1 & code2)
	    break;
	else
	{
	    int code_out;
	    double x, y;

	    if (code1 != 0)
		code_out = code1;
	    else
		code_out = code2;

	    // y = y1 + slope * (x - x1),
	    // x = x1 + (1 / slope) * (y - y1)
	    if (code_out & TOP)
	    {
		x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
		y = y_max;
	    }
	    else if (code_out & BOTTOM)
	    {
		x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
		y = y_min;
	    }
	    else if (code_out & RIGHT)
	    {
		y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
		x = x_max;
	    }
	    else if (code_out & LEFT)
	    {
		y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
		x = x_min;
	    }

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
	cout <<"Line accepted from " << x1 << ", "
	     << y1 << " to "<< x2 << ", " << y2 << endl;
	line(x1, y1, x2, y2);
    }
    else
	cout << "Line rejected" << endl;
}

void main()
{
  clrscr();
    double px1, py1, px2, py2, left, top, right, bottom;

    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    cout<<"Enter window\'s minimum coordinates (x, y): ";
    cin>>x_min>>y_min;
    cout<<"Enter window\'s maximum coordinates (x, y): ";
    cin>>x_max>>y_max;

    cout<<"Enter initial coordinates of line (x, y): ";
    cin>>px1>>py1;
    cout<<"Enter final coordinates of line (x, y): ";
    cin>>px2>>py2;


    rectangle(x_min, y_max, x_max, y_min);
    line(px1, py1, px2, py2);

    getch();
    setcolor(RED);
    cohenSthAlgo(px1, py1, px2, py2);

  getch();
}