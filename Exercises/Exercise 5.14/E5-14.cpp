/*
Author: Connie Deng
Course: CSCI-136
Instructor: Genady Maryash
Assignment: E5.14, e.g., Lab1C

E5.14
*/

#include <cmath>
#include <iostream>
using namespace std;

void sort2(int a, int b);

int main()
{
	sort2(1,2);
}

void sort2(int a, int b)
{
	int temp = 0;
	if(a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	
	cout << a << " " << b;
}