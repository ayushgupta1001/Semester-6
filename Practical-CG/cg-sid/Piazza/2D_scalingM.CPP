#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>

using namespace std;

void main()
{  
    clrscr();
    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    int O[2],S[2][2],N[2],P[2],Q[2],i,j,k;
    cout<<"Enter the coordinates x0 and y0 for the point:";
    cin>>O[0]>>O[1];
    cout<<"Enter the coordinates x1 and y1 for the point:";
    cin>>P[0]>>P[1];
    cout<<"Enter the scaling for x and y axis:";
    cin>>S[0][0]>>S[1][1];
    S[0][1]=S[1][0]=0;
    line(O[0],O[1],P[0],P[1]);
    cout<<"Scaling Matrix formed is: \n";
        
    for(i=0;i < 2;i++)
    { 
        printf("\n");
        for(j=0;j < 2;j++)
        {  
            printf("[%d]",S[i][j]);
        }
    }

    for(i=0;i < 2;i++)
    {  
        N[i]=0;
    }

    for(i=0;i < 2;i++)
    {  
        for(j=0;j < 2;j++)
        {
            N[i]+=S[i][j]*O[j];
            Q[i]+=S[i][j]*P[j];
        }
    }

    line(N[0],N[1],Q[0],Q[1]);
    getch();
}
        