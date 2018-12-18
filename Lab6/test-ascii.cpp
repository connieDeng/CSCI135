/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 6A, e.g., Lab1C

program that tests ascii given a string input
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	string input;
	
	cout << "Input: ";
	getline(cin, input); //recieves all characters until an end-of-line is reached
	
	for(int i = 0; i < input.length(); i++) //parse through the whole string
	{
		cout << input[i] << " " << (int)input[i] << endl; //casting the char into an int so it outputs the ascii number of the char
	}
}