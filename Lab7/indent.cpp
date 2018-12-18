/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab7 B, e.g., Lab1C

Lab 7 B: Counting blocks opened and closed by { and }, and adding real indentation
*/

#include <cmath>
#include <iostream>
using namespace std;

int countChar(string line, char c);
string removeLeadingSpaces(string line);
/**int getNumBlocks(string str);**/

int main()
{
	string line;
    string editted_line;	
	//string newStr;
	int blocks = 0;	//number of open blocks
	int num_tabs = 0;	//number of tabs
	
	while(getline(cin, line))
	{
		editted_line = removeLeadingSpaces(line);
		num_tabs = blocks;
		
		if(editted_line[0] == '}')
		{
			num_tabs = blocks - 1;
		}
	
		for(int i = 0; i < num_tabs; i++)
		{
			cout <<'\t';
		}
		
		cout << editted_line << endl;
		blocks += countChar(line,'{') - countChar(line,'}');
		
		/*ridOfBlock(str, newStr);

		if(newStr[0] == '}')
		{
			for(int i = 0; i < getNumBlocks(str)-1; i++)
			{
				cout << '\t';
			}
		}
		
		else
		{
			for(int i = 0; i < getNumBlocks(str); i++)
			{
				cout << '\t';
			}
		}
			cout << newStr <<endl;*/
	}

}

int countChar(string line, char c) //count how many times a character appears in a  line
{
	int counter = 0;
	
	for(int i = 0; i < line.length(); i++)
	{
		if(line[i] == c)
		{
			counter++;
		}
	}
	
	return counter;
}

string removeLeadingSpaces(string line) //removes space in the beginning of a line
{
	bool isBeginning = true;	//boolean to keep track if first character
	string temp = "";
	
	for(int i = 0; i < line.length(); i++)
	{
		if(isspace(line[i]) == false && isBeginning == true)	//test for when char is NOT a space
		{
			isBeginning = false;
		}
		
		if(isBeginning == false)
		{
			temp += line[i];
		}
	}
	
	return temp;
}

/**int getNumBlocks(string str)
{
	return stoi(str.substr(0, str.find(" "))); //this will grab the first number, or the # of tabs
	//stoi changes the string to an int
}
**/

