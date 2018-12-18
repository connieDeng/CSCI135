/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab3 TaskC, e.g., Lab1C

user gives interval and program compares elevation from east and west 
*/

#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

//double compare2(double num1, double num2);

int main()
{	
	string startDate = "";
	string endDate = "";
	cout << "Enter starting date: ";
	cin >> startDate;
	cout << "Enter ending date: ";
	cin >> endDate;
	
	string date;
	double eastSt;
	double eastEl;
	double westSt;
	double westEl;
	double compare;

	
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) 
	{
		cerr << "File cannot be opened for reading." << endl;
		exit(1); // exit if failed to open the file
	}	
	
	string junk;        // new string variable
	getline(fin, junk); // read one line from the file 

	
	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
	{ 
		// this loop reads the file line-by-line
		// extracting 5 values on each iteration 
		
		fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
							  //ignorring the remaining columns 

		if(date >= startDate && date <= endDate)
		{
			if(eastEl > westEl)
			{
				cout << date << " " << "East" << endl;
			}
			
			else if(westEl > eastEl)
			{
				cout << date << " " << "West" << endl;
			}
			
			else
			{
				cout << date << " " << "Equal" << endl;
			}
		}
	}

	fin.close();
}

/*double compare2(double num1, double num2) //returns higher number
{
	if (num1 > num2)
	{
		return num1;
	}

	else if (num1 < num2) 
	{
		return num2;
	}
	
	else return 0;
}*/