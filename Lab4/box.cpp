/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: name, e.g., Lab1C

description
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
	
	for(int j = 0; j < height; j++)		//how many rows
	{
		for(int i = 0; i < width; i++) //prints width amount of starts
		{
			cout << "*";
		}
		cout << endl;					//once line in complete, next line
	}
}