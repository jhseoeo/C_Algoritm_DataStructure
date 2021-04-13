/*
	Problem 035
	ID : BOARDCOVER2
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;
// Y, X board size
static int boardY, boardX;
// empty places of the board
static int wholePiece;
// size of unit block 
static int blockPiece;
// board
static bool board[10][10];
// information of blocks for the every rotating
static vector<vector<pair<int, int>>> rotations;

// fill rotations vector
static void initialize(const vector<pair<int, int>> &init) {
	
	// initialize rotations vector
	rotations.clear();
	rotations.push_back(init);

	for (int rot = 0; rot < 3; rot++) {
		// finding left bottom block
		int maxy = -999, minx = 999;
		for (int i = 0; i < rotations[rot].size(); i++)
			minx = min(minx, rotations[rot][i].second);
		for (int i = 0; i < rotations[rot].size(); i++)
			if (rotations[rot][i].second == minx)
			 	maxy = max(maxy, rotations[rot][i].first);

		// apply rotating
		vector<pair<int, int>> newRot;
		for (int i = 0; i < rotations[rot].size(); i++) {
			newRot.push_back(
				pair<int, int>(rotations[rot][i].second - minx, -(rotations[rot][i].first - maxy))
			);
		}

		rotations.push_back(newRot);
	}
	// removing duplication
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
}

// check if the block can be placed on given position
// compare with board, all blocks differ with delta, it is placable or deplacable
// returns true when block is placable or deplacale
static bool putBlock(int y, int x,
					 const vector<pair<int, int>> &rotate, bool delta) {
	// check if it is placable / deplacable
	for(int i = 0; i < rotate.size(); i++) {
		int dy = y + rotate[i].first;
		int dx = x + rotate[i].second;

		if (dx < 0 || dx >= boardX || dy >= boardY) {
			return false;
		}

		if (board[dy][dx] == delta) {
			return false;
		}
	}

	// place / deplace the block
	for (int i = 0; i < rotate.size(); i++) {
		int dy = rotate[i].first;
		int dx = rotate[i].second;
		
		board[y + dy][x + dx] = delta;
	}

	return true;
}

static int huristic = 0;
static int generate(int leftBlocks) {
	int ret = 0;

	if (leftBlocks < blockPiece)
		return ret;

	// finding left bottom value that is not covered yet
	int y = -1, x = -1;
	for (int i = 0; i < boardY; i++) {
		for (int j = 0; j < boardX; j++) {
			if (board[i][j]) {
				y = i;
				x = j;
				break;
			}
		}
		if (x != -1)
			break;
	}

	if (x == -1)
		return ret;

	// place block and next recursion
	for (int i = 0; i < rotations.size(); i++) {
		if(putBlock(y, x, rotations[i], false)) { 
			ret = max(ret, generate(leftBlocks - blockPiece) + 1);
			putBlock(y, x, rotations[i], true);
		}
	}
	// temporarily place current pos and next recursion
	board[y][x] = false;
	ret = max(ret, generate(leftBlocks - 1));
	board[y][x] = true;

	return ret;
}

void p035() {
	AutomatedInput Input;
	Input.set( 
		"2 "
		"4 7 2 3 "
		"##.##.. "
		"#...... "
		"#....## "
		"#..#### "
		"### "
		"#.. "

		"5 10 3 3 "
		".......... "
		".......... "
		".......... "
		".......... "
		".......... "
		".#. "
		"### "
		"..# "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		int yy, xx;
		Input >> boardY >> boardX >> yy >> xx;

		wholePiece = 0;
		blockPiece = 0;

		// getting board state
		for (int i = 0; i < boardY; i++) {
			string tmp;
			Input >> tmp;
			for (int j = 0; j < boardX; j++) {
				if (tmp[j] == '#') {
					board[i][j] = false;
				} else {
					board[i][j] = true;
					wholePiece++;
				}
			}
		}	

		// getting block state
		vector<pair<int, int>> asd;
		int defy, defx; bool first = false;
		for (int i = 0; i < yy; i++) {
			string tmp;
			Input >> tmp;
			for (int j = 0; j < xx; j++) {
				if(tmp[j] == '#') {
					blockPiece++;
					if(!first) {
						defy = i;
						defx = j;
						asd.push_back(pair<int, int>(0, 0));
						first = true;
					} else {
						asd.push_back(pair<int, int>(i - defy, j - defx));
					}
				}
			}
		}

		huristic = wholePiece / blockPiece;
		initialize(asd);

		cout << generate(wholePiece) << endl;
	}
}