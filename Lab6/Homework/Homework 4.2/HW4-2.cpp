/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Homework 4.2, e.g., Lab1C

Porblem Solving: Hand-Tracing
*/

#include <iostream>
using namespace std;

int main()
{
   cout << "Enter a positive integer: " << endl;
   int n;
   cin >> n;
   
   while(n > 0)
   {
      int digit = n % 10;
      n = n / 10;
      cout << digit;
   }
   
   if(n < 0)
   {
	   cout << "-";
	   n = n * -1;
	   while(n > 0)
	   {
		  int digit = n % 10;
		  n = n / 10;
		  cout << digit;
	   }
   }
   
   
   cout << endl;

   return 0;
}

