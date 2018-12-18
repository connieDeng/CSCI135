/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: name, e.g., Lab1C

I keeping missing these exercises, I actually have no idea when these are posted
*/

#include <cmath>
#include <iostream>
using namespace std;

int* read_data(int& size);

int main()
{
	int num = 0;
	char charac = ' ';
	int counter = 0;
	
	while(cin >> num >> charac)
	{
		if(charac == 'Q')
		{
			cout << "EXIT";
		}
		counter++;
	}
	
	cout << counter;
	
}

int* read_data(int& size)
{

}