#include<stdio.h>
#include "graphics.h"
#include<dos.h>
#include<conio.h>

template <class T>
void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
              swap(a[j], a[j - 1]);
}

void floodfill(intx,inty,intold,intnewcol)
{
                int current;
                current=getpixel(x,y);
                if(current==old)
                {
                                delay(5);
                                putpixel(x,y,newcol);
                                floodfill(x-1,y,old,newcol);
                                floodfill(x-1,y,old,newcol);
                                floodfill(x,y+1,old,newcol);
                                floodfill(x,y-1,old,newcol);
                                floodfill(x+1,y+1,old,newcol);
                                floodfill(x-1,y+1,old,newcol);
                                floodfill(x+1,y-1,old,newcol);
                                floodfill(x-1,y-1,old,newcol);
                }
}
void main()
{
                intgd=DETECT,gm;
                initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
                rectangle(50,50,15,150);
                floodfill(70,70,0,15);
                getch();
                closegraph();
}
