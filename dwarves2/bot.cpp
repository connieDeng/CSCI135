
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
bool ifmoved[6] = { false, false, false, false, false, false }; //boolean array for moved
bool ifBuild[6] = { false, false, false, false, false, false }; //boolean array for build

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
	if(dwarf.lumber() >= 300)
	{
		enoughLimber = true;
	}
	
	if(enoughLimber == false)
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
		}
	}
	
	else	//once enough timber
	{
		if(ifmoved[0] == false && dwarf.name() == 0)	//have all dwarves line to the left
		{
			dwarf.start_walk(0, 1);
			ifmoved[0] = true;
		}
		
		if(ifmoved[1] == false && dwarf.name() == 1)
		{
			dwarf.start_walk(1, 1);
			ifmoved[1] = true;
		}
		
		if(ifmoved[2] == false && dwarf.name() == 2)
		{
			dwarf.start_walk(2, 1);
			ifmoved[2] = true;
		}
		
		if(ifmoved[3] == false && dwarf.name() == 3)
		{
			dwarf.start_walk(3, 1);
			ifmoved[3] = true;
		}
		
		if(ifmoved[4] == false && dwarf.name() == 4)
		{
			dwarf.start_walk(4, 1);
			ifmoved[4] = true;
		}
		
		if(ifmoved[5] == false && dwarf.name() == 5)
		{
			dwarf.start_walk(5, 1);
			ifmoved[5] = true;
		}
		
		else 
		{	
			if(ifBuild[dwarf.name()] == false)	//build to the west
			{
				dwarf.start_build(WEST);
				ifBuild[dwarf.name()] = true;
			}
			else {
				dwarf.start_walk(dwarf.row(), dwarf.col()+1); //move one to left
				ifBuild[dwarf.name()] = false;//toggle build west
			}
		}
		
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


