/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab3 B, e.g., Lab1C

finds the minimum and maximum storage in East basin in 2016
*/

#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{	
	string date = "";
	double eastSt;
	double min = INT_MAX;
	double max = INT_MIN;
	
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) 
	{
		cerr << "File cannot be opened for reading." << endl;
		exit(1); // exit if failed to open the file
	}	
	
	string junk;        // new string variable
	getline(fin, junk); // read one line from the file 
		
	while(fin >> date >> eastSt)
	{
		// this loop reads the file line-by-line
		// extracting 5 values on each iteration 
		
		fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
								//ignorring the remaining columns 
		
		if(eastSt < min)
		{
			min = eastSt;
		}
	
		if(eastSt > max)
		{
			max = eastSt;
		}
		
	}
	
	cout << "Minimum storage in East basin: " << min << endl;
	cout << "Maximum storage in East basin: " << max;
}