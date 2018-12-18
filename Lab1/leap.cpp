/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: leapyear, e.g., Lab1C

Recieves and year and returns if it is a leapyear.
*/

#include <iostream>
using namespace std;

int main() 
{
	
	//input year
	int year;
    cout << "Enter year: ";	
	cin >> year;
	
	//test if is a leapyear
	if(year % 4 > 0)
	{
		cout << "It is a common year.";
	}

	else if(year % 100 > 0)
	{
		cout << "It is a leap year.";
	}
	
	else if(year % 400 > 0)
	{
		cout << "It is a common year.";
	}
	
	else
	{
		cout << "It is a leap year.";
	} 
}