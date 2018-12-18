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

void sort2(double* p, double* q);

int main()
{
	double x = 1.1;
	double y = 9.2;
	double *num1 = &x;
	double *num2 = &y;
	
	sort2(num2, num1);
	cout << *num1 << " " << *num2; //outputs values of addresses with *
}

void sort2(double* p, double* q)
{
	double* temp = nullptr; //initialize pointer to null
	if(*p > *q)
	{
		temp = p; //temp points to p
		p = q; //p points to q
		q = temp; //q points to temp
	}
}