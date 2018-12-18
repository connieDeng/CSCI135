/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: edit-array, e.g., Lab1C

Create an editable array of 10 integers.
*/

#include <cmath>
#include <iostream>
using namespace std;

bool isIndexInRage(int min, int max, int val) //check if the index inputted is in range
{
	if((val < min) || (val >= max))
	{
		return false;
	}
	
	else
	{
		return true;
	}
}

int main()
{
	int minRage = 0;
	int maxRange = 10;
	int arr[10] = {};
	int index = 0;
	int value = 0;
	
	for(int i = 0; i < 10; i++) //create an array full of 1s
	{
		arr[i] = 1;
	}
	
	do
	{		
			for(int i = 0; i < 10; i++)
			{
				cout << arr[i] << " ";
			}
			
			cout << endl;
			cout << "input index: ";
			cin >> index;
			cout << "enter value: ";
			cin >> value;		//user input
			
			if(isIndexInRage(minRage, maxRange, index) == true)
			{
				arr[index] = value;		//if index is in range change index value to user value
			}
	}
	while(isIndexInRage(minRage, maxRange, index) == true); //repeat if true

	
}