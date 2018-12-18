
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bot.h"

using namespace std;

const int MAX_ROWS = 40;	//constant variables
const int MAX_COLS = 40;
const int MAX_NUM = 10;

int ROWS;  // global variables
int COLS;
int NUM;

bool isNextToATree(Dwarf & dwarf, int r, int c);

void onStart(int rows, int cols, int num, std::ostream &log) 
{
	log << "Start!" << endl; // Print a greeting message

	ROWS = rows; // Save values in global variables
	COLS = cols;
	NUM = num;
}

void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) 
{
	// Get current position of the dwarf
	int r = dwarf.row();
	int c = dwarf.col();

	if(isNextToATree(dwarf, r, c) == true)	//only check when tree is next
	{		
		if (dwarf.look(r+1, c) == PINE_TREE || dwarf.look(r+1, c) == APPLE_TREE)	//check direction - chop south
		{
			log << "Found a tree south -- chop" << endl;
			dwarf.start_chop(SOUTH);
		}
		
		if (dwarf.look(r-1, c) == PINE_TREE || dwarf.look(r-1, c) == APPLE_TREE)	//check direction - chop north
		{
			log << "Found a tree north -- chop" << endl;
			dwarf.start_chop(NORTH);
		}
		
		if (dwarf.look(r, c+1) == PINE_TREE || dwarf.look(r, c+1) == APPLE_TREE)	//check direction - chop east
		{
			log << "Found a tree east -- chop" << endl;
			dwarf.start_chop(EAST);
		}
		
		if (dwarf.look(r, c-1) == PINE_TREE || dwarf.look(r, c-1) == APPLE_TREE)	//check direction - chop west
		{
			log << "Found a tree west -- chop" << endl;
			dwarf.start_chop(WEST);
		}
		
		return;
	}
	
	else 
	{
		int rr = 0;
		int cc = 0;
		int range = 0;
		bool isFound = false;
		// Otherwise, move to a random location
		while(isFound == false)
		{
			
			for(int row = r-range; row < r+range; row++)
			{
				for(int col = c-range; col < c+range; col++)
				{
					if(isNextToATree(dwarf, row, col) == true)	//if there is tree go to it
					{
						rr = row;
						cc = col;
						isFound = true;	//exit the loop
					}
				}
			}
			range++;	//if no tree in range, increase range
		}

		
		log << "Walk to " << rr << " " << cc <<endl;
		dwarf.start_walk(rr, cc);
		return;
	}
}

bool isNextToATree(Dwarf & dwarf, int r, int c)	//check if there is tree next
{
	if( dwarf.look(r+1, c) == PINE_TREE || dwarf.look(r+1, c) == APPLE_TREE ||
	dwarf.look(r-1, c) == PINE_TREE || dwarf.look(r-1, c) == APPLE_TREE ||
	dwarf.look(r, c+1) == PINE_TREE || dwarf.look(r, c+1) == APPLE_TREE ||
	dwarf.look(r, c-1) == PINE_TREE || dwarf.look(r, c-1) == APPLE_TREE )
	{
		return true;
	}
	
	else
		return false;
}
