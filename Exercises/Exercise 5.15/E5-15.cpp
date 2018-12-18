/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: name, e.g., Lab1C

description
*/

#include <cmath>
#include <iostream>
using namespace std;

void sort3(int a, int b, int c);

int main()
{
	sort3( 3,  2,  1);
}

void sort3(int a, int b, int c)
{
	int temp = 0;
	if(a >= b && a >= c) //if a is biggest
	{
		if(b >= c)		//c b a 
		{
			temp = a;
			a = c;
			b = b;
			c = temp;
		}
		
		else			//b c a
		{
			temp = a;
			a = b;
			b = c;
			c = temp;
		}
	}
	
	else if(b >= a && b >= c) //if b is biggest
	{
		if(a >= c)			// c a b
		{
			temp = a;
			a = c;
			b = temp;
			c = b;
		}
		
		else				//a c b
		{
			temp = b;
			a = a;
			b = c;
			c = temp;
		}
	}
	
	else if(c >= b && c >= a)
	{
		if(a >= b)			//b a c
		{
			temp = a;
			a = b;
			b = temp;
			c = c;
		}
	}
	cout << a << " " << b << " " << c;
}
