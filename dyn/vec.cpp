#include "vec.h"

Vec::Vec(const Vec &inVec){
	x = inVec.x;
	y = inVec.y;
	len = inVec.len;
};
Vec Vec::getSum(Vec a,Vec b){
	return Vec(a.x+b.x,a.y+b.y);
};
Vec Vec::getSub(Vec a,Vec b){
	return Vec(a.x-b.x,a.y-b.y);
}
double Vec::getDot(Vec a,Vec b){
	return a.x*b.x+a.y*b.y;
}
Vec const operator+(const Vec &plusA,const Vec &plusB){
	return Vec(plusA.x+plusB.x,plusA.y+plusB.y);
}
Vec const operator-(const Vec &subA,const Vec &subB){
	return Vec(subA.x-subB.x,subA.y-subB.y)	   ;
}
Vec Vec::normalizeVec(){
	return 	Vec(x/len,y/len);
}