//  mid point circle drawing algorithm
#include<iostream.h>
#include<conio.h>
#include<graphics.h>

int main() {
  clrscr();
    int h, k, r, P, X, Y;
    int centerX = 319, centerY = 239;

    cout<<"Enter co-ordinates of center(h, k): ";
    cin>>h>>k;
    cout<<"Radius: ";
    cin>>r;

    clrscr();

    /////////////////////////////////////////

    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    line(319, 15, 319, 464);	// y-axis
    line(15, 239, 624, 239);	// x-axis

    centerX += h;
    centerY -= k;

    putpixel(centerX, centerY, WHITE);  // center (h, k)

    X = 0;
    Y = r;

    P = 1 - r;

    while(X<=Y) {

       /*	REFLECTIONS	*/
       //  (X`, Y`)    ............     O  -> Oct.
       putpixel(centerX+X, centerY-Y, RED);     // O1
       putpixel(centerX+X, centerY+Y, RED);     // O4
       putpixel(centerX-X, centerY-Y, RED);     // O5
       putpixel(centerX-X, centerY+Y, RED);     // O8
       //  (Y`, X`)
       putpixel(centerX+Y, centerY-X, GREEN);   // O2
       putpixel(centerX+Y, centerY+X, GREEN);   // O3
       putpixel(centerX-Y, centerY-X, GREEN);   // O6
       putpixel(centerX-Y, centerY+X, GREEN);   // O7

       if(P<0) {
	 P += 2*X + 3;
       } else {
	 P += 2*X - 2*Y + 5;
	 Y--;
       }
       X++;
    }

    //////////////////////////////////////////////////

  getch();
  closegraph();
  return 0;
}