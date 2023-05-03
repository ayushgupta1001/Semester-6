#include<iostream.h>
#include<conio.h>
#include<graphics.h>

#include<CohenSutherlandLineClipping.h>

struct point{
  int x;
  int y;
};

static int c;
point Q[10];	// to store resulting points ----> max double than

void dispLine(LINE l){
   if((l.x1 || l.y1) == -1){
   // put into Q if any one point ain't rejected
	Q[c].x = Q[c-1].x;
	Q[c].y = Q[c-1].y;
	c++;
   }
   else{
	//cout<<"("<<l.x1<<", "<<l.y1<<") to ("<<l.x2<<", "<<l.y2<<")\n";
	Q[c].x = l.x1;
	Q[c].y = l.y1;
	c++;
   }

   if((l.x2 || l.y2) == -1){
   // put into Q if any one point ain't rejected
	Q[c].x = Q[c-1].x;
	Q[c].y = Q[c-1].y;
	c++;
   }
   else{
	//cout<<"("<<l.x1<<", "<<l.y1<<") to ("<<l.x2<<", "<<l.y2<<")\n";
	Q[c].x = l.x2;
	Q[c].y = l.y2;
	c++;
   }

   if((l.x1 && l.y1 && l.x2 && l.y2) != -1){
     line(l.x1, l.y1, l.x2, l.y2);
   }
}

//  temp func -->  just for checking
void dispQ(int size){
   for(int i=0; i<size; i++)
	cout<<"\t("<<Q[i].x<<", "<<Q[i].y<<")\n";
}

drawVnH()	// draws horizontal and vertical lines
    {
      // horizontal lines ---> have const y
      for(int i=0; i<c; i++){
	 int constY = Q[i].y;
	 for(int j = i+1; j<c; j++){
	    if(constY==Q[j].y)
	      line(Q[i].x, Q[i].y, Q[j].x, Q[j].y);
	 }
      }

      // vertical lines ---> have const x
      for(i=0; i<c; i++){
	 int constX = Q[i].x;
	 for(int j = i+1; j<c; j++){
	    if(constX==Q[j].x)
	      line(Q[i].x, Q[i].y, Q[j].x, Q[j].y);
	 }
      }
    }

void main()
{
  clrscr();
    LINE Line;
    point P[10];
    int n, x, y, i, j, size;

    cout<<"Enter window\'s minimum coordinates (x, y): ";
    cin>>x_min>>y_min;
    cout<<"Enter window\'s maximum coordinates (x, y): ";
    cin>>x_max>>y_max;

    cout<<"Enter the no of vertices (of polygon): ";
    cin>>n;
    size = 2*n;	//size of Q[]

    cout<<"Enter the co-ordinates (x, y) for "<<n<<" vertices: ";
    for(i=0; i<n; i++)
	cin>>P[i].x>>P[i].y;

    /////////////////////////////

    clrscr();

    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // window
    rectangle(x_min, y_max, x_max, y_min);

    // drawing object i.e. polygon
    for(i=0; i<n-1; i++)
	line(P[i].x, P[i].y, P[i+1].x, P[i+1].y);
    line(P[0].x, P[0].y, P[n-1].x, P[n-1].y);

    getch();
    setcolor(RED);

    cout<<"\n\n\n";
    c=0;
    for(i=0; i<n-1; i++){
       Line = cohenSthAlgo(P[i].x, P[i].y, P[i+1].x, P[i+1].y);
       dispLine(Line);
    }

    Line = cohenSthAlgo(P[0].x, P[0].y, P[n-1].x, P[n-1].y);
    dispLine(Line);

    drawVnH();

  getch();
}