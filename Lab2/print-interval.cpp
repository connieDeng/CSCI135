/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: print-interval, e.g., Lab1C

Takes user input of a maximum integer and a minimum integer. It then prints the numbers starting from min, and incrementing by 1 to 1 below the max.
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	int min = 0;
	int max = 0;
	
	cout << "Please enter L: ";
	cin >> min;
	cout << "Please enter U: ";
	cin >> max;						//user is setting up the range
	
	int difference = max - min;		//finds the difference between the max and min
	int arr[difference] = {};		//initializes an empty array with a size of the difference.

	for(int i = 0; i < difference; i++) //counts from 0 to 1 less than difference (because <)
	{
		arr[i] = min + i; 			//index 0 is the min, and increments
		cout << arr[i];				// + " ," how come I can't do this???
		cout << " ";				//prints a space between every number
	}
}