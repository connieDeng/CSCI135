/*
Author: Connie Deng
Course: CSCI-235
Instructor: Mike Zamansky
Assignment 1

Travis testing with summation and factorial
*/

#include <ncurses.h>
#include <cmath>
#include <iostream>
using namespace std;

int sum(int n);
int fact(int n);

int main()
{
	cout << sum(5) << endl << fact(5);
}

int sum(int n)
{
	return (n*(n+1))/2;
}

int fact(int n)
{
	if(n > 1)
		return n * fact(n - 1);
	
	else
        return 1;
}