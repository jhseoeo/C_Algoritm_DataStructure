/*
	Problem 037
	ID : KAKURO2
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// two types of direction. HORIZONTAL one and VERTICAL one.
static enum class Direction { HORIZONTAL, VERTICAL };
// two types of color. BLACK one and WHITE one.
static enum class Color { BLACK, WHITE, };
// hint type. consists with pair type that indicates position and direction
using Hint = pair<pair<int, int>, Direction>;
// list of hints
static vector<Hint> Hints;
// sum of all number for each hints
static map<Hint, int> sumHint;
// size of number for each hints
static map<Hint, int> sizeHint;
// bitmap of used numbers for each hints
static map<Hint, int> usedNumHint;
// number of hint
static int numHints;
// width and height size of board
static int boardSize;
// board recorded colors
static Color board[20][20];
// board recorded answer
static int answer[20][20];

// get number of candidates of hint
static int getNumCandidates(const Hint &h) {
	int start = (h.second == Direction::VERTICAL ? h.first.first : h.first.second);
	int res = 0;

	for (int i = 1; start + i < boardSize; i++) {
		// setting X and Y pos of board
		int posY = (h.second == Direction::VERTICAL ? start + i : h.first.first);
		int posX = (h.second == Direction::VERTICAL ? h.first.second : start + i);

		// for only black cells
		if (board[posY][posX] != Color::WHITE) {
			break;
		}

		// for uncoverd cell
		if (answer[posY][posX] == 0) {
			res++;
		}
	}

	return res;
}

// find hints applying to given pos and directions
static Hint findBoardHint(const pair<int, int> &pos, Direction dir) {
	int i = 1, posY, posX;

	// until hint is found
	do {
		posY = (dir == Direction::VERTICAL ? pos.first - i : pos.first);
		posX = (dir == Direction::VERTICAL ? pos.second : pos.second - i);
		i++;
	} while (!sumHint[{ {posY, posX}, dir}]);

	return { {posY, posX}, dir };
}

// get size from bitmask of candidates 
static int getSize(int bitmask) {
	int size = 0;
	for (int i = 1; i <= 9; i++) {
		if (bitmask & (1 << i)) {
			size++;
		}
	}

	return size;
}

// get sum from bitmask of candidates 
static int getSum(int bitmask) {
	int sum = 0;
	for (int i = 1; i <= 9; i++) {
		if (bitmask & (1 << i)) {
			sum += i;
		}
	}

	return sum;
}

// array of candidates memoization by sum, size and used number
static int candidates[10][46][1024];
// fill candidates array
static void generateCandidates() {
	memset(candidates, 0, sizeof(candidates));
	 
	// traverse all candidates
	for (int set = 0; set < 1024; set += 2) {
		int subset = set;
		int l = getSize(set), s = getSum(set);
		
		// 
		while (true) {
			candidates[l][s][subset] |= (set & ~subset);
			if (subset == 0) break;
			subset = (subset - 1) & set;
		}
	}
}

// put number on the board 
static void put(int y, int x, int val) {
	answer[y][x] = val;
	board[y][x] = Color::BLACK;
	usedNumHint[findBoardHint({ y, x }, Direction::HORIZONTAL)] |= (1 << val);
	usedNumHint[findBoardHint({ y, x }, Direction::VERTICAL)] |= (1 << val);
}

// remove number on the board 
static void remove(int y, int x, int val) {
	answer[y][x] = 0;
	board[y][x] = Color::WHITE;
	usedNumHint[findBoardHint({ y, x }, Direction::HORIZONTAL)] &= ~(1 << val);
	usedNumHint[findBoardHint({ y, x }, Direction::VERTICAL)] &= ~(1 << val);
}

// get candidates by given hint
static int getCandHint(Hint hint) {
	int siz = sizeHint[hint];
	int sum = sumHint[hint];
	int used = usedNumHint[hint];

	int tmp = candidates[sizeHint[hint]][sumHint[hint]][usedNumHint[hint]];
	return candidates[sizeHint[hint]][sumHint[hint]][usedNumHint[hint]];
}

// get candidates by given pos
static int getCandPos(int y, int x) {
	return getCandHint(findBoardHint( {y, x}, Direction::HORIZONTAL ))
		& getCandHint(findBoardHint( {y, x}, Direction::VERTICAL ));
}

// print answer board
static void printBoard() {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
}

static bool fillBoard() {

	// find uncovered cell that has minimum candidates
	int y = -1, x = -1, minCands = 1023;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (board[i][j] == Color::WHITE) {
				int cands = getCandPos(i, j);
				if(getSize(minCands) > getSize(cands)) {
					minCands = cands;
					y = i; x = j;
				}
			}
		}
	}

	// if there is a uncovered cell that has no candidates something goes wrong
	if (minCands == 0) return false;

	// if there is no uncovered cell, print the board
	if (y == -1) {
		printBoard();
		return true;
	}

	// fill current cell and call next recursion.
	for (int val = 1; val <= 9; val++) {
		if (minCands & (1 << val)) {
			put(y, x, val);
			if (fillBoard()) return true;
			remove(y, x, val);
		}
	}

	return false;
}

void p037() {
	AutomatedInput Input;
	Input.set(
		"1 "
		"8 " // size of board
		"0 0 0 0 0 0 0 0 " // 0 is black or hint cell
		"0 1 1 0 0 1 1 1 " // 1 is white cell
		"0 1 1 0 1 1 1 1 "
		"0 1 1 1 1 1 0 0 "
		"0 0 1 1 0 1 1 0 "
		"0 0 0 1 1 1 1 1 "
		"0 1 1 1 1 0 1 1 "
		"0 1 1 1 0 0 1 1 "
		"24 "	// number of hint
		"2 1 0 16 " // y, x, direction, sum
		"2 5 0 24 " // y, x means position of hint
		"3 1 0 17 " // direction indicates hints are horizontal or vertical hint
		"3 4 0 29 " // 1 means vertical hint
		"4 1 0 35 " // 0 means horizontal hint
		"5 2 0 7 " 
		"5 5 0 8 "
		"6 3 0 16 "
		"7 1 0 21 "
		"7 6 0 5 "
		"8 1 0 6 "
		"8 6 0 3 "
		"1 2 1 23 "
		"1 3 1 30 "
		"1 6 1 27 "
		"1 7 1 12 "
		"1 8 1 16 "
		"2 5 1 17 "
		"3 4 1 15 "
		"4 7 1 12 "
		"5 5 1 7 "
		"5 8 1 7 "
		"6 2 1 11 "
		"6 3 1 10 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		int leftCells = 0;
		Input >> boardSize;
		
		memset(answer, 0, sizeof(answer));

		// getting color of board
		for (size_t i = 0; i < boardSize; i++) {
			for (size_t j = 0; j < boardSize; j++) {
				int tmp;
				Input >> tmp;
				board[i][j] = (Color)tmp;
				if (board[i][j] == Color::WHITE)
					leftCells++;
			}
		}

		// getting hints
		Input >> numHints;
		int y, x, dir, sum;
		for (size_t i = 0; i < numHints; i++) {
			Input >> y >> x >> dir >> sum;
			Hint h = {pair<int, int>(y-1, x-1), (Direction)dir};
			Hints.push_back(h);
			sumHint.insert({ h, sum });
			sizeHint.insert({ h, getNumCandidates(h) });
		}

		generateCandidates();
		sort(Hints.begin(), Hints.end(),
			[](const Hint& a, const Hint& b) { return sizeHint[a] < sizeHint[b]; });

		fillBoard();
	}
};