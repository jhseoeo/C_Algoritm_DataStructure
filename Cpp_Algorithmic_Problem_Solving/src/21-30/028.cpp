/*
	Problem 028
	ID : NUMBERGAME
*/

#include <iostream>
#include <algorithm>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// length of board elements
static int len;
// board
static int board[50];
// cache
static int cache[50][50];

static int play(int left, int right) {
	// base case. no elements remaining
	if (left > right)
		return 0;

	int& ret = cache[left][right];
	if (ret != -55555) return ret;
	
	// player takes left/right one
	ret = max(board[left] - play(left+1, right),
			  board[right] - play(left, right-1));

	// player skis left/right one
	if (right - left >= 1) {
		ret = max(ret, -play(left + 2, right));
		ret = max(ret, -play(left, right - 2));
	}

	return ret;
}


void p028() {

	AutomatedInput Input;
	Input.set(
		"3 "
		"5 "
		"-1000 -1000 -3 -1000 -1000 "
		"6 "
		"100 -1000 -1000 100 -1000 -1000 "
		"10 "
		"7 -5 8 5 1 -4 -8 6 7 9 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		Input >> len;

		for (int i = 0; i < len; i++) {
			Input >> board[i];
			for (int j = 0; j < len; j++) {
				cache[i][j] = -55555;
			}
		}
		cout << play(0, len - 1) << endl;
	}
}
