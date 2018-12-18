/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Month, e.g., Lab1C

Recieves month and year, returns the number of days in a month taking account leapyears.
*/

#include <iostream>
using namespace std;

int main()
{
	
	//enter in month and year
	//isLeapYear is used as a boolean
	int year, isLeapYear, month;
    cout << "Enter year: ";	
	cin >> year;
 	cout << "Enter month: ";	
	cin >> month;

	//test if the year is a leapyear
	if(year % 4 != 0)
	{
		isLeapYear = 0;
	}

	else if(year % 100 != 0)
	{
		isLeapYear = 1;
	}
	
	else if(year % 400 != 0)
	{
		isLeapYear = 0;
	}
	
	else
	{
		isLeapYear = 1;
	}	

	//test how many days in a month and takes into account leapyears
	if(month == 2 && isLeapYear == 1)
	{
		cout << "29 days";
	}
	
	else if(month == 2 && isLeapYear == 0)
	{
		cout << "28 days";
	}
	
	else if(month == 4 || month == 6 || month == 9 || month == 11)
	{
		cout << "30 days";
	}
	
	else
	{
		cout << "31 days";
	}
}
