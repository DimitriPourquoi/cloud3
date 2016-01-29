// 02LAB. Реалізувати і протестувати тип даних Segment

 

//*******************************************

//Every segment posesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a segment created or resp. deleted

//Developed by Dmytro Proskurnia

//at ....................

//Version 1.0

//*******************************************

 

// Клас відрізків
#include "stdafx.h"
#include <cmath>
#include <iostream>
#include "Segment.h"
#include "Point.h"
using namespace std;

struct Fraction
{
	double top;
	double bot;

	Fraction(double t, double b): top(t), bot(b) 
	{
		if(bot < 0)
		{
			bot = - bot;
			top = - top;
		};
	};

	~Fraction(){};

	Fraction operator+(const Fraction& f)
	{
		if(bot != f.bot)
			return Fraction(top*f.bot + bot*f.top, bot*f.bot);
		return Fraction(top + f.top, bot);
	};

	Fraction operator-(const Fraction& f)
	{
		if(bot != f.bot)
			return Fraction(top*f.bot - bot*f.top, bot*f.bot);
		return Fraction(top - f.top, bot);
	};

	Fraction operator*(const Fraction& f)
	{
		return Fraction(top*f.top, bot*f.bot);
	};

	Fraction operator/(const Fraction& f)
	{
		return Fraction(top*f.bot, bot*f.bot);
	};

	bool operator==(const Fraction& f)
	{
		if(bot == f.bot)
			return top == f.bot;
		return top*f.bot == bot*f.top;
	};
};


int Segment::_freeID(0);

// Конструктори відрізків

// 1) за координатами його кінців

Segment::Segment(const double x1, const double y1,

	const double x2, const double y2): 
	_a(Point::Point(x1,y1)), _b(Point::Point(x2,y2)), _myId(++_freeID) {};

// 2) за точками початку і кінця

Segment::Segment(const Point &start, const Point &end):
	_a(start), _b(end), _myId(++_freeID) {};

// 3) копіювальний конструктор

	Segment::Segment(const Segment& seg): _a(seg._a), _b(seg._b), _myId(++_freeID) {};

// Деструктор

	Segment::~Segment() {};

// Присвоєння

	Segment& Segment::operator=(const Segment& seg)
	{
		_a = seg._a, _b = seg._b;
		return *this;
	};

// Селектори  точок

const Point& Segment::start() const
{
	return _a;	
};

const Point& Segment::end() const
{
	return _b;
};

// Селектори-модифікатори точок

Point &Segment::start()
{
	return _a;
};

Point &Segment::end()
{
	return _b;
};

// Селектори координат точок

const double &Segment::startX() const
{
	return _a.x();
};

const double &Segment::startY() const
{
	return _a.y();
};

const double &Segment::endX() const
{
	return _b.x();
};

const double &Segment::endY() const
{
	return _b.y();
};

// Селектори-модифікатори координат точок

double &Segment::startX()
{
	return _a.x();
};

double &Segment::startY()
{
	return _a.y();
};

double &Segment::endX()
{
	return _b.x();
};

double &Segment::endY()
{
	return _b.y();
};

// Обчислення довжини відрізка

double inline dist(const Point& a, const Point& b)
{
	return sqrt(pow(b.x() - a.x(),2) + pow(b.y() - a.y(),2));
}

double Segment::length () const
{
	return dist(_a, _b);
};

// Обчислення відстані від відрізка до точки

double min(const double a, const double b)
{
	if(a<b)
		return a;
	return b;
};

bool inline double_equals(double a, double b, double epsilon = 0.001)
{
    return std::abs(a - b) < epsilon;
}

double Segment::distance (const Point&p) const
{
	if (Fraction(p.x() - _a.x(), _b.x() - _a.x()) == Fraction(p.y() - _a.y(), _b.y() - _a.y()))
	{
		if(double_equals(dist(_a, p)+dist(_b, p), length()))
			return 0;
		return min(dist(_a, p), dist(_b, p));
	};
	double a = _b.y() - _a.y();
	double b = _b.x() - _a.x();
	double d = abs(a*p.x() - b*p.y() - a*_a.x() + b*_b.y()) / sqrt(a*a + b*b);
	double left = d*sqrt(pow(dist(_a, p),2)-d*d) + d*sqrt(pow(dist(_b, p),2)-d*d);
	double right = d*length();
	if (double_equals(d*sqrt(pow(dist(_a, p),2)-d*d) + d*sqrt(pow(dist(_b, p),2)-d*d), d*length()))
		return d;
	return min(dist(_a, p), dist(_b, p));
};

// Селектор ID

const int Segment::getID() const
{
	return _myId;
};

ostream& operator<<(ostream &os, const Segment &seg)
{
	return os<<"Segment"<<seg.start()<<','<<seg.end();
};