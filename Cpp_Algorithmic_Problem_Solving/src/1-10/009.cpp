/*
	Problem 008
	ID : JUMPGAME

	
*/

#include <iostream>
#include <vector>
#include <string>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

const int BOARD[7][7] = {
	{2, 5, 1, 6, 1, 4, 1},
	{6, 1, 1, 2, 2, 9, 3},
	{7, 2, 3, 2, 1, 3, 1},
	{1, 1, 3, 1, 7, 1, 2},
	{4, 1, 2, 3, 4, 1, 3},
	{3, 3, 1, 2, 3, 4, 1},
	{1, 5, 2, 9, 4, 7, -1}
};

int board[7][7]; // variables for memoization

bool jump(int n, int x, int y) {
	if (x == n - 1 && y == n - 1)
		return true;
	else if (x >= n || y >= n)
		return false;

	int& ret = board[x][y];
	if (ret == -1) {
		// applying memoization. restore result on variables and use it later.
		ret = jump(n, x + BOARD[x][y], y) || jump(n, x, y + BOARD[x][y]);
	} 

	return ret;

	// version that memoization is not used
	// return jump(n, x + BOARD[x][y], y) || jump(n, x, y + BOARD[x][y]);
}

void p009() {
	for (int i = 0; i < 7; i++) 
		for (int j = 0; j < 7; j++) 
			board[i][j] = -1;

	cout << jump(7, 0, 0) << endl;
}