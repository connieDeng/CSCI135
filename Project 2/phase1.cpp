/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: name, e.g., Lab1C

description
*/

#include <fstream>
#include <cmath>
#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{	
	void splitOnSpace(string s, string before, string after); //helper
		
	string input;
	string word;
	string pronunciation;
	string line;
	bool isFound = false;

	cin >> input;

	ifstream myfile; //ifstream reads files
	myfile.open ("cmudict.0.7a.txt"); //opens text file
		
	while(getline(myfile, line))
	{
		splitOnSpace(line, word, pronunciation);
		
		if(input == word)
		{
			cout << "Pronunciation: " << pronunciation << endl;
			isFound = true;
		}
	}
	
	if(isFound == false)
	{
		cout << "word not found" << endl;
	}
	
	return 0;
	
}

void splitOnSpace(string s, string before, string after) 
{
  // reset strings
  before = ""; 
  after = "";
  // accumulate before space
  int i = 0;
  while (i < s.size() && not isspace(s[i])) { before += s[i]; i++; }
  // skip the space
  i++;
  // accumulate after space
  while (i < s.size()) { after += s[i]; i++; }
}