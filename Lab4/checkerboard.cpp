/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4 part B, e.g., Lab1C

Make a checkerboard
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	int width = 0;
	int height = 0;
	
	cout << "Input width: ";
	cin >> width;
	cout << endl;
	
	cout << "Input height: ";
	cin >> height;
	cout << endl;
	
	for(int row = 0; row < height; row++)		//how many rows
	{
		for(int col = 0; col < width; col++) //prints width amount of starts
		{
			if(row == 0 || row % 2 == 0)//alternate starting with * or a space
			{
				if(col == 0 || col % 2 == 0) //alternating *
				{
					cout << "*";
				}
					
				else
				{
					cout << " ";
				}
			}
			
			else
			{
				if(col == 0 || col % 2 == 0)
				{
					cout << " ";
				}
					
				else
				{
					cout << "*";
				}
			}
		}
		
		cout <<endl; //next line when line is finished
	}
}