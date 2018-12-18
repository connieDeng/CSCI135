/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: fibonacci, e.g., Lab1C

Fibonacci
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	int fib[60] = {};
	fib[0] = 0; 			//set index 0 to 0
	fib[1] = 1;				//set index 1 to 1
	int count = 0;
	
	cout << fib[0] << "\n" << fib[1] << "\n";
	
	for (int i = 2; i < 60; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
		cout << fib[i] << "\n";
	}
}

/*	
	Observation and Explaination
		Due to declaring the array to be an int array, there is 4 bytes or 32 bits stored for each int. This means, that 
		for a signed binary int, the highest number value that can be stored in the int is 2^31 which is 2,147,483,647 
		(one bit is used for - +). Once the values are larger than 2 billion there begins to be an overflow error causing 
		unintended results.
*/