/*
Author: Connie Deng
Course: CSCI-136
Instructor: 
Assignment: Exercise 5.16, e.g., Lab1C

description
*/

#include <cmath>
#include <iostream>
using namespace std;

int zellerCongruence(int dd, int mm, int yyyy);

int main()
{
	int day = 0;
	int month = 0;
	int year = 0;
	int weekday = 0;
	
	cout << "please enter date." << endl << "Enter month in the form of mm: ";
	cin >> month;
	
	cout << "Enter numeric day: ";
	cin >> day;
	
	cout << "Enter year in the form of yyyy: ";
	cin >> weekday;
	
	weekday = zellerCongruence(day,month,year);
	
	if(weekday == 0)
	{
		cout << "Monday";
	}
	else if(weekday == 1)
	{
		cout << "Tuesday";
	}
	else if(weekday == 2)
	{
		cout << "Wednesday";
	}
	else if(weekday == 3)
	{
		cout << "Thursday";
	}	
	else if(weekday == 4)
	{
		cout << "Friday";
	}	
	else if(weekday == 5)
	{
		cout << "Saturday";
	}
	else if(weekday == 6)
	{
		cout << "Sunday";
	}	
	else
	{
		cout << "error";
	}
}

int zellerCongruence(int dd, int mm, int yyyy)
{
	return (dd + 5 + ((26*(mm +1))/10) + 
		((5*(yyyy % 100))/4)+ ((21*(yyyy/100))/4))%7;
}