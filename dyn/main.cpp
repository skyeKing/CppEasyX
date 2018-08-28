#include <iostream>
#include <graphics.h>
#include <conio.h>
#include "vec.h"

Vec a(0,200) ,b(400,0);
Vec eye(200,460);

Vec findCrossPointAxis(double slopeA,double offsetA,double slopeB,double offsetB){
	double x = (offsetB-offsetA)/(slopeA-slopeB);
	double y = (slopeA*offsetB-slopeB*offsetA)/(slopeA-slopeB);
	Vec tem(x,y);
	return tem;
}

double getSlope(Vec A,Vec B){
	return (B.getY()-A.getY())/(B.getX()-A.getX())	;
}

void drawBackGround(){
	line(
		(int)::a.getX(),(int)::a.getY(),
		(int)::b.getX(),(int)::b.getY());//point a and point b made up the mirror
	circle(
		(int)::eye.getX(),
		(int)::eye.getX(),
		3);	// set the position of eyes
}

void main(){
	// 2D
	initgraph(640,480);
	setlinestyle(PS_SOLID,3);

	MOUSEMSG m;
	while(true)	{
		m = GetMouseMsg();
		switch(m.uMsg){
		case WM_MOUSEMOVE:
			cleardevice()  ;
			drawBackGround();
			Vec targetPoint(m.x,m.y);
			double mirrorK = getSlope(::a,::b);	//	 find slope of base line
			double mirrorNormalK = (-1)/mirrorK;				        // find the line`s slope which vertical on the base line
			double offsetLine = targetPoint.getY()-mirrorNormalK*targetPoint.getX();  // depend on the x axis and the y axis and find out the offset
			// format record the data to easy use
			double a1=mirrorK,b1=a.getY()-a1*a.getX(),a2=mirrorNormalK,b2=targetPoint.getY()-targetPoint.getX()*a2;
			Vec crossPoint = findCrossPointAxis(a1,b1,a2,b2);

			Vec mirrorTarget = crossPoint+(crossPoint-targetPoint);

			//putpixel((int)crossPoint.getX(),(int)crossPoint.getY(),RED);
			line((int)crossPoint.getX(),(int)crossPoint.getY(),(int)targetPoint.getX(),(int)targetPoint.getY());




			line((int)mirrorTarget.getX(),(int)mirrorTarget.getY(),(int)eye.getX(),(int)eye.getY())	;

			putpixel((int)mirrorTarget.getX(),(int)mirrorTarget.getY(),BLUE);

			break;
		}
	} 
	
	getch();
	closegraph();
}