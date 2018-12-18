/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: E6.21, e.g., Lab1C

Upper case words come first in vector staying in the same order
*/

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

vector<string> capitalFirst(vector<string> a);

int main()
{
	vector<string> result;
	vector<string> a{ "hello", "Why", "lol" }; 
	
	result = capitalFirst(a);
	
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}

vector<string> capitalFirst(vector<string> a)
{	
	vector<string> capital; //2 vectors to hold uppercase and lowercase strings
	vector<string> lower;
	
	for(int i = 0; i < a.size(); i++)
	{
		//bool isCapital = false;
		//cout << a[i][0]<< " ";
		if(a[i][0] < 65 || a[i][0] > 90) //not uppercase
		{
			lower.push_back(a[i]);
		}
		
		else
		{
			//bool isCapital = true;	//is uppercase
			capital.push_back(a[i]);
		}
	}
	
	for(int i = 0; i < lower.size(); i++)
	{
		capital.push_back(lower[i]); //uppercase vector + lowercase vector
	}
	
	return capital;
}