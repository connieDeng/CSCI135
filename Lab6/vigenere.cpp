/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 6C, e.g., Lab1C

Implementing Vigenere cipher encryption
*/

#include <cmath>
#include <iostream>
using namespace std;

int calcShift(char c);
char shiftChar(char c, int rshift);
string encryptVigenere(string plaintext, string keyword);

int main()
{
	string plaintext;
	string keyword;
	
	cout << "Enter plaintext: ";
	getline(cin, plaintext); //recieves all characters until an end-of-line is reached
	
	cout << "Enter keyword: ";
	cin >> keyword;
	
	cout << "Ciphertext: " << encryptVigenere(plaintext, keyword);
}

int calcShift(char c) //calculates shift of character
{
	if(c >= 'a' && c <= 'z')
	{
		return c-'a';
	}
	
	if(c >= 'A' && c <= 'Z')
	{
		return c-'A';
	}
}

char shiftChar(char c, int rshift) //does the shifting of one char
{
	rshift = rshift % 26;
	
	if(c >= 'A'&& c <='Z') //check if its uppercase letter
	{
		if(c+rshift > 'Z')
		{
			return c+rshift-26;
		}
	}
	
	else if(c >= 'a' && c <= 'z') //check if its lowercase letter
	{
		if(c+rshift > 'z')
		{
			return c+rshift-26;
		}
	}
	
	else	//checks if anything other than letter
		return c;
}

string encryptVigenere(string plaintext, string keyword) //does the vigenere cipher encryption on a whole string
{
	int keywordIndex = 0;
	
	for(int i = 0; i < plaintext.length(); i++)
	{
		if((plaintext[i] >= 'a' && plaintext[i] <= 'z') || (plaintext[i] >= 'A' && plaintext[i] <= 'Z')) //makes sure it's a letter
		{
			plaintext[i] = shiftChar(plaintext[i], calcShift(keyword[keywordIndex]));
			keywordIndex++;
			
			if(keywordIndex >= keyword.length())
			{
				keywordIndex = 0;
			}
		}
	}
	
	return plaintext;
}