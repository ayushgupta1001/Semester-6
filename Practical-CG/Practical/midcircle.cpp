#include<iostream.h>
#include<graphics.h>
#include<conio.h>

void midPointCircle(int a,int b,int r){
	int x = 0;
	int y = r;
	double d = 1.0 - r;
	putpixel (a, b+r, RED);  
    putpixel (a, b-r, RED);  
    putpixel (a-r, b, RED);  
    putpixel (a+r, b, RED);  
	while(y > x)
	{
		if(d < 0)
			d += (2.0*x + 3.0);
		else
		{
			d += 2.0 *(x - y) + 5.0;
			y--;
		}
		x++;
		putpixel (a+x, b+r, RED);  
        putpixel (a-x, b+y, RED);  
        putpixel (a+x, b-y, RED; 
        putpixel (a-y, b-x, RED);  
        putpixel (a+y, b+x, RED); 
        putpixel (a+y, b-x, RED); 
        putpixel (a-y, b+x, RED);  
        putpixel (a-x, b-y, RED); 
		
	}
}

int main()
{
   int gd = DETECT,gm;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI"); 
   int h,k,r;
   cout<<"ENTER x coordinate of centre: ");
   cin>>h;
   cout<<"ENTER y coordinate of centre: ");
   cin>>k;
   cout<<"ENTER the radius of the circle: ");
   cin>>r;

   midPointCircle(h,k,r);
   getch();
   closegraph();
   return 0;
}