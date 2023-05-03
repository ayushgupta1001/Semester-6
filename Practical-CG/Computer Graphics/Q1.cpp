#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <graphics.h>

void main()
{
    clrscr();
    
    // detect and store the graphics driver preset value if present
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\TURBOC3\BGI");

    int x1, y1, x2, y2, x, y, dx, dy, pk, i = 0;

    cout << "Enter the 1st point";
    cin >> x1 >> y1;

    cout << "Enter the 2nd point";
    cin >> x2 >> y2;

    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;

    pk = (2 * dy) - dx;

    do
    {
        if (pk < 0)
        {
            pk = pk + (2 * dy);
            x++;
            putpixel(x, y, RED);
        }
        else
        {
            pk = pk + (2 * dy) - (2 * dx);
            x++;
            y++;
            putpixel(x, y, RED);
        }
        i++;
    } while (i <= dx);

    getch();
    closegraph();
}