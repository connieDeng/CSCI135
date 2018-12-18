/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab3 TaskA, e.g., Lab1C

prints east basin storage given date
*/

#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{	
	string iDate = "";
	cout << "Enter date in MM/DD/YYYY format: ";
	cin >> iDate;
	
	string date;
	double eastSt;
	double eastEl;

	
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

	if(date == iDate)
	{
		cout << "East basin storage: " << eastSt << " billion gallons";
	}
}

fin.close();
}