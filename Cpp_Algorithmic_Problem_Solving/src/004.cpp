#include "004.h"

static const int ROTATION[4][3][2] = {	// information of rotating
	{{0, 0}, {1, 0}, {0, 1}},		    // this rotation assumes that top left blocks are already filled
	{{0, 0}, {0, 1}, {1, 1}},		    // filling forwarded 
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};

static bool** copyBoard(bool** BOARD, const int& row, const int& col) { // copy and return new board same as given board
	bool** board = new bool*[row];
	for (int i = 0; i < row; i++) {
		board[i] = new bool[col];
		for (int j = 0; j < col; j++) {
			board[i][j] = BOARD[i][j];
		}
	}
	return board;
}

static bool check(bool** board, const int& row, const int& col,
	const int &rotation, const int &posx, const int &posy) {			// check if block of given information in board are suitable
	for (int r = 0; r < 3; r++) {
		int x = posx + ROTATION[rotation][r][0];
		int y = posy + ROTATION[rotation][r][1];

		if (x < row && x >= 0)
			if (y < col && y >= 0)
				if (board[x][y]) {
					continue;
				}
		
		return false;
	}
	return true;
}

static int fill_t(bool** board, const int& row, const int& col, int left, int depth) {

	if (left == 0)
		return 1;

	int result = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {	// finding unfilled top left block
			bool EndLoop = false;
			if (board[i][j])			// if found the block, never find more block. (break loop)
				EndLoop = true;

			for (int r = 0; r < 4; r++) {	// apply every kind of rotation
				if (check(board, row, col, r, i, j)) {	// if the rotated block ensure in board
					bool** newBoard = copyBoard(board, row, col);	// make new board filled by rotated block
					for (int b = 0; b < 3; b++) {
						int x = i + ROTATION[r][b][0];
						int y = j + ROTATION[r][b][1];
						newBoard[x][y] = false;
					}

					result += fill_t(newBoard, row, col, left - 3, depth+1); // apply function fill recursively
				}
			}

			if (EndLoop)
				goto ENDLOOP;
		}
	}	ENDLOOP:;

	return result;
};

void p004() {
	int T; // the number of trial
	
	cin >> T;

	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		int maxRow, maxCol; // size of row, column of board
		cin >> maxRow >> maxCol;
		bool** board = new bool*[maxRow];
		int white = 0;
		for (int i = 0; i < maxRow; i++) {	// getting board info
			string s;
			cin >> s;
			board[i] = new bool[maxCol];
			for (int j = 0; j < maxCol; j++) {
				if (s[j] == '.') {
					board[i][j] = true;
					white++;
				}
				else if (s[j] == '#')
					board[i][j] = false;
			}
		}
		if (white % 3 == 0)
			result[trial] = fill_t(board, maxRow, maxCol, white, 0);
		else
			result[trial] = 0;
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}
}