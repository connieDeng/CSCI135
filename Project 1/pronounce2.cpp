/*
Author: Connie Deng
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Project2 Phase1 , e.g., Lab1C

Project2 Phase1 
*/

#include <fstream>
#include <cmath>
#include <iostream>
#include <ctype.h>
using namespace std;

//& MEANS REFERENCE OMG
void splitOnSpace(string s, string & before, string & after);
void toLower(string & word);
void toUpper(string & word);

int main()
{
	string input;
	string line; //each line of the file
	string word;
	string pronunciations; //all pronunciations (s for plural)
	string pronunciation; //your chosen word pronunciation
	string identical;
	bool isfound = false;

	cout << "Type word: ";
	cin >> input;

	toLower(input);
  
	ifstream myfile; //ifstream reads files
	myfile.open ("cmudict.0.7a"); //opens text file
	
		while(getline(myfile,line))
		{
			
			splitOnSpace(line, word, pronunciations);
			toLower(word);
		
			if(input == word)
			{
			  cout << "pronunciation: " << pronunciations << endl;
			  pronunciation = pronunciations;
			  isfound = true;
			}

			if(isfound == true)
			{
				if(pronunciations == pronunciation && word != ";;;" && word != input)
				{
						toUpper(word);
						identical += word + " ";
				}
				
			}
		}
		
		cout << "Identical: " << identical;
		
		if(isfound == false)
		{
			cout << "Not found";
		}
	return 0;
}

void splitOnSpace(string s, string & before, string & after) {
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

void toLower(string & word)
{
  for(int i = 0; word[i]; i++)
  {
    word[i] = tolower(word[i]);
  }
}

void toUpper(string & word)
{
  for(int i = 0; word[i]; i++)
  {
    word[i] = toupper(word[i]);
  }
}