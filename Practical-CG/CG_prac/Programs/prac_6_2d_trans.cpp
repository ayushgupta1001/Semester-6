#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>

void mul(int a[3][3], int b[3][3], int c[3][3]){
   int i, j, k;
   // multiplication ==>  trmat X obj
   for(i=0; i<3; i++)
     for(j=0; j<3; j++){
       for(k=0; k<3; k++)
       a[i][j] += b[i][k]*c[k][j];
   }
}

void mul(int a[3][3], double b[3][3], int c[3][3]){
   int i, j, k;
   // multiplication ==>  trmat X obj
   for(i=0; i<3; i++)
     for(j=0; j<3; j++){
       for(k=0; k<3; k++)
       a[i][j] += b[i][k]*c[k][j];
   }
}

///////////////////////////
void mapXY(int& x, int& y){
     x += 319;
     y = 239 - y;
}

void drawAxis(int vertices[3][3]){
  int gd = DETECT , gm ;

  clrscr();
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    line(vertices[0][0]+319, 239-vertices[1][0], vertices[0][1]+319, 239-vertices[1][1]);
    line(vertices[0][1]+319, 239-vertices[1][1], vertices[0][2]+319, 239-vertices[1][2]);
    line(vertices[0][2]+319, 239-vertices[1][2], vertices[0][0]+319, 239-vertices[1][0]);

    // Origin (319, 239)
    line(9, 239, 629, 239); //x-axis
    line(319, 9, 319, 469); //y-axis
}

/////////////////////////////
void translate(int obj[3][3], double dx, double dy){

   int trmat[3][3], final[3][3], i, j, k;
   for(i=0; i<3; i++)
      for(j=0; j<3; j++){
	 final[i][j] = 0;
	 trmat[i][j] = (i==j) ? 1 : 0;
      }

   trmat[0][2] = dx;
   trmat[1][2] = dy;

   mul(final, trmat, obj);

   for(i=0; i<3; i++)
      mapXY(final[0][i], final[1][i]);
   setcolor(CYAN);
   line(final[0][0], final[1][0], final[0][1], final[1][1]);
   line(final[0][1], final[1][1], final[0][2], final[1][2]);
   line(final[0][2], final[1][2], final[0][0], final[1][0]);
   getch();
}

void scaling(int obj[3][3], double dx, double dy){


   int final[3][3], i, j, k;
   double sclmat[3][3];
   for(i=0; i<3; i++)
      for(j=0; j<3; j++){
	 final[i][j] = 0;
	 sclmat[i][j] = (i==j) ? 1 : 0;
      }
   sclmat[0][0] = (dx!=0) ? dx : 1;
   sclmat[1][1] = (dy!=0) ? dy : 1;
   mul(final, sclmat, obj);

   for(i=0; i<3; i++)
      mapXY(final[0][i], final[1][i]);

   setcolor(LIGHTGREEN);
   line(final[0][0], final[1][0], final[0][1], final[1][1]);
   line(final[0][1], final[1][1], final[0][2], final[1][2]);
   line(final[0][2], final[1][2], final[0][0], final[1][0]);
   getch();
}

/////////////////////////////
void reflect(int obj[3][3], int about){

   int reflactmat[3][3], final[3][3], i, j, k;

   for(i=0; i<3; i++)
      for(j=0; j<3; j++){
	 final[i][j] = 0;
	 reflactmat[i][j] = (i==j) ? 1 : 0;
      }

   switch(about){
      case 1: reflactmat[1][1] = -1;
	      break;
      case 2: reflactmat[0][0] = -1;
	      break;
      case 3: reflactmat[0][0] = -1;
	      reflactmat[1][1] = -1;
	      break;
      default: cout<<" Seems you ain\'t familier with a cartition plane!!";
	       delay(200);
	       exit(0);
   }

   mul(final, reflactmat, obj);

   for(i=0; i<3; i++)
      mapXY(final[0][i], final[1][i]);
   setcolor(LIGHTBLUE);
   line(final[0][0], final[1][0], final[0][1], final[1][1]);
   line(final[0][1], final[1][1], final[0][2], final[1][2]);
   line(final[0][2], final[1][2], final[0][0], final[1][0]);
   getch();
}

