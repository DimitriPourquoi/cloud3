// 02.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Point.h"
#include "Segment.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Segment s(0,0,10,0);
	cout<<s<<endl;
	cout<<"distance to point(5,0): "<<s.distance(Point(5,0))<<endl;
	cout<<"distance to point(0,10): "<<s.distance(Point(0,10))<<endl;
	cout<<"distance to point(-5,0): "<<s.distance(Point(-5,0))<<endl;
	cout<<"distance to point(13,4): "<<s.distance(Point(13,4))<<endl;
	cout<<"segment length: "<<s.length()<<endl;
	return 0;
	return 0;
}

