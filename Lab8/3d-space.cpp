/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: LabA, e.g., Lab1C

Task A. Length and distance in 3D space

NOTES FOR ME
difference between class and a struct:
structs are default public
classes are default private
both can have public and private members, use inheritence, and have member functions

*x are POINTER variable that can store memory addresses
&x is the ADDRESS of object x

you have to create the struct first before passing it in a func ;-;

when "." you are getting a property from the object
OBJECT, you cannot "." from a memory address
you also don't wana pass the entire struct
SO
when you pass the address (again u cant "." it)
you have to dereference it first
Dereferencing a pointer means getting the value that is stored in the memory location pointed by the pointer.
HOW TO DEREFERENCE:
(*p) --> then get x you get (*p).x
SHORT HAND IS p->x
*/

#include <cmath>
#include <iostream>
using namespace std;

struct Coord3D 
{
    double x;
    double y;
    double z;
};

double length(Coord3D *p);
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
void move(Coord3D *ppos, Coord3D *pvel, double dt);
Coord3D* createCoord3D(double x, double y, double z);
void deleteCoord3D(Coord3D *p);

int main()
{
	Coord3D pointP = 
	{
		15.123,	//x
		-234.321,	//y
		783.4	//z
	};
	
	Coord3D pointQ = 
	{
		 234.23,
		 -18.0,
		 -783.67
	};

	Coord3D pos = 
	{	0,
		0,
		100.0
	};
	
	Coord3D vel = 
	{	 1,
		-5,
		 .2
	};
	
	//cout << pointP.x; how to get value from struct
	//cout << length(&pointP) << endl; // would print 37.4166
	
	cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;
	
	Coord3D* ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl; // So which point is farther?

    move(&pos, &vel, 2.0); // object pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl;

}

double length(Coord3D *p)
{
	return sqrt(pow((*p).x,2)+pow(p->y,2)+pow(p->z,2)); //st trying ot print value of x
}

Coord3D* fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
	double length1 = 0.0;
	double length2 = 0.0;
	
	length1 = length(p1);
	length2 = length(p2);
	
	cout << "P:" << length1 << " Q:" << length2 << endl;
	
	if(length1 > length2)
		return p1;
	else
		return p2;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
	ppos->x = (ppos->x) + ((pvel->x) * (dt));
	ppos->y = (ppos->y) + ((pvel->y) * (dt));
	ppos->z = (ppos->z) + ((pvel->z) * (dt));
}

Coord3D* createCoord3D(double x, double y, double z)
{
	Coord3D *p = new Coord3D; //creating new vector
	
	p->x = x;
	p->y = y;
	p->z = z;
	
	return p;
}

void deleteCoord3D(Coord3D *p)
{
	delete p;
}