/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: calc, e.g., Lab1C

create a simple +/- calculator program
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	char sym = 'a';	//tracks +/- SINGLE QUOTES FOR CHAR
	int sum = 0;	//stores sum
	int num = 0;	//stores number
	
	cin >> num;
	sum = num;
	
	while(cin >> sym >> num)
	{
		if(sym == '+') 
		{
			sum += num;
		}
		
		else
		{
			sum -= num;
		}
	}
	cout << sum;
}