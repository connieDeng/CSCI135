/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab8E, e.g., Lab1C

Task E. Scale image by 200%

*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

void copy2(int out[MAX_H*2][MAX_W*2], int img[MAX_H][MAX_W], int row, int col);

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[2*MAX_H][2*MAX_W], int height, int width) //writing bigger image 2x
{
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

int main() {

	int img[MAX_H][MAX_W]; //your original image
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
	int out[2*MAX_H][2*MAX_W]; //our resulting img will be 2x bigger

	for(int row = 0; row < h; row++) 
	{
		for(int col = 0; col < w; col++) 
		{
			copy2(out, img, row, col); //prints out your original image
		}
	}

	// and save this new image to file "outImage.pgm"
	writeImage(out, (h*2), (w*2)); //write out image h and w are 2x bigger

}

void copy2(int out[MAX_H*2][MAX_W*2], int img[MAX_H][MAX_W], int row, int col)
{
	for(int i = 2*row; i < 2*row+2; i++)
	{
		for(int j = 2*col; j < 2*col+2; j++)
		{
			out[i][j] = img[row][col];
		}
	}
}
