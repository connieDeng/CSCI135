
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bot.h"

using namespace std;

const int MAX_ROWS = 40;	//constant variables
const int MAX_COLS = 40;
const int MAX_NUM = 10;
const int midr = MAX_ROWS/4;
const int midc = MAX_COLS/4;

bool enoughLimber = false;

int ROWS;  // global variables
int COLS;
int NUM;

bool isNextToPineTree(Dwarf & dwarf, int r, int c);	//check if next to pine tree
bool isNextToAppleTree(Dwarf & dwarf, int r, int c);	//check if next to apple tree
bool ifDay(int hours, int minutes);
Dir directionChop(Dwarf & dwarf, int r, int c);
void find();

void onStart(int rows, int cols, int num, std::ostream &log) 
{
	log << "Start!" << endl; // Print a greeting message

	ROWS = rows; // Save values in global variables
	COLS = cols;
	NUM = num;
}

void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) 
{
	if(dwarf.lumber() >= 300)
	{
		enoughLimber = true;
	}
	
	if(ifDay(hours, minutes) == true)
	{
		// Get current position of the dwarf
		int r = dwarf.row();
		int c = dwarf.col();

	
		if(isNextToPineTree(dwarf, r,  c) == true) //if next to tree chop
		{
			dwarf.start_chop(directionChop(dwarf, r, c));
		}
		
		else //tree finder
		{
			int rr = 0;
			int cc = 0;
			
			//initialize pointers 
			int *prr = 0;
			int *pcc = 0;
			
			//assigning pointers
			prr = &rr;
			pcc = &cc;
			
			/*
				int x = 5;
				int *p = &x;
				cout << *p << endl;
			*/

			

			
			log << "Walk to " << rr << " " << cc <<endl;
			dwarf.start_walk(rr, cc);
		}
	}
	
		
}

bool isNextToPineTree(Dwarf & dwarf, int r, int c)	//check if there is tree next
{
	if(dwarf.look(r+1, c) == PINE_TREE ||
	dwarf.look(r-1, c) == PINE_TREE ||
	dwarf.look(r, c+1) == PINE_TREE ||
	dwarf.look(r, c-1) == PINE_TREE)
		return true;
	else
		return false;
}

bool isNextToAppleTree(Dwarf & dwarf, int r, int c)	//check if there is tree next
{
	if(dwarf.look(r+1, c) == APPLE_TREE ||
	dwarf.look(r-1, c) == APPLE_TREE ||
	dwarf.look(r, c+1) == APPLE_TREE ||
	dwarf.look(r, c-1) == APPLE_TREE )
		return true;
	else
		return false;
}

bool ifDay(int hours, int minutes)	//checks if day or night
{
	if(hours >= 6 && hours <= 21 && minutes >= 0 && minutes <= 59)
		return true;
	else
		return false;
}

Dir directionChop(Dwarf & dwarf, int r, int c) //returns direction of tree
{
		if (dwarf.look(r+1, c) == PINE_TREE)	
			return SOUTH;
			
		else if (dwarf.look(r-1, c) == PINE_TREE)
			return NORTH;
			
		else if (dwarf.look(r, c+1) == PINE_TREE)
			return EAST;
			
		else if (dwarf.look(r, c-1) == PINE_TREE)
			return WEST;
}

void find()
{
	
}
