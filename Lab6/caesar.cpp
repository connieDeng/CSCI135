/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 6B, e.g., Lab1C

Implementing Caesar cipher encryption
*/

#include <cmath>
#include <iostream>
using namespace std;

char shiftChar(char c, int rshift);
string encryptCaesar(string plaintext, int rshift);

int main()
{
	string plaintext;
	int rightShift = 0;    
	cout << "Enter plaintext: ";
	getline(cin, plaintext); //recieves all characters until an end-of-line is reached
	cout << "Enter shift: ";
	cin >> rightShift;
	cout << "Ciphertext: " << encryptCaesar(plaintext, rightShift);
	
}

char shiftChar(char c, int rshift)
{
	rshift = rshift % 26;
	
	if(c >= 'A'&& c <='Z') //check if its uppercase letter
	{
		if(c+rshift > 'Z')
		{
			//cout << "WHATTTA" << endl;
			
			return c+rshift-26;
		}

	}
	
	else if(c >= 'a' && c <= 'z') //check if its lowercase letter
	{
		if(c+rshift > 'z')
		{
			//cout << "what" << endl;
			return c+rshift-26;
		}
		//return 'a';
		//cout << "OUTTA DA CONDITIONS" << endl;
	}
	
	else	//checks if anything other than letter
		return c;
}

string encryptCaesar(string plaintext, int rshift)
{
	for(int i = 0; i < plaintext.length(); i++) //parses string and encrypts it 
	{
		plaintext[i] = shiftChar(plaintext[i],rshift);
	}
	
	return plaintext;
}