/*
	Problem 029
	ID : BLOCKGAME
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

/*
Board Order
0	1	2	3	4 
5	6	7	8	9
10	11	12	13	14
15	16	17	18	19
20	21	22	23	24
*/

// shapes of every blocks
static const int SHAPES[6][3][2] = {
	{ {0, 0}, {1, 0}, {999, 999} },
	{ {0, 0}, {0, 1}, {999, 999} },
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {0, 1}, {-1, 1} },
	{ {0, 0}, {1, 0}, {0, 1} },
};

// return whether block of given shape is placable on given position
bool placable(const int &state, const int &shape, const int &pos) {
	const int x = pos % 5;
	const int y = pos / 5;
	
	for (int i = 0; i < 3; i++) {
		if (SHAPES[shape][i][0] == 999)
			continue;

		const int dx = x + SHAPES[shape][i][0];
		const int dy = y + SHAPES[shape][i][1];

		if (dx < 0 || dx > 4 || dy > 4)
			return false;

		if ((state & (1 << (dy * 5 + dx))) != 0)
			return false;
	}

	return true;
}

// all placable blocks in initial state.
vector<int> moves;
// calculate before run function
static void precalc(const int &state) {
	for (int i = 0; i < 24; i++) {
		const int x = i % 5;
		const int y = i / 5;

		for(int j = 0; j < 6; j++) {
			int newState = 0;

			if (!placable(state, j, i))
				continue;

			for(int k = 0; k < 3; k++) {
				if (SHAPES[j][k][0] == 999)
					continue;
				
				const int dx = x + SHAPES[j][k][0];
				const int dy = y + SHAPES[j][k][1];
				newState = newState | (1 << (dy * 5 + dx));
			}

			moves.push_back(newState);
		}
	}
}

// cache
// return type of function must be char to express TRUE, FALSE, and initial state
static char cache[1 << 25];
// return if there is at least a case that user of this turn can win
static char play(int state) {
		
	char& ret = cache[state];
	if (ret != -1) return ret;
	ret = 0;
	
	for(int i = 0; i < moves.size(); i++) {

		// for the placable blocks
		if((moves[i] & state) == 0)
			if (!play(state | moves[i])) {
				ret = 1;
				break;
			}
	}

	return ret;
}

void p029() {

	AutomatedInput Input;
	Input.set(
		"3 "
		"..... "
		".##.. "
		"##..# "
		"#.### "
		"..#.. "

		"..... "
		"..... "
		"..... "
		"..... "
		"..... "

		"#..## "
		"##.## "
		"##.## "
		"#...# "
		"##.## "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		string tmp;
		int state = 0;
		for (int i = 0; i < 5; i++) {
			Input >> tmp;
			for (int j = 0; j < 5; j++) {
				state = state | ((tmp[j] == '#' ? 1 : 0) << (i * 5 + j));
			}
		}
		for (int i = 0; i < (1 << 25); i++) {
			cache[i] = -1;
		}

		precalc(state);
		//cout << availablity(state, 0, 23) << endl;
		cout << (play(state) ? "WINNING" : "LOSING") << endl;
	}
}