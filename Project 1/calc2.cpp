/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: calc2, e.g., Lab1C

create a multiple +/- calculator program seperated by ;
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
	
	while(cin >> sym)
	{	
		if(sym == '+') 
		{
			cin >> num;
			sum += num;
		}
		
		else if(sym == '-') 
		{
			cin >> num;
			sum -= num;
		}
		
		else if(sym == ';')
		{
			cout << sum << endl;
			cin >> num;
			sum = num;
		}
	}
}