/////////////////////////////
void rotate(int obj[3][3], double coff){

   double rotmat[3][3], pi = 3.14;
   int final[3][3], i, j, k;
   double theeta = pi/coff;

   for(i=0; i<3; i++)
      for(j=0; j<3; j++){
	 final[i][j] = 0;
	 rotmat[i][j] = 0;
      }
   rotmat[0][0] = cos(theeta);
   rotmat[0][1] = -sin(theeta);
   rotmat[1][0] = sin(theeta);
   rotmat[1][1] = cos(theeta);

   mul(final, rotmat, obj);

   for(i=0; i<3; i++)
      mapXY(final[0][i], final[1][i]);
   setcolor(LIGHTRED);
   line(final[0][0], final[1][0], final[0][1], final[1][1]);
   line(final[0][1], final[1][1], final[0][2], final[1][2]);
   line(final[0][2], final[1][2], final[0][0], final[1][0]);
   getch();
}

/////////////////////////////
// Bug:  infinite shearing
/////////////////////////////
void shear(int obj[3][3], double dx, double dy){

   int final[3][3], i, j;
   double shrmat[3][3];

   for(i=0; i<3; i++)
      for(j=0; j<3; j++){
	 final[i][j] = 0;
	 shrmat[i][j] = (i==j) ? 1 : 0;
      }
   shrmat[0][1] = dx;
   shrmat[1][0] = dy;
   mul(final, shrmat, obj);

   for(i=0; i<3; i++)
      mapXY(final[0][i], final[1][i]);
   setcolor(LIGHTMAGENTA);
   line(final[0][0], final[1][0], final[0][1], final[1][1]);
   line(final[0][1], final[1][1], final[0][2], final[1][2]);
   line(final[0][2], final[1][2], final[0][0], final[1][0]);
   getch();
}

void main(){
  clrscr();

    int vertices[3][3];
    int i, j, choice, about;
    double dx=0, dy=0, theeta;

    beg:
    cout<<"\n Range of x-axis: [-320, 320]"
	<<"\n Range of y-axis: [-240, 240]\n\n";

    cout<<" Enter 3 vertices of triangle (x, y): ";
    for(i=0; i<3; i++){
       for(j=0; j<2; j++){
	  cin>>vertices[j][i];
       }
       vertices[2][i] = 1;
       cout<<"\n";
    }

    do{
      closegraph();
      clrscr();

      cout<<"\n  MENU\n"
	  <<"--------\n"
	  <<"\n 1) Translate"
	  <<"\n 2) Scale"
	  <<"\n 3) Reflection"
	  <<"\n 4) Rotate"
	  <<"\n 5) Shear\n"
	  <<"\n 6) Enter new vertices!!"
	  <<"\n *  Press 0 to exit!\n\n   > ";
      cin>>choice;
      switch(choice){
	  case 1: cout<<" Enter Translation factors (dx, dy): ";
		  cin>>dx>>dy;
		  clrscr();
		  drawAxis(vertices);
		  getch();
		  translate(vertices, dx, dy);
		  break;
	  case 2: cout<<" Enter Scaling factors (dx, dy): ";
		  cin>>dx>>dy;
		  clrscr();
		  drawAxis(vertices);
		  getch();
		  scaling(vertices, dx, dy);
		  break;
	  case 3: clrscr();
		  cout<<"\n\tReflect about: \n"
		  <<"\n 1) x-axis"
		  <<"\n 2) y-axis"
		  <<"\n 3) diagolan"
		  <<"\n *  \n\n   : ";
		  cin>>about;
		  clrscr();
		  drawAxis(vertices);
		  getch();
		  reflect(vertices, about);
		  break;
	  case 4: cout<<" Enter Angle of rotation (in degrees): ";
		  cin>>theeta;
		  clrscr();
		  drawAxis(vertices);
		  getch();
		  rotate(vertices, double(180/theeta));
		  break;
	  case 5: clrscr();
		  cout<<"\n\tShear about: \n"
		  <<"\n 1) x-axis"
		  <<"\n 2) y-axis"
		  <<"\n 3) both i.e. x & y axis"
		  <<"\n *  \n\n   : ";
		  cin>>about;
		  switch(about) {
		     case 1: cout<<"\n  Enter shearing factor for x-axis: ";
			     cin>>dx;
			     break;
		     case 2: cout<<"\n  Enter shearing factor for y-axis: ";
			     cin>>dy;
			     break;
		     case 3: cout<<"\n  Enter shearing factors for x & y-axis: ";
			     cin>>dx>>dy;
			     break;
		     default: cout<<"\n\n Can\'t shear!!";
			      delay(200);
			      goto end;
		  }
		  clrscr();
		  drawAxis(vertices);
		  getch();
		  shear(vertices, dx, dy);
		  break;
	  case 6: goto beg;
	  case 0: cout<<"Exiting...";
		  delay(200);
		  goto last;
	  default: cout<<"Invalid input!!";
		   delay(200);
		   goto last;
      }
      end:
    }while(1);

  last:
	closegraph();
	exit(0);
}