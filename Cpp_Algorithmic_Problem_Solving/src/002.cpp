/*
	Problem 002
	ID : BOGGLE

	From given 5x5 alphabet board,
	finding letters by moving adjacent alphabet one by one.
*/

#include <iostream>
#include <string>
#include "Problems.h"

using namespace std;

#define BOARD_SIZE 5

static const char BOARD[BOARD_SIZE][BOARD_SIZE] = { // 5x5 alphabet board
	{'U', 'R', 'L', 'P', 'M'},
	{'X', 'P', 'R', 'E', 'T'},
	{'G', 'I', 'A', 'E', 'T'},
	{'X', 'T', 'N', 'Z', 'Y'},
	{'X', 'O', 'Q', 'R', 'S'}
};

static bool hasWord(int x, int y, string word) {
	if (word.length() == 0) return false;
	else if (x <= 0 || x >= BOARD_SIZE) return false;
	else if (y <= 0 || y >= BOARD_SIZE) return false;

	if (BOARD[x][y] == word[0]) {
		if (word.length() == 1) return true;
		string afword = word.substr(1);
		
		bool result = hasWord(x - 1, y - 1, afword) || hasWord(x, y - 1, afword) || hasWord(x + 1, y - 1, afword) || // execute recursion at adjacent alphabet
					  hasWord(x - 1, y, afword) || hasWord(x + 1, y, afword) || 
					  hasWord(x + 1, y + 1, afword) || hasWord(x, y + 1, afword) || hasWord(x - 1, y + 1, afword);
		return result;
	} else
		return false;

}

void p002() {
	string word = "PRETTY"; // word that we have to find from board.
	cout << hasWord(1, 1, word) << endl;
}