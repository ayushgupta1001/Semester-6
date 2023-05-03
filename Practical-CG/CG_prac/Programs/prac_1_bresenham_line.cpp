//  bresenham's line drawing algorithm

#include<iostream.h>
#include<conio.h>
#include<graphics.h>

int main() {
  clrscr();
     int gd = DETECT,gm;
     initgraph(&gd,&gm,"C:\\TC\\BGI");

     int begX, begY, endX, endY, dx, dy;
     int x, y, P, i;

     cout<<"Enter co-ordinate of first point: ";
     cin>>begX>>begY;
     cout<<"Enter co-ordinate of second point: ";
     cin>>endX>>endY;

     x = begX;
     y = begY;

     dx = endX-begX;
     dy = endY-begY;

     i=0;
     P = 2*dy - dx;

     ////////////////////////////////////////////////

     line(20, 25, 20, 454); //x-axis
     line(15, 449, 619, 449); //y-axis

     ////////////////////////////////////////////////

     // if end poient ain't to be considered, put  (i<dx)
     while(i<=dx) {
       putpixel(20+x, 449-y, GREEN);
       if(P<0) {
	 x++;
	 P += 1 + 2*dy;
       } else {
	 x++;
	 y++;
	 P += 2*dy - 2*dx;
       }
       i++;
     }

  getch();
  return 0;
}