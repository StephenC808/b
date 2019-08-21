#include <windows.h>
#include <iostream>   // for cerr
#include <stdio.h>
#include <conio.h> 
#include "Point.h"

class   line:   public point{
   protected:  int   x2, y2;
   public:     line()  {  x = 0;   y = 0; RGB_color=RGB(0,0,0);  x2 = 0; y2=0;  }
               line( int xval, int yval, int r,int g,int b , int xval2, int yval2);
			   ~line();
               void  draw(HDC hDC);
        };

//=== methods for line class ================================
      line::line( int xval, int yval, int r, int g, int b, int xval2, int yval2): point( xval, yval, r,g,b)
                                     {  x2 = xval2; y2 = yval2;  }
	  line::~line(){}

void  line::draw(HDC hDC)
      {
       
		 HPEN pen=NULL;
		 if (pen)DeleteObject(pen); //delete previous created pen
		         
		 pen=CreatePen(PS_SOLID,1,RGB_color);  // Create a new pen
         SelectObject(hDC,pen); // select pen into context
         MoveToEx (hDC,x,y,NULL);
		 LineTo(hDC,x2,y2);
       }