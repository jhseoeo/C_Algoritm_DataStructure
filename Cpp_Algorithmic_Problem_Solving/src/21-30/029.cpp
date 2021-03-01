/*
	Problem 029
	ID : BLOCKGAME
*/

#include <iostream>
#include <algorithm>
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

static const int SHAPES[6][3][2] = {
	{{0, 0}, {1, 0}, {999, 999}},
	{{0, 0}, {0, 1}, {999, 999}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {-1, 1}},
	{{0, 0}, {1, 0}, {0, 1}},
};

static char cache[1 << 25];

static bool availablity(const int &state, const int &shape, const int &n) {
	int y = n / 5;
	int x = n % 5;

	for (int i = 0; i < 3; i++) {
		if (x + SHAPES[shape][i][0] < 0 || x + SHAPES[shape][i][0] > 4 || y + SHAPES[shape][i][1] > 4)
			return false;

		int tmpState = (y + SHAPES[shape][i][1]) * 5 + x + SHAPES[shape][i][1];
		if (tmpState > 24 || (state & (1 << tmpState)) != 0)
			return false;
	}

	return true;
}

static int place(const int& state, const int& shape, const int &n) {
	int newState = state;

	int y = n / 5;
	int x = n % 5;

	for (int i = 0; i < 3; i++) {
		int tmpState = (y + SHAPES[shape][i][1]) * 5 + x + SHAPES[shape][i][1];

		newState = newState | (1 << tmpState);
	}

	return newState;
}

static char play(int state) {	
		
	char& ret = cache[state];
	if (ret != -1) return ret;
	ret = 2;
	
	for(int i = 0; i < 25; i++) {
		for (int shape = 0; shape < 6; shape++) {
			if(availablity(state, shape, i)) {
				if (play(place(state, shape, i)))
			}
		}
	}

	if (ret == 2)
		return 0;
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
			for (int j = 0; j < 2; j++) {
				cache[i][j] = -1;
			}
		}

		cout << (play(state, true) ? "WINNING" : "LOSING") << endl;
	}
}
