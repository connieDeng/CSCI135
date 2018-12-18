/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: smaller3, e.g., Lab1C

Finds the smallest of 3 numbers
*/

#include <iostream>
using namespace std;

int main() 
{
	//input three numbers
	int num1, num2, num3;
    
	cout << "Enter your first integer: ";
    cin >> num1;
	
    cout << "Enter your second integer: ";
    cin >> num2;
	
	cout << "Enter your third integer: ";
    cin >> num3;

	//test for smallest number of the three
    if(num1 <= num2 && num1 <= num3)
    {
		cout << num1;
	}

	else if(num2 <= num1 && num2 <= num3)
	{
		cout << num2;
	}

	else if(num3 <= num1 && num3 <= num2)
	{
		cout << num3;
	}
}