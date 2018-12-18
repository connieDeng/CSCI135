/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: valid, e.g., Lab1C

Takes in an integer in a range and raises it to the second power.
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	
	cout << "Please enter an integer: ";
	cin >> num;						//user inputs an integer
	
	while ((num < 0) || (num > 100) || num == 0 || num == 100) //if num is out of range ask them for another input
	{
		cout << "input a valid number: ";
		cin >> num;
	}
	
	cout << pow(num, 2);			//if valid, the integer is raised to the power of 2
}