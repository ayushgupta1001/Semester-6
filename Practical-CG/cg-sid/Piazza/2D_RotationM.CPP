#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>

using namespace std;

#define PI 3.14

void main()
{  
    clrscr();
    int O[2],theta,i,j;
    float R[2][2],N[2],val=PI/180,a,b;
    char dir[20];
    cout<<"Enter the coordinates x and y for the point:";
    cin>>O[0]>>O[1];
    cout<<"Enter the angle for rotation:";
    cin>>theta;
    a=sin(theta*val);
    b=cos(theta*val);
    cout<<"Enter the direction of rotation:";
    cin>>dir;
    cout<<"Original coordinates:";
    cout<<"[%d  %d]\n",O[0],O[1];
        
    //Rotation matrix formed is | cos(theta)   -sin(theta) |
    //                          | sin(theta)    cos(theta) |
    
    if(dir=="anticlockwise")
	{
        R[0][0]=R[1][1]=b;
        R[0][1]=-a;
        R[1][0]=a;
    }
    else
    {
        R[0][0]=R[1][1]=b;
        R[0][1]=a;
        R[1][0]=-a;
    }
        
    cout<<"\nRotation Matrix formed is: \n";
    for(i=0;i < 2;i++)
    { 
        cout<<"\n";
        for(j=0;j < 2;j++)
        {  
            cout<<"[%f]",R[i][j];
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
            N[i]+=R[i][j]*O[j];
        }
    }
        
    cout<<"\nNew coordinates:";
    cout<<"[%f  %f]\n",N[0],N[1];
    getch();
}
        