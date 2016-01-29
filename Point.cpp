#include "stdafx.h"
#include <iostream>
#include "Point.h"

using namespace std;

 

//*******************************************

//Every point posesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a point created or resp. deleted

//Developed by Dmytro Proskurnia

//on ....................

//Version 1.0

//*******************************************

int Point::freeID = 0;

int Point::n = 0;

Point::Point (double x, double y): _x(x),_y(y), pointID(++freeID) {n++;};

Point::Point (const Point &p): _x(p._x),_y(p._y), pointID(++freeID) {n++;};

Point::~Point(){n--;};

Point& Point::operator=(const Point &p)
{
	return Point(p._x,p._y);
};

double& Point::x()
{
	return _x;	
};

double& Point::y()
{
	return _y;	
};

const double& Point::x()const
{
	return _x;	
};

const double& Point::y()const
{
	return _y;	
};

const int Point::getID() const
{
	return pointID;
};

int Point::amount()
{
	return freeID;	
};

int Point::existing()
{
	return n;	
};
 

ostream& operator<<(ostream& os, const Point& p)
{
	os<<'('<<p.x()<<", "<<p.y()<<')';
	return os;
};


const Point operator+ (const Point & u, const Point & v)
{
	return Point(u.x() + v.x(), u.y() + v.y());
};

Point& operator+=(Point & p, const Point& a)
{
	p.x()+= a.x();
	p.y()+= a.y();
	return p;
};

bool operator==(const Point & u, const Point &v)
{
	return (u.x() == v.x() && u.y() == v.y());
	return false;
};

bool operator!=(const Point & u, const Point &v)
{
	return !(u==v);	
};
