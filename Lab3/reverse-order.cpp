/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab3 TaskD, e.g., Lab1C

user inputs interval and info about west basin elevation is printed in reverse 
*/

#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{	
	string earlyDate = "";
	string lateDate = "";
	
	cout << "Enter earlier date: ";
	cin >> earlyDate;
	cout << "Enter later date: ";
	cin >> lateDate;
	
	string date;
	double eastSt;
	double eastEl;
	double westSt;
	double westEl;
	
	int counter = 0;
	string dateArr[500] = {};
	double westElArr[500] = {};
	
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
		
		if(date >= earlyDate && date <= lateDate)
		{
			dateArr[counter] = date;
			westElArr[counter] = westEl;
			counter++;
		}
	}
	
	for(int i = counter; i >= 0; i--)
	{
		cout << dateArr[i] << " " << westElArr[i] << " ft" << endl;
	}

}