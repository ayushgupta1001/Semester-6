#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void drawline(int x1,int y1,int x2,int y2)
{
   int x,y,dx,dy,d;
   dx=x2-x1;
   dy=y2-y1;
   d=2*dy-dx;
   x=x1;
   y=y1;
   if(x1==x2 && y1==y2)
     putpixel(x,y,15);
   else
   {
     while(x<=x2)
     {
       putpixel(x,y,15);
       if(d<0)
	 d=d+2*dy;
       else{
	 d=d+2*dy-2*dx;
	 y++;}
       x++;
     }
   }
  }



void main()
{
  int gd = DETECT,gm;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  int x1,y1,x2,y2;
  cout<<"Enter x1 and y1 "<<endl;
  cin>>x1>>y1;
  cout<<"Enter x2 and y2 "<<endl;
  cin>>x2>>y2;
  drawline(x1,y1,x2,y2);
  getch();
  closegraph();
}