 #include<graphics.h>
 #include<conio.h>
 #include<dos.h>
 #include<iostream.h>

    void line2(int x1,int y1,int x2,int y2)
    {
	int dx,dy,pk,x,y;
	if(x1==x2 && y1==y2)
	    putpixel(x1,y1,15);
	else
	{
	    dx=x2-x1;
	    dy=y2-y1;

	    if(dx>dy)
		pk=2*dx-dy;
	    else
		pk=2*dy-dx;

	    x=x1;
	    y=y1;
	    while(x<=x2)
	    {
		putpixel(x,y,15);
		if(pk<0)
		{
		    pk=pk+2*dy;

		}
		else
		{
		    y=y+1;
		    pk=pk+2*dy-2*dx;
		}
		x=x+1;
	    }
	}
    }

    void main()
    {
	int gd = DETECT;
	int gm, x1, x2, y1, y2;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	cout<<"\nEnter the co-ordinates \n";
	cout<<"\nEnter x1: ";
	cin>>x1;
	cout<<"\nEnter y1: ";
	cin>>y1;
	cout<<"\nEnter x2: ";
	cin>>x2;
	cout<<"\nEnter y2: ";
	cin>>y2;

      //	clrscr();

	line2(x1,y1,x2,y2);
	getch();
	closegraph();
    }