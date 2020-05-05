#include "002.h"

#define BOARD_SIZE 5

const char BOARD[BOARD_SIZE][BOARD_SIZE] = {
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
		
		bool result = hasWord(x - 1, y - 1, afword) || hasWord(x, y - 1, afword) || hasWord(x + 1, y - 1, afword) ||
					  hasWord(x - 1, y, afword) || hasWord(x + 1, y, afword) || 
					  hasWord(x + 1, y + 1, afword) || hasWord(x, y + 1, afword) || hasWord(x - 1, y + 1, afword);
		return result;
	} else
		return false;

}

void p002() {
	string word = "PRETTY";
	cout << hasWord(1, 1, word) << endl;
}