/*
Author: Connie Deng
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Lab 5G, e.g., Lab1C

function nextTwinPrime
*/

#include <cmath>
#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d);
bool isPrime(int n);
int nextPrime(int n);
int countPrimes(int a, int b);
bool isTwinPrime(int n);
int largestTwinPrime(int a, int b);
int nextTwinPrime(int n);

int main()
{
	int num = 0;
	int divider = 0;
	cout << "Give number: ";
	cin >> num;
	cout << "Give divider: ";
	cin >> divider;
	
	/*if(isDivisibleBy(num, divider) == true) //testing the function
	{
		cout << "Yes"; //cout this when divisable
	}
	else
	{
		cout << "No"; //cout this when not divisable
	}
	
	cout << isPrime(num);
	cout << nextPrime(num);
	cout << countPrimes(num, divider);
	cout << isTwinPrime(num);
	cout << nextTwinPrime(num);*/
	cout << largestTwinPrime(num, divider);
}

bool isDivisibleBy(int n, int d)
{
	if(d == 0) //make sure the dividend is not 0
	{
		return false;
	}
	
	else if(n % d == 0) //if number does not evenly divide into the divider
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

bool isPrime(int n)
{
	if(n <= 1) //if number is less than or equal to 1 it is NOT prime
	{
		return false;
	}
	
	else 
	{
		for(int i = 2; i <= n-1; i++) //checking if prime
		{
			if(n % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

int nextPrime(int n)
{
	n++; //make sure its checking the next prime
	while(isPrime(n) == false) //if number is not prime keep incrementing until reaching a prime
	{
		n++;
	}
	return n;
}

int countPrimes(int a, int b)
{
	int count = 0; //counter
	for(int i = a; i <= b; i++) //checks numbers within the range
	{
		if(isPrime(i) == true)
		{
			count++; //increment counter everytime there is a found prime number
		}
	}
	return count;
}

bool isTwinPrime(int n)
{
	if(isPrime(n) == true)//must check if number given is prime first
	{
		if(isPrime(n-2) == true || isPrime(n+2) == true) //check if n+2 or n-2 is a prime
		{
			return true;
		}
	
		else
			return false;
	}
	else
		return false;
}

int nextTwinPrime(int n)
{
	int counter = n+1; //number has to be bigger than n
	while(isTwinPrime(counter) == false) //checks if isTwinPrime
	{
		counter++; //if not twinPrime go to next number
	}
	return counter; //if twinPrime return it
}

int largestTwinPrime(int a, int b)
{
	int counter = -1; //if no twin primes in range return -1
	
	for(int i = b; i >=a; i--) //from biggest to smallest
	{
		if(isTwinPrime(i) == true)
		{
			counter = i; //first biggest num hit as twinprime is returned
			return counter;
		}
	}
	return counter; 
}