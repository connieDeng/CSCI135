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
void splitOnSpace(string s, string &before, string &after);
void toUpper(string &word);
int phonemeCounter(string phoneme);
void printArr(string array[], int size);
bool ifFound(string str, char character);
void convertArr(string str, string arr[], int size);

int main()
{
	string input;
	string line; //each line of the file
	string word;
	string pronunciations; //all pronunciations (s for plural)
	string pronunciation; //your chosen word pronunciation
	string identical; //holds all identical words with same phoneme
	string replacePhoneme; //holds all words with one diff 
	string addPhoneme; //holds all add phonemes
	string removePhoneme; //holds all remove phonemes
	bool isfound = false;

	cout << "Type word: ";
	cin >> input;
	toUpper(input);		//input is uppercase

/*--------------------------------PART 1--------------------------------*/
	
	ifstream myfile; //ifstream reads files
	myfile.open ("cmudict.0.7a"); //opens text file
	
		while(getline(myfile,line))
		{
			splitOnSpace(line, word, pronunciations);
		
			if(input == word) //when the word equals input
			{
			  cout << "pronunciation: " << pronunciations << endl;
			  pronunciation = pronunciations;
			  isfound = true;
			}

		}
	
/*--------------------------------PART 2--------------------------------*/
		
		myfile.close();
		myfile.open("cmudict.0.7a"); //reset the file
		
		while(getline(myfile,line))
		{
			splitOnSpace(line, word, pronunciations);
			
			if(isfound == true)
			{
				if(pronunciations == pronunciation && word != ";;;" && word != input)
				{
						toUpper(word);
						identical += word + " ";
				}
				
			}
		}
		
		cout << "Identical: " << identical << endl;

/*--------------------------------PART 3--------------------------------*/

		myfile.close();
		myfile.open("cmudict.0.7a"); //reset the file	
		string before1, after1; //chosen pronounce
		string before2, after2; //other pronounce
		
		while(getline(myfile,line))
		{
			splitOnSpace(line, word, pronunciations);
			splitOnSpace(pronunciation, before1, after1);
			splitOnSpace(pronunciations, before2, after2);
			
			if(phonemeCounter(pronunciation) == phonemeCounter(pronunciations)) //checks if the phoneme of input and phoneme of words are the same length
			{
				int countDiff = 0;
				
				for(int i = 0; i < phonemeCounter(pronunciation); i++)
				{
					splitOnSpace(after1, before1, after1);
					splitOnSpace(after2, before2, after2);
					
					if(before1 != before2)
					{
						countDiff++;
					}
				}
				
				if(countDiff == 1 && ifFound(word, '(') == 0)
				{
					replacePhoneme += word + " ";
				}
			}
		}
		
		cout << "Replace phoneme: " << replacePhoneme << endl;
		
/*--------------------------------PART 4--------------------------------*/

		myfile.close();
		myfile.open("cmudict.0.7a"); //reset the file
		
		while(getline(myfile,line))
		{
			splitOnSpace(line, word, pronunciations);
			splitOnSpace(pronunciation, before1, after1);
			splitOnSpace(pronunciations, before2, after2);
			splitOnSpace(after1, before1, after1);
			splitOnSpace(after2, before2, after2);

			if(phonemeCounter(pronunciations) == phonemeCounter(pronunciation)+1) //checks if the phoneme of input and phoneme of words are the same length
			{
				int countDiff = 0;

				
				for(int i = 0; i < phonemeCounter(pronunciation)+1; i++)
				{						
					if(before1 != before2)
					{
						countDiff++;
						splitOnSpace(after2, before2, after2);
					}
					
					else
					{
						splitOnSpace(after1, before1, after1);
						splitOnSpace(after2, before2, after2);
					}
				}
				
				if(countDiff == 1 && ifFound(word, '(') == 0)
				{
					addPhoneme += word + " ";
				}
			}
		}

		cout << "Add phoneme: " << addPhoneme << endl;
		
/*--------------------------------PART 5--------------------------------*/

		myfile.close();
		myfile.open("cmudict.0.7a"); //reset the file
		
		while(getline(myfile,line))
		{
			splitOnSpace(line, word, pronunciations);
			splitOnSpace(pronunciation, before1, after1);
			splitOnSpace(pronunciations, before2, after2);
			splitOnSpace(after1, before1, after1);
			splitOnSpace(after2, before2, after2);

			if(phonemeCounter(pronunciations) == phonemeCounter(pronunciation)-1) //checks if the phoneme of input and phoneme of words are the same length
			{
				int countDiff = 0;

				
				for(int i = 0; i < phonemeCounter(pronunciation); i++)
				{						
					if(before1 != before2)
					{
						countDiff++;
						splitOnSpace(after1, before1, after1);
					}
					
					else
					{
						splitOnSpace(after1, before1, after1);
						splitOnSpace(after2, before2, after2);
					}
				}
				
				if(countDiff <=1 && ifFound(word, '(') == 0)
				{
					removePhoneme += word + " ";
				}
			}
		}

		cout << "Remove Phoneme: " << removePhoneme << endl;
		
/*--------------------------------IF NOT FOUND--------------------------------*/
		
		if(isfound == false)
		{
			cout << "Not found";
		}
	return 0;
}

void splitOnSpace(string s, string &before, string &after) //helper function
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

int phonemeCounter(string phoneme) //this works properly
{
	int numspaces = 0;
	char nextChar;
	// checks each character in the string
	for (int i=0; i < phoneme.length(); i++)
	{
		nextChar = phoneme.at(i); // gets a character
		if (isspace(phoneme[i]) || phoneme[i] == '\n')
		{
			numspaces++;
		}
	}
	return numspaces;
}

void toUpper(string & word) //helper function that capitalizes a string passed to it
{
  for(int i = 0; word[i]; i++)
  {
    word[i] = toupper(word[i]);
  }
}

void printArr(string array[], int size) //for testing
{
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

void convertArr(string str, string arr[], int size) //converts string to array
{
	string before, after;
	for(int i = 0; i < size; i++)
	{
		splitOnSpace(str, before, after);
		arr[i] = before;
		str = after;
	}
}

bool ifFound(string str, char character)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == character)
		{
			return true;
		}
	}
	
	return false;
}