#include<iostream>
#include<conio.h>
#include<graphics.h>

using namespace std;

void main() {
	int gd = DETECT, gm;
	int poly[12] = {350, 450, 350, 410, 430, 400, 350, 350, 300, 430, 350, 450};
	initgraph(&gd, &gm, "");
	line(100, 250, 540, 250);
	getch();
	closegraph();
}
