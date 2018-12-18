/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab7 A, e.g., Lab1C

Task A Removing indentation
*/

#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string removeLeadingSpaces(string line);

int main()
{
	string str;
    
	while(getline(cin, str))
	{
		cout << removeLeadingSpaces(str) << endl;
	}
}

string removeLeadingSpaces(string line)
{
	bool isBeginning = true;	//boolean to keep track if first character
	string temp = "";
	
	for(int i = 0; i < line.length(); i++)
	{
		if(isspace(line[i]) == false && isBeginning == true)	//test for when char is NOT a space
		{
			isBeginning = false;
		}
		
		if(isBeginning == false)
		{
			temp += line[i];
		}
	}
	
	return temp;
}