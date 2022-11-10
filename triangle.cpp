#include <iostream>
#include <math.h>
using namespace std;

class Triangle {
	private:
		int a; int a1; int b; int b1; int c; int c1;
	
	public:
		Triangle();
		Triangle(int , int , int , int , int , int);
		~Triangle();
		int getA(); int getA1(); int getB(); int getB1(); int getC(); int getC1();
};

Triangle::Triangle(){
	a = 0; a1 = 0;
	b = 0; b1 = 0;
	c = 0; c1 = 0;
}

Triangle::~Triangle(){}

Triangle::Triangle (int a ,int a1 ,int b ,int b1 ,int c ,int c1 ){
	this -> a = a;
	this -> a1 = a1;
        this -> b = b;
	this -> b1 = b1;
	this -> c = c;
	this -> c1 = c1;
}

int Triangle:: getA()
{
	return this -> a;	
}

int Triangle:: getA1()
{
	return this -> a1;	
}

int Triangle:: getB()
{
	return this -> b;	
}

int Triangle:: getB1()
{
	return this -> b1;	
}

int Triangle:: getC()
{
	return this -> c;	
}

int Triangle:: getC1()
{
	return this -> c1;	
}


float area(int x1,int y1, int x2 ,int y2, int x3 , int y3) {

	return abs ( ( x1 * ( y2 - y3 ) + x2 * ( y3 - y1 ) + x3 * ( y1-y2 ) ) /2.0);
}

bool pointInside( int x1, int y1, int x2 , int y2, int x3 , int y3, int x , int y ){
	float A = area (x1,y1,x2,y2,x3,y3);
	float A1 = area (x,y,x2,y2,x3,y3);
	float A2 = area (x1,y1,x,y,x3,y3);
	float A3 = area (x1,y1,x2,y2,x,y);

	return ( A == A1 + A2 + A3 );
}
class Point {

	private:
		int x;
		int y;
	public:
		Point();
		Point(int , int);
		~Point();
		int getX();
		int getY();
		void setX(int);
		void setY(int);

};

Point::Point() {
	x = 0;
	y = 0;
}

Point::~Point(){}

Point::Point(int x1 , int y1){
	x = x1;
	y = y1;
}

void Point::setX(int x1) {
	x = x1;
}

void Point::setY (int y1) {
	y = y1;
}

int Point::getX() {
	return this -> x;
}

int Point::getY() {
	return this -> y;
}

int main(){
	int a;
	int b;

	cout << "a = "; 
	cin >> a;
	cout << "b = "; 
	cin >> b;
	
	Point point (a, b);	
	
	Triangle triangle(0 , 0 , 0 , 6 , 8 , 0);

	bool isInside = pointInside(triangle.getA(),triangle.getA1() , triangle.getB(),  triangle.getB1() , triangle.getC(),triangle.getC1(), point.getX() , point.getY());
	if(isInside == true){
		cout << "The point is located inside the triangle" << endl;
	}else{
	        cout << "The point is located outside of the triangle" << endl;
	}

	return 0;
}
