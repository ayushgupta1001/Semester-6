#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>

using namespace std;
    
void main()
{  
    clrscr();
    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    int O[2],T[2],N[2],P[2],Q[2],i;
    cout<<"Enter the coordinates x0 and y0 for the point:";
    cin>>O[0]>>O[1];
    cout<<"Enter the coordinates x1 and y1 for the point:";
    cin>>P[0]>>P[1];
    cout<<"Enter the translation for x and y axis:";
    cin>>T[0]>>T[1];
    line(O[0],O[1],P[0],P[1]);

    for(i=0;i < 2;i++)
    {
        N[i]=O[i]+T[i];
        Q[i]=P[i]+T[i];
    }

    line(N[0],N[1],Q[0],Q[1]);
    getch();
}        