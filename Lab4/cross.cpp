/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4 C, e.g., Lab1C

Lab 4 C print a cross
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	int input = 0;
	int start = 0;
	int end = 0;
	
	cout << "Input size: ";
	cin >> input;
	end = input;
	cout << endl;
	
	for(int row = 0; row < input; row++)		
	{
		for(int col = 0; col < input; col++) 
		{
		if(row == col || col == (input - row - 1)) //the 2 separate diagnals
			{
				cout << "*";
			}
			
			else
			{
				cout << " ";
			}
		}	
		cout << endl; //next line when line is complete		
	}
}