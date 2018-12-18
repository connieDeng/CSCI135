/*
Author: Connie Deng
Course: CSCI-136
Instructor: Genady Maryash
Assignment: E7.13, e.g., Lab1C

Homework E7.13, reverse char array
*/

#include <cmath>
#include <iostream>

using namespace std;

void reverse(char s[], int size);

int main()
{
	char test[] = {'t','e','s','t'};
	
	reverse(test, 4);
	
	cout << test;
}

void reverse(char s[], int size) //i believe you need the array size
{
	int start = 0;
	int end = size;
	while (start < end) 
    { 
        char temp = s[start];  
        s[start] = s[end]; 
        s[end] = temp; 
        start++; 
        end--; 
    }  
}