#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
using namespace std;


class bucket
{
	public:
    int ymax;  
    float xofymin; 
    float slopeinverse;
};
 
class edgetablebucket
{
	public:
    int count;   
    bucket buckets[10];
};
 
edgetablebucket EdgeTable[600], ActiveEdge;

void Sort(edgetablebucket *t)
{
	int i,j;
	 for(i = 0; i < t->count; i++)
    {
        for(j = 0; j < t->count - i -1 ; j++)
        {
            if(t->buckets[j].xofymin >t->buckets[j+1].xofymin)
            {
                bucket temp;
                temp.ymax = t->buckets[j].ymax;
        		temp.xofymin = t->buckets[j].xofymin;
        		temp.slopeinverse = t->buckets[j].slopeinverse;
                t->buckets[j].ymax = t->buckets[j+1].ymax;
                t->buckets[j].xofymin = t->buckets[j+1].xofymin;
                t->buckets[j].slopeinverse = t->buckets[j+1].slopeinverse;
                t->buckets[j+1].ymax = temp.ymax;
                t->buckets[j+1].xofymin = temp.xofymin;
                t->buckets[j+1].slopeinverse = temp.slopeinverse;          
            }
        }

    }
}

void store(int x1,int y1, int x2, int y2)
{
    float slope,slopeinv; 
    if (x2==x1)
    {
        slopeinv=0;
    }
    else
    {
    slope = ((float)(y2-y1))/((float)(x2-x1));
    if (y2==y1)
        return;
         
    slopeinv = (float)1.0/slope;
    }
     
    if (y1>y2)
    {
        EdgeTable[y2].buckets[EdgeTable[y2].count].ymax = y1;
        EdgeTable[y2].buckets[EdgeTable[y2].count].xofymin = (float)x2;
        EdgeTable[y2].buckets[EdgeTable[y2].count].slopeinverse = slopeinv;
        Sort(&EdgeTable[y2]);
        (EdgeTable[y2].count)++;
    }
    else
    {
		EdgeTable[y1].buckets[EdgeTable[y1].count].ymax = y2;
        EdgeTable[y1].buckets[EdgeTable[y1].count].xofymin = (float)x1;
        EdgeTable[y1].buckets[EdgeTable[y1].count].slopeinverse = slopeinv;  
		Sort(&EdgeTable[y1]);
        (EdgeTable[y1].count)++;   
    }
     
}
 
void remove(edgetablebucket *t,int y)
{
    int i,j;
    for (i=0; i< t->count; i++)
    {
        if (t->buckets[i].ymax == y)
        {
             
            for ( j = i ; j < t->count -1 ; j++ )
                {
                t->buckets[j].ymax =t->buckets[j+1].ymax;
                t->buckets[j].xofymin =t->buckets[j+1].xofymin;
                t->buckets[j].slopeinverse = t->buckets[j+1].slopeinverse;
                }
                t->count--;
            i--;
        }
    }
}    
 
void ScanlineFill()
{
    
    int i, j;
    for (i=0; i<600; i++)
    {
        for (j=0; j<EdgeTable[i].count; j++)
        {
        	
        	ActiveEdge.buckets[ActiveEdge.count].ymax = EdgeTable[i].buckets[j].ymax;
			ActiveEdge.buckets[ActiveEdge.count].xofymin = EdgeTable[i].buckets[j].xofymin;
			ActiveEdge.buckets[ActiveEdge.count].slopeinverse = EdgeTable[i].buckets[j].slopeinverse;  
			Sort(&ActiveEdge);
			(ActiveEdge.count)++;
			
        }
        remove(&ActiveEdge, i);
        Sort(&ActiveEdge);
        j = 0;
        int flag = 0;
        int x1 = 0;
        int x2 = 0;
        while (j<ActiveEdge.count)
        {
            if (flag%2==0)
            {
                x1 = (int)(ActiveEdge.buckets[j].xofymin);
                flag++;   
            }
            else
            {
                x2 = (int)ActiveEdge.buckets[j].xofymin;         
                flag++;
                line(x1,i,x2,i);
             
        	}
             
        	j++;
    	}
             
         
    
    int k;
    for (k=0; k<ActiveEdge.count; k++)
    {
        (ActiveEdge.buckets[k]).xofymin =(ActiveEdge.buckets[k]).xofymin + (ActiveEdge.buckets[k]).slopeinverse;

        
    }
}
cout<<"\nPolygon filling completed";
 
}
int main(){
	int gd=DETECT,gm,n;
	int x[10],y[10];
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    cout<<"Enter the no. of vertices of the polygon : ";
    cin>>n;
    int i;
    for(i=0;i<n;i++) {
            cout<<"P"<<i+1<<" : ";
            cin>>x[i]>>y[i];
    }
    for (i=0; i<600; i++)
    {
        EdgeTable[i].count = 0;
    }
     
    ActiveEdge.count = 0;
    for(i=0;i<n-1;i++) {
    	store(x[i], y[i], x[i+1], y[i+1]);
            
    }
    store(x[i],y[i],x[0],y[0]);
    ScanlineFill();
    getch();
    closegraph();
    return 0;
    
}

