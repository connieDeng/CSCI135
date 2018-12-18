/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: smaller, e.g., Lab1C

input two integers and return the smaller of the two integers
*/

#include <iostream>
using namespace std;

int main() 
{
	int num1, num2;
	cout << "Enter your first integer: "; 
	cin >> num1;
	cout << "Enter your second integer: "; 
	cin >> num2;

	if(num1 < num2)
	{	
		cout << num1;
	}

	else
	{
		cout << num2;
	}

	//compare2(num1, num2);
}

/*int compare2(int x, int y)
{
	if (x < y)
	{
		cout << y;
	}

	else 
	{
		cout << x;
	}
}*/