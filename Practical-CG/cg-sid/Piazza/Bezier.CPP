#include<stdio.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

void bezier(int x[4], int y[4])
{
    double t;
    for(t=0.0;t < 1.0;t+=0.0005)
    {
        double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
        double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
        putpixel(xt,yt,WHITE);
    }

    for(int i=0;i < 4;i++)
    putpixel(x[i],y[i],YELLOW);
    getch();
    closegraph();
    return;
}

void main()
{
    /* request auto detection */
    int gdriver = DETECT, gmode, errorcode;

    /* initialize graphics and local variables */
    initgraph(&gdriver, &gmode, "..\\bgi");

    /* read result of initialization */
    errorcode = graphresult();

    /* an error occurred */
    if (errorcode != grOk)
    {
        cout<<"Graphics error: %s\n", grapherrormsg(errorcode);
        cout<<"Press any key to halt:";
        getch();
        exit(1);
    }

    int x[4],y[4];
    int i;
    cout<<"Enter x and y coordinates"<<endl;

    for(i=0;i < 4;i++)
    {
        cin>>x[i];
        cout<<endl;
        cin>>y[i];
    }
    bezier(x,y);
}