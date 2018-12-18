
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

bool iffenceUp = false;
bool enoughLimber = false;

int ROWS;  // global variables
int COLS;
int NUM;

bool isNextToPineTree(Dwarf & dwarf, int r, int c);	//check if next to pine tree
bool isNextToAppleTree(Dwarf & dwarf, int r, int c);	//check if next to apple tree
bool ifDay(int hours, int minutes); //checks if day or night
Dir directionChop(Dwarf & dwarf, int r, int c); //returns chop direction
void find(Dwarf & dwarf, int & rr, int & cc, int r, int c, char tree); //find object
bool ifEmpty(Dwarf & dwarf, int r, int c); //check if space is empty (valid)
Dir directionPickApple(Dwarf & dwarf, int r, int c); //returns direction of tree

//need something to check if there is already someone next to the tree

void onStart(int rows, int cols, int num, std::ostream &log) 
{
	log << "Start!" << endl; // Print a greeting message

	ROWS = rows; // Save values in global variables
	COLS = cols;
	NUM = num;
}

void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) 
{	
	int r = dwarf.row();
	int c = dwarf.col();
	
	if(dwarf.lumber() >= 300) //how much wood can be collected
	{
		enoughLimber = true;
	}
	
	if(ifDay(hours, minutes) == true && enoughLimber == false) //daytime and need wood
	{
		// Get current position of the dwarf

		if(isNextToPineTree(dwarf, r,  c) == true) //choppoing trees when need wood
		{
			dwarf.start_chop(directionChop(dwarf, r, c));
		}
		
		else //tree finder
		{
			int rr = 0;
			int cc = 0;

			find(dwarf, rr, cc, r, c, 'P'); //find PINE tree
			log << "Walk to " << rr << " " << cc << endl;
			dwarf.start_walk(rr, cc);
		}
	}
	
	if(enoughLimber == true && isNextToAppleTree(dwarf, r, c) == false) //not next to apple tree 
	{
		int rr = 0;
		int cc = 0;
			
		find(dwarf, rr, cc, r, c, 'A'); //find APPLE tree
		log << "Walk to " << rr << " " << cc << endl;
		dwarf.start_walk(rr, cc);
	}
	
	if(ifDay(hours, minutes) == false)
	{	
		if(enoughLimber == true && isNextToAppleTree(dwarf, r, c) == true && ifEmpty(dwarf, r+1, c) == true) //ready to build
		{
			dwarf.start_build(SOUTH);
		}
		
		else if(enoughLimber == true && isNextToAppleTree(dwarf, r, c) == true && ifEmpty(dwarf, r-1, c) == true) //ready to build
		{
			dwarf.start_build(NORTH);
		}
		
		else if(enoughLimber == true && isNextToAppleTree(dwarf, r, c) == true && ifEmpty(dwarf, r, c+1) == true) //ready to build
		{
			dwarf.start_build(EAST);
		}
		
		else if(enoughLimber == true && isNextToAppleTree(dwarf, r, c) == true && ifEmpty(dwarf, r, c-1) == true) //ready to build
		{
			dwarf.start_build(WEST);
		}
		
		else if(ifEmpty(dwarf, r+1, c) == false && ifEmpty(dwarf, r-1, c) == false && ifEmpty(dwarf, r, c-1) == false && ifEmpty(dwarf, r, c+1) == false)
		{
			dwarf.start_pick(directionPickApple(dwarf, r, c));
		}
	}
		
}

bool isNextToPineTree(Dwarf & dwarf, int r, int c)	//check if there is pine tree next
{
	if(dwarf.look(r+1, c) == PINE_TREE ||
	dwarf.look(r-1, c) == PINE_TREE ||
	dwarf.look(r, c+1) == PINE_TREE ||
	dwarf.look(r, c-1) == PINE_TREE)
		return true;
	else
		return false;
}

bool isNextToAppleTree(Dwarf & dwarf, int r, int c)	//check if there is apple tree next
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
	if(hours >= 6 && hours <= 20 && minutes >= 0 && minutes <= 59) //5 so time to build
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

void find(Dwarf & dwarf, int & rr, int & cc, int r, int c, char tree) //finds object
{
	int range = 0;
	bool isFound = false;

	while(isFound == false)
	{
		
		for(int row = r-range; row < r+range; row++)
		{
			for(int col = c-range; col < c+range; col++)
			{
				switch(tree)
				{
					case 'P': //if tree is pine
						if(isNextToPineTree(dwarf, row, col) == true && ifEmpty(dwarf, row, col) == true) //check if there is space around pine tree
						{
							rr = row;
							cc = col;
							isFound = true;	//exit the loop
						}
					break;
					
					case 'A': 
						if(isNextToAppleTree(dwarf, row, col) == true && (ifEmpty(dwarf, row, col) == true)) //check if there is space around apple tree
						{
							rr = row;
							cc = col;
							isFound = true;	//exit the loop
						}
					break;
					
					default:
					break;
			}
			}
		}
		range++;	//if no tree in range, increase range
	}		
}

bool ifEmpty(Dwarf & dwarf, int r, int c)
{
	if(dwarf.look(r, c) == EMPTY)
		return true;
	else
		return false;
}

Dir directionPickApple(Dwarf & dwarf, int r, int c) //returns direction of tree
{
		if (dwarf.look(r+1, c) == APPLE_TREE)	
			return SOUTH;
			
		else if (dwarf.look(r-1, c) == APPLE_TREE)
			return NORTH;
			
		else if (dwarf.look(r, c+1) == APPLE_TREE)
			return EAST;
			
		else if (dwarf.look(r, c-1) == APPLE_TREE)
			return WEST;
}