#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
using namespace std;


typedef int vertex[2];
typedef vertex edge[2];
typedef vertex vertexArray[10];

static void Output(vertex newVertex, int* outLength, vertexArray outVertexArray)
{
    outVertexArray[*outLength][0] = newVertex[0];
    outVertexArray[*outLength][1] = newVertex[1];
    *outLength = *outLength + 1;


}

static int Inside(vertex testVertex, edge clipBoundary, int clipCheck)
{
    
    int d = ((clipBoundary[1][0] - clipBoundary[0][0]) * (testVertex[1] - clipBoundary[0][1])) - ((clipBoundary[1][1] - clipBoundary[0][1]) * (testVertex[0] - clipBoundary[0][0]));
    if (clipCheck)
    {
        if (d >= 0)
            return 1;
        else return 0;

    }
    else
    {
        if (d <= 0)
            return 1;
        else return 0;
    }

}

int inters[2];
static int* Intersect(vertex first, vertex second, edge clipBoundary)
{
    int x1 = first[0];
    int y1 = first[1];
    int x2 = second[0];
    int y2 = second[1];
    int x3 = clipBoundary[0][0];
    int y3 = clipBoundary[0][1];
    int x4 = clipBoundary[1][0];
    int y4 = clipBoundary[1][1];
    
    inters[0] = (((x1 * y2 - y1 * x2) * (x3 - x4)) - ((x1 - x2) * (x3 * y4 - y3 * x4))) / (((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4)));
    inters[1] = (((x1 * y2 - y1 * x2) * (y3 - y4)) - ((y1 - y2) * (x3 * y4 - y3 * x4))) / (((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4)));
    return inters;


}

void SutherlandHodgmanPolygonClip(vertexArray inVertexArray, vertexArray outVertexArray, int inLength, int* outLength, edge clipBoundary, int clipCheck)
{
    vertex s, p, i;
    int j;
    *outLength = 0;
    s[0] = inVertexArray[inLength - 1][0];
    s[1] = inVertexArray[inLength - 1][1];
    for (j = 0; j < inLength; j++)
    {
        p[0] = inVertexArray[j][0];
        p[1] = inVertexArray[j][1];
        if (Inside(p, clipBoundary, clipCheck))
        {
            if (Inside(s, clipBoundary, clipCheck))
            {
                Output(p, outLength, outVertexArray);
                
            }
            else
            {
                i[0] = Intersect(s, p, clipBoundary)[0];
                i[1] = Intersect(s, p, clipBoundary)[1];
                Output(i, outLength, outVertexArray);
                Output(p, outLength, outVertexArray);
                
            }
        }
        else
        {

            if (Inside(s, clipBoundary, clipCheck))
            {
                i[0] = Intersect(s, p, clipBoundary)[0];
                i[1] = Intersect(s, p, clipBoundary)[1];
                Output(i, outLength, outVertexArray);
                
            }

        }
        s[0] = p[0];
        s[1] = p[1];
    }
}

int main()
{
    vertexArray inVertexArray, outVertexArray;
    int gd = DETECT, gm, x0, y0, x1, y1;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    
    cout << "Enter no of vertices:";
    int inLength, outLength = 0;
    cin >> inLength;
    cout << "Enter coordinates of Polygon:\n";
    for (int i = 0; i < inLength; i++)
    {
        cout << "Enter x" << i << ":";
        cin >> inVertexArray[i][0];
        cout << "Enter y" << i << ":";
        cin >> inVertexArray[i][1];
    }

    int inputPoly[30];
    int j = 0;
    for (int y = 0; y < inLength; y++)
    {
        for (int k = 0; k < 2; k++)
        {

            inputPoly[j] = inVertexArray[y][k];
            j++;
        }


    }

    inputPoly[j] = inVertexArray[0][0];
    j++;
    inputPoly[j] = inVertexArray[0][1];
    rectangle(100,200,300,400);
    setcolor(GREEN);
    drawpoly(inLength+1,inputPoly);
    //int inCount = inLength;
    int clipCheck = 1;
    edge TOP_BOUND;
    TOP_BOUND[0][0] = 0;
    TOP_BOUND[0][1] = 200;
    TOP_BOUND[1][0] = 639;
    TOP_BOUND[1][1] = 200;

    edge RIGHT_BOUND;
    RIGHT_BOUND[0][0] = 300;
    RIGHT_BOUND[0][1] = 0;
    RIGHT_BOUND[1][0] = 300;
    RIGHT_BOUND[1][1] = 479;

    edge BOTTOM_BOUND;
    BOTTOM_BOUND[0][0] = 0;
    BOTTOM_BOUND[0][1] = 400;
    BOTTOM_BOUND[1][0] = 639;
    BOTTOM_BOUND[1][1] = 400;

    edge LEFT_BOUND;
    LEFT_BOUND[0][0] = 100;
    LEFT_BOUND[0][1] = 0;
    LEFT_BOUND[1][0] = 100;
    LEFT_BOUND[1][1] = 479;
    SutherlandHodgmanPolygonClip(inVertexArray, outVertexArray, inLength, &outLength, TOP_BOUND, clipCheck);
    
    int x;
    for (x = 0; x < outLength; x++)
    {
        inVertexArray[x][0] = outVertexArray[x][0];
        inVertexArray[x][1] = outVertexArray[x][1];
    }
    inLength = outLength;
    outLength = 0;
    SutherlandHodgmanPolygonClip(outVertexArray, outVertexArray, inLength, &outLength, RIGHT_BOUND, clipCheck);
    
    for (x = 0; x < outLength; x++)
    {
        inVertexArray[x][0] = outVertexArray[x][0];
        inVertexArray[x][1] = outVertexArray[x][1];
    }
    inLength = outLength;
    outLength = 0;
    clipCheck = 0;
    SutherlandHodgmanPolygonClip(inVertexArray, outVertexArray, inLength, &outLength, BOTTOM_BOUND, clipCheck);
    
    for (x = 0; x < outLength; x++)
    {
        inVertexArray[x][0] = outVertexArray[x][0];
        inVertexArray[x][1] = outVertexArray[x][1];
    }
    inLength = outLength;
    outLength = 0;
    SutherlandHodgmanPolygonClip(inVertexArray, outVertexArray, inLength, &outLength, LEFT_BOUND, clipCheck);
    cout << "No of vertices after clipping::"<<outLength;
    cout << "\nOutput:\n";
    for (x = 0; x < outLength; x++)
    {
        cout << "("<<outVertexArray[x][0] << ","<<outVertexArray[x][1]<<")"<<endl;
        


    }
    
    //inLength = inCount;
    int outputPoly[30];
    j = 0;
    for (x = 0; x < outLength; x++)
    {
        for (int z = 0; z < 2; z++)
        {

            outputPoly[j] = outVertexArray[x][z];
            j++;
        }


    }
    outputPoly[j] = outVertexArray[0][0];
    j++;
    outputPoly[j] = outVertexArray[0][1];

     setcolor(RED);
     setfillstyle(HATCH_FILL,RED);
     fillpoly(outLength+1,outputPoly);

    getch();
    closegraph();
    return 0;
}


