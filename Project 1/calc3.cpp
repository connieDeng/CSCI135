/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: calc3, e.g., Lab1C

create a multiple +/- calculator program seperated by ; and takes into account ^
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	char prevSym = '+';			//always positive because squared
	char nextSym = ';';
	int num = 0;
	int sum = 0;

	while (cin >> num) 			//while there are still numbers, grabs number
	{
		cin >> nextSym;			//grabs next symbol which is either +, -, or ^
		
		if (nextSym == '^')		//if squared
		{
			num = pow(num,2);
			cin >> nextSym;		//grabs next symbol after ^ when finished
		}
		
		if (prevSym == '+')
		{
			sum += num;
		}
		
		else if (prevSym == '-') 
		{
			sum -= num;
		}
		
		prevSym = nextSym;			//grabs next symbol
		
		if (nextSym == ';') 
		{
			cout << sum << endl;		//if ; reset everything
			prevSym = '+';
			num = 0;
			sum = 0;
		}
	}
	return 0;
}