/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: name, e.g., Lab1C

description
*/

#include <ncurses.h>
#include <cmath>
#include <iostream>
using namespace std;
int sum(int n);
int fact(int n);

int main()
{
	cout << fact(5);

}

int sum(int n)
{
	return(1+n)*(n/2);
}

int fact(int n)
{
	if(n > 1)
		return n * fact(n - 1);
	
	else
        return 1;
}
