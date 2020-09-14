/*
	Problem 011
	ID : TRIANGLEPATH
*/

#include <iostream>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

const int SIZE = 5;

int cache[5][5] = {
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1}
}; // array variable for memoization.

/*int triangle[5][5] = {
	{6, -1, -1, -1, -1},
	{1, 2, -1, -1, -1},
	{3, 7, 4, -1, -1},
	{9, 4, 1, 7, -1},
	{2, 7, 5, 9, 4}
};*/	// board 
int triangle[5][5] = {
		{1, -1, -1, -1, -1},
		{2, 4, -1, -1, -1},
		{8, 16, 8, -1, -1},
		{32, 64, 32, 64, -1},
		{128, 256, 128, 256, 128}
};

int findPath(int y, int x) {
	int& res = cache[y][x];

	if (res != -1)				 
		return res;

	if (y == SIZE - 1)
		return res = triangle[y][x];	// if current posotion is bottom, return its own value.

	int a = triangle[y][x] + findPath(y + 1, x);	 // getting downside maximum 
	int b = triangle[y][x] + findPath(y + 1, x + 1); // getting downside left maximum
	// getting both values and choose bigger one

	return res = (a > b ? a : b); 
}

void p011() {

	cout << findPath(0,0) << endl;
}