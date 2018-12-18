/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 6D, e.g., Lab1C

Decryption with caesar and vigenere
*/

#include <cmath>
#include <iostream>
using namespace std;

int calcShift(char c);
char shiftChar(char c, int rshift);
string encryptCaesar(string plaintext, int rshift);
string encryptVigenere(string plaintext, string keyword);
string decryptCaesar(string ciphertext, int rshift);
string decryptVigenere(string ciphertext, string keyword);

int main()
{
	int shift = 0;	
	string plaintext;
	string keyword;
	
	cout << "Enter plaintext: ";
	getline(cin, plaintext); //recieves all characters until an end-of-line is reached
	cout << endl;
	
	cout << "= Caesar =" << endl;
	cout << "Enter shift: ";
	cin >> shift;
	cout << "Ciphertext: " << encryptCaesar(plaintext, shift) << endl;
	cout << "Decrypted: " << decryptCaesar(encryptCaesar(plaintext, shift), shift) << endl;
	
	cout << endl;
	cout << "= Vigenere =" << endl;
	cout << "Enter keyword: ";
	cin >> keyword;
	cout << "Ciphertext: " << encryptVigenere(plaintext, keyword) << endl;
	cout << "Decrypted: " << decryptVigenere(encryptVigenere(plaintext, keyword), keyword);
	
	
	
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

char shiftChar(char c, int rshift)
{
	rshift = rshift % 26;
	
	if(rshift >= 0) //shift is positive
	{
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
	
	if(rshift < 0) //shift is negative
	{
		if(c >= 'A'&& c <='Z') //check if its uppercase letter
		{
			if(c+rshift < 'A')
			{
				return c+rshift+26;
			}
		}
		
		else if(c >= 'a' && c <= 'z') //check if its lowercase letter
		{
			if(c+rshift < 'a')
			{
				return c+rshift+26;
			}
		}
		
		else	//checks if anything other than letter
			return c;
	}
}

string encryptCaesar(string plaintext, int rshift)
{
	for(int i = 0; i < plaintext.length(); i++) //parses string and encrypts it 
	{
		plaintext[i] = shiftChar(plaintext[i],rshift);
	}
	
	return plaintext;
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

string decryptCaesar(string ciphertext, int rshift)
{
	for(int i = 0; i < ciphertext.length(); i++) //parses string and encrypts it 
	{
		ciphertext[i] = shiftChar(ciphertext[i],(rshift*-1));
	}
	
	return ciphertext;
}

string decryptVigenere(string plaintext, string keyword)
{
	int keywordIndex = 0;
	
	for(int i = 0; i < plaintext.length(); i++)
	{
		if((plaintext[i] >= 'a' && plaintext[i] <= 'z') || (plaintext[i] >= 'A' && plaintext[i] <= 'Z')) //makes sure it's a letter
		{
			plaintext[i] = shiftChar(plaintext[i], (calcShift(keyword[keywordIndex])*-1));
			keywordIndex++;
			
			if(keywordIndex >= keyword.length())
			{
				keywordIndex = 0;
			}
		}
	}
	
	return plaintext;
}