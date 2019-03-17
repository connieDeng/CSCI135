#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

const int SIZE = 9; //5+(2*2 borders)
std::string board[SIZE];
//border represented by b
//spaces on board represented by x
char me = 'K'; //represents knight
char visited = '.';
char wall = 'b';
//char goal = '$'; //goal is when all spaces are visited

//initialize board
void load_board(std::string filename, std::string *board)
{
	std::ifstream infile(filename);
	int i = 0;
	while (std::getline(infile, board[i]))
	{
		i++;
		//std::cout << board[i-1];
	}
}

//print board 
void print_board(std::string board[SIZE])
{
	
	std::cout << "[0;0H\n";
	for (int i = 0; i < SIZE; ++i) 
	{
		std::cout << board[i] << "\n";
		//std::cout << board[i][0] << "\n"; prints one char
	}
}

//check if solved (all tiles are visted)
bool isSolved(std::string board[SIZE])
{
	for (int row = 0; row < SIZE; row++) 
	{
		for (int col = 0; col < SIZE; col++) 
		{
			if(board[row][col] != '.' && board[row][col] != 'b')
			{
				//std::cout << "not done";
				return false;
			}
		}
	}
	
	//std::cout << "here";
	return true;
}

void solve(std::string board[SIZE], int row, int col, int &solved)
{
	usleep(20);
	char current = board[row][col];
	//int moves = 0;
	
	if (current == me || current == visited || current == wall)//validation
	{
		return;
	}
		
	if (isSolved(board) == true)
	{
		//std:: cout << "finished";
		solved = 1;
		return;
	}
	
	/* recursively try to solve taking one step in each direction */
	board[row][col] = me; //start at upper left corner
	print_board(board);

	if (!solved) solve(board, row-2, col+1, solved);
	if (!solved) solve(board, row-2, col-1, solved);
	if (!solved) solve(board, row+2, col+1, solved);
	if (!solved) solve(board, row+2, col-1, solved);
	if (!solved) solve(board, row-1, col+2, solved);
	if (!solved) solve(board, row-1, col-2, solved);
	if (!solved) solve(board, row+1, col+2, solved);
	if (!solved) solve(board, row+1, col-2, solved);
	if (!solved) board[row][col] = visited;

}

int main()
{
	int solved = 0;
	load_board("chessBoard.dat",board);
	//print_board(board);
	solve(board, 2, 4, solved);
	//std::cout << isSolved(board);

	return 0;
}

