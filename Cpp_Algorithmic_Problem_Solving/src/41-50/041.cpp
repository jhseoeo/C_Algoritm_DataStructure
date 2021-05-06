/*
	Problem 041
	ID : RATIO
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;
// wins limit
static const long long MAXWIN = 2000000000;
// total games
static long long games;
// won games 
static long long wins;

// returns win ratio
static inline int ratio(long long g, long long w) {
	return (w * 100) / g;
}

// calculate number of victory need to change win ratio
long long calc() {
	if (ratio(games + MAXWIN, wins + MAXWIN) == ratio(games, wins))
		return -1;

	int defaultCalc = ratio(games, wins);

	long long low = 1, high = MAXWIN, mid;
	while (high >= low) {
		mid = (high + low) / 2;

		if (defaultCalc == ratio(games + mid, wins + mid))
			low = mid + 1; 
		else
			high = mid - 1;
	}

	return high + 1;
}

void p041() {
	AutomatedInput Input;
	Input.set(
		"5 "
		"10 8 "
		"100 80 "
		"47 47 "
		"99000 0 "
		"1000000000 470000000"
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		Input >> games >> wins;

		cout << calc() << endl;
	}
}