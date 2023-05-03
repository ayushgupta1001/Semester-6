#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

using namespace std;

void scaling(int sx,int sy,int lineMatrix[2][3])
{
	int transMatrix[3][3]={0};
	int i,j;
	transMatrix[2][2] =1;
	transMatrix[0][0] = sx;
	transMatrix[1][1] = sy;
	transMatrix[0][1] = 0;
	transMatrix[1][0] = 0;
	cout<<"\nLine Matrix::\n";
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<lineMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\nTransformation Matrix::\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<transMatrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
	int multMatrix[2][3];
	int ele;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			ele = 0;
			for(int l=0;l<3;l++){
					ele += lineMatrix[i][l]*transMatrix[l][j];
			}
			multMatrix[i][j] = ele;
			
		}
		
	}
	cout<<"\nLine Matrix after transformation::\n";
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout<<multMatrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
	setcolor(RED);
	line(multMatrix[0][0],multMatrix[0][1],multMatrix[1][0],multMatrix[1][1]);
	
}

void shearing(int shx,int shy,int lineMatrix[2][3]){
	int transMatrix[3][3]={0};
	int i,j;
	transMatrix[2][2] =1;
	transMatrix[0][0] = 1;
	transMatrix[1][1] = 1;
	transMatrix[0][1] = shy;
	transMatrix[1][0] = shx;
	cout<<"\nLine Matrix::\n";
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout<<lineMatrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
	cout<<"\nTransformation Matrix::\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<transMatrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
	int multMatrix[2][3];
	int ele;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			ele = 0;
			for(int l=0;l<3;l++){
					ele += lineMatrix[i][l]*transMatrix[l][j];
			}
			multMatrix[i][j] = ele;
			
		}
		
	}
	cout<<"\nLine Matrix after transformation::\n";
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout<<multMatrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
	setcolor(RED);
	line(multMatrix[0][0],multMatrix[0][1],multMatrix[1][0],multMatrix[1][1]);
	
}

void translation(int tx,int ty,int lineMatrix[2][3]){
	int transMatrix[3][3]={0};
	int i,j;
	transMatrix[2][2] =1;
	transMatrix[0][0] = 1;
	transMatrix[1][1] = 1;
	transMatrix[2][0] = tx;
	transMatrix[2][1] = ty;
	cout<<"\nLine Matrix::\n";
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout<<lineMatrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
	cout<<"\nTransformation Matrix::\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<transMatrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
	int multMatrix[2][3];
	int ele;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			ele = 0;
			for(int l=0;l<3;l++){
					ele += lineMatrix[i][l]*transMatrix[l][j];
			}
			multMatrix[i][j] = ele;
			
		}
		
	}
	cout<<"\nLine Matrix after transformation::\n";
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout<<multMatrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
	setcolor(RED);
	line(multMatrix[0][0],multMatrix[0][1],multMatrix[1][0],multMatrix[1][1]);
	
}

void rotation(int theta,int direction,int lineMatrix[2][3]){
	float transMatrix[3][3]={0};
	int i,j;
	float radian = theta * 3.14/180;
	float cvalue = cos(radian*direction);
	float svalue = sin(radian*direction);
	transMatrix[2][2] =1;
	transMatrix[0][0] = cvalue;
	transMatrix[1][1] = cvalue;
	transMatrix[0][1] = svalue;
	transMatrix[1][0] = -svalue;
	cout<<"\nLine Matrix::\n";
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout<<lineMatrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
	cout<<"\nTransformation Matrix::\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<transMatrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
	float multMatrix[2][3];
	float ele;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			ele = 0;
			for(int l=0;l<3;l++){
					ele += lineMatrix[i][l]*transMatrix[l][j];
			}
			multMatrix[i][j] = ele;
			
		}
		
	}
	cout<<"\nLine Matrix after transformation::\n";
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout<<multMatrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
	
	setcolor(RED);
	line(multMatrix[0][0],multMatrix[0][1],multMatrix[1][0],multMatrix[1][1]);
	
	
	
}
int main(){
	int gd = DETECT,gm;
	int lineMatrix[2][3];
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cout<<"Enter x0 coordinates of line::";
	cin>>lineMatrix[0][0];
	cout<<"\nEnter y0 coordinates of line::";
	cin>>lineMatrix[0][1];
	cout<<"\nEnter x1 coordinates of line::";
	cin>>lineMatrix[1][0];
	cout<<"\nEnter y1 coordinates of line::";
	cin>>lineMatrix[1][1];
	lineMatrix[0][2]=1;
	lineMatrix[1][2]=1;

	line(lineMatrix[0][0],lineMatrix[0][1],lineMatrix[1][0],lineMatrix[1][1]);
	

	
		int choice;
		cout<<"\n1.Scaling";
		cout<<"\n2.Shearing";
		cout<<"\n3.Translation";
		cout<<"\n4.Rotation";
		cout<<"\nEnter your choice::";
		cin>>choice;
		switch(choice){
			case 1:
					int sx,sy;
					cout<<"\nEnter scaling in x direction:";
					cin>>sx;
					cout<<"\nENTER scaling in y direction:";
					cin>>sy;
					scaling(sx,sy,lineMatrix);
					break;
			
			case 2:
					int shx,shy;
					cout<<"\nEnter shearing in x direction:";
					cin>>shx;
					cout<<"\nENTER shearing in y direction:";
					cin>>shy;
					shearing(shx,shy,lineMatrix);
					break;
			
			case 3:
					int tx,ty;
					cout<<"\nEnter translation in x direction:";
					cin>>tx;
					cout<<"\nENTER translation in y direction:";
					cin>>ty;
					translation(tx,ty,lineMatrix);
					break;
			
			case 4:
					int theta,direction;
					cout<<"\nEnter rotation angle :";
					cin>>theta;
					cout<<"\nENTER direction of rotation(1 for anticlockwise OR -1 for clockwise):";
					cin>>direction;
					rotation(theta,direction,lineMatrix);
					break;
			default: cout<<"\nInvalid input";
					 break;
	
		}
	getch();
    closegraph();
    return 0;
		
	
	
}
