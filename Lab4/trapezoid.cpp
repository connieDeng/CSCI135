/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4 F, e.g., Lab1C

Lab 4 F upside-down trapezoid
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	int width = 0;
	int height = 0;
	int spaces = 0;
	
	cout << "Input width: ";
	cin >> width;
	cout << "Input height: ";
	cin >> height;
	int stars = width;	
	
	cout << endl;
	
	
	if(width - height < (width / 2)) //check if it can be a trapezoid
	{
		cout << "impossible shape";
	}
	
	else
	{
		for(int row = 0; row < height; row++)	
		{	
			for(int i = 0; i < spaces; i++) //print spaces
			{
				cout << " ";
			}
				
			for(int j = 0; j < stars; j++) //print stars
			{
				cout << "*";
			}
				
			spaces += 1; //add one space each iteration
			stars -= 2; //minus 2 stars each iteration
			cout << endl;					//once line in complete, next line
		}
	}

}