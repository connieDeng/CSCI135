
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

bool isfenceUp = false;
bool ifmiddle = false;
bool enoughLimber = false;
bool startingFen = false;
int numFences = 0;

//double distances[3] = {0,0,0};

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
bool isNextToPumkpin(Dwarf & dwarf, int r, int c);
Dir directionPickPumpkin(Dwarf & dwarf, int r, int c); //returns direction of tree
//double distanceFromCenter(int r, int c);
double lowestThree(double num1, double num2, double num3);
Dir directionEmpty(Dwarf & dwarf, int r, int c);
bool isNextToFence(Dwarf & dwarf, int r, int c);	//check if there is fence next
int pumpkinOnBoard(Dwarf & dwarf);

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
	
	if(day < 7)
	{
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
			numFences = dwarf.lumber()/10;
				
			find(dwarf, rr, cc, r, c, 'A'); //find APPLE tree
			log << "Walk to " << rr << " " << cc << endl;
			//log << "#FENCES " << numFences << endl; //reports # of fences
			dwarf.start_walk(rr, cc);
		}
		
		if(ifDay(hours, minutes) == false) //night time build fences
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
				isfenceUp = true; //fences are up
			}
		}
		
		if(isfenceUp == true) //as long as fence is up collect apples
		{
			dwarf.start_pick(directionPickApple(dwarf, r, c));
		}
	}
		
	else
	{
		if(ifDay(hours, minutes) == true) //daytime on day 7 cut fence NEEDS TO KNOW WHEN TO STOP CHOPPING
		{	
			if(enoughLimber == true && isNextToAppleTree(dwarf, r, c) == true && dwarf.look(r+1, c) == FENCE) //ready to chop
			{
				dwarf.start_chop(SOUTH);
			}
			
			else if(enoughLimber == true && isNextToAppleTree(dwarf, r, c) == true && dwarf.look(r-1, c) == FENCE) //ready to chop
			{
				dwarf.start_chop(NORTH);
			}
			
			else if(enoughLimber == true && isNextToAppleTree(dwarf, r, c) == true && dwarf.look(r, c+1) == FENCE) //ready to chop
			{
				dwarf.start_chop(EAST);
			}
			
			else if(enoughLimber == true && isNextToAppleTree(dwarf, r, c) == true && dwarf.look(r, c-1) == FENCE) //ready to chop
			{
				dwarf.start_chop(WEST);
			}
			
			else if(dwarf.look(r+1, c) != FENCE && dwarf.look(r-1, c) != FENCE && dwarf.look(r, c-1) != FENCE && dwarf.look(r, c+1) != FENCE)
			{
				isfenceUp = false;
			}
		}
		
		if(pumpkinOnBoard(dwarf) > 1)
		{
			if(ifDay(hours, minutes) == true && isfenceUp == false) //day time collect pumkpin of day 7 dwarves 0-3
			{
					int r = dwarf.row();
					int c = dwarf.col();
			
					if(isNextToPumkpin(dwarf, r,  c) == true) //picking up pumkins
					{
						dwarf.start_pick(directionPickPumpkin(dwarf, r, c));
					}
					
					else
					{
						int rr = 0;
						int cc = 0;
						
						find(dwarf, rr, cc, r, c, 'K');
						log << "Walk to " << rr << " " << cc << endl;
						dwarf.start_walk(rr, cc);	//walk to pumpkins
					}
			}
		}
		
		else
		{	
			if(dwarf.name() == 1 && ifmiddle == false && startingFen == false) //day time on day 7 dwarf 4 is not middle and didnt build first fence
			{
			//log << ifmiddle << endl;
				ifmiddle = true;
			//log << ifmiddle << endl;
				dwarf.start_walk(midr, midc); //dwarf 4 walks to middle
			}
			
			if(dwarf.name() == 1 && ifmiddle == true && startingFen == false)
			{
				dwarf.start_build(NORTH);
			}
			
			if(dwarf.name() == 1 && ifmiddle == true && dwarf.look(r-1,c) == FENCE)
			{
				startingFen = true;
			}
			
			if(ifmiddle == true && startingFen == true)
			{
				int r = dwarf.row();
				int c = dwarf.col();
			
				if(isNextToFence(dwarf, r,  c) == true) //picking up pumkins
				{
					dwarf.start_build(EAST);
				}
					
				else
				{
					int rr = 0;
					int cc = 0;
						
					find(dwarf, rr, cc, r, c, 'F');
					log << "Walk to " << rr << " " << cc << endl;
					dwarf.start_walk(rr, cc);	//walk to pumpkins
				}
			}
			
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

bool isNextToPumkpin(Dwarf & dwarf, int r, int c)	//check if there is pine tree next
{
	if(dwarf.look(r+1, c) == PUMPKIN ||
	dwarf.look(r-1, c) == PUMPKIN ||
	dwarf.look(r, c+1) == PUMPKIN ||
	dwarf.look(r, c-1) == PUMPKIN)
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

bool isNextToFence(Dwarf & dwarf, int r, int c)	//check if there is fence next
{
	if(dwarf.look(r+1, c) == FENCE ||
	dwarf.look(r-1, c) == FENCE ||
	dwarf.look(r, c+1) == FENCE ||
	dwarf.look(r, c-1) == FENCE )
		return true;
	else
		return false;
}

bool ifDay(int hours, int minutes)	//checks if day or night
{
	if(hours >= 7 && hours <= 20 && minutes >= 0 && minutes <= 59) //give 1 hour to build and wait an hour to drop fences
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

Dir directionEmpty(Dwarf & dwarf, int r, int c) //returns empty direction
{
		if (dwarf.look(r+1, c) == EMPTY)	
			return SOUTH;
			
		else if (dwarf.look(r-1, c) == EMPTY)
			return NORTH;
			
		else if (dwarf.look(r, c+1) == EMPTY)
			return EAST;
			
		else if (dwarf.look(r, c-1) == EMPTY)
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
					
					case 'K': //find pumpkin
						if(isNextToPumkpin(dwarf, row, col) == true && ifEmpty(dwarf, row, col) == true) //check if there is space around pine tree
						{
							rr = row;
							cc = col;
							isFound = true;	//exit the loop
						}
					break;
					
					case 'F': //find fence
						if(isNextToFence(dwarf, row, col) == true && (ifEmpty(dwarf, row-1, col) == true))
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

Dir directionPickPumpkin(Dwarf & dwarf, int r, int c) //returns direction of tree
{
		if (dwarf.look(r+1, c) == PUMPKIN)	
			return SOUTH;
			
		else if (dwarf.look(r-1, c) == PUMPKIN)
			return NORTH;
			
		else if (dwarf.look(r, c+1) == PUMPKIN)
			return EAST;
			
		else if (dwarf.look(r, c-1) == PUMPKIN)
			return WEST;
}

/*double distanceFromCenter(int r, int c)
{
	return sqrt(pow((r-middleR),2) + pow((c-middleC),2));
}*/

double lowestThree(double num1, double num2, double num3)
{
	double smallest = 999999.99;
	
	if (num1 < smallest)
		smallest = num1;
	if (num2 < smallest)
		smallest = num2;
	if(num3 < smallest)
		smallest = num3;

	return smallest;
}

int pumpkinOnBoard(Dwarf & dwarf)
{
	int count = 0;
	for(int i = 0; i < ROWS; i ++)
	{
		for(int j = 0; j < COLS; j++)
		{
			if(dwarf.look(i,j) == PUMPKIN)
			{
				count++;
			}
		}
	}
	
	return count;
}