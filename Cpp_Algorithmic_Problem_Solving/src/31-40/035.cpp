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

static int boardY, boardX;

static bool board[10][10];

static vector<vector<pair<int, int>>> rotations;

static void initialize(const vector<pair<int, int>> &init) {
	rotations.clear();
	rotations.push_back(init);

	for (int rot = 0; rot < 3; rot++) {
		
		int maxy, minx = 999;
		for (int i = 0; i < rotations[rot].size(); i++) {
			if (rotations[rot][i].second <= minx){
				maxy = 0;
				if (rotations[rot][i].first >= maxy) {
					maxy = rotations[rot][i].first;
					minx = rotations[rot][i].second;
				}
			}
		}

		vector<pair<int, int>> newRot;
		for (int i = 0; i < rotations[rot].size(); i++) {
			newRot.push_back(
				pair<int, int>(rotations[rot][i].second - minx, -(rotations[rot][i].first - maxy))
			);
		}

		rotations.push_back(newRot);
	}
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
}

static bool putBlock(int y, int x,
					 const vector<pair<int, int>> &block, bool delta) {

	for(int i = 0; i < block.size(); i++) {
		int dy = block[i].first;
		int dx = block[i].second;

		if (dx < 0 || dx >= boardX || dy >= boardY) {
			return false;
		}

		if (board[y + dy][x + dx] == delta) {
			return false;
		}
	}

	for (int i = 0; i < block.size(); i++) {
		int dy = block[i].first;
		int dx = block[i].second;
		
		board[y + dy][x + dx] = delta;
	}

	return false;
}

int best;
static int generate(int left) {

	return 0;
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

		int emptyPlaces = 0;

		for (int i = 0; i < boardY; i++) {
			string tmp;
			Input >> tmp;
			for (int j = 0; j < boardX; j++) {
				if (tmp[j] == '#') {
					board[i][j] = true;
					emptyPlaces++;
				} else {
					board[i][j] = false;
				}
			}
		}	

		vector<pair<int, int>> asd;
		int defy, defx; bool first = false;
		for (int i = 0; i < yy; i++) {
			string tmp;
			Input >> tmp;
			for (int j = 0; j < xx; j++) {
				if(tmp[j] == '#') {
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

		initialize(asd);

		cout << generate(emptyPlaces) << endl;
	}
}