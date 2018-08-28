#include <math.h>
class Vec{
private:
	double x,y ,len;
public:
	Vec():x(0),y(0),len(0){};
	Vec(double xx,double yy):x(xx),y(yy){len = sqrt(x*x+y*y);};
	Vec(const Vec &inVec);
	double getLengh();
	Vec normalizeVec();
	void setX(double xx){x = xx;} 
	void setY(double yy){y = yy;}
	double getX(){return x;}
	double getY(){return y;}
	Vec getSum(Vec a,Vec b);
	Vec getSub(Vec a,Vec b);
	double getDot(Vec a,Vec b);
	friend const Vec operator+(const Vec &plusA,const Vec &plusB);
	friend const Vec operator-(const Vec &subA,const Vec &subB);
};
