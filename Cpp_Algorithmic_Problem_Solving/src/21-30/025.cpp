/*
	Problem 025
	ID : DRAGON
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

static const string GEN0 = "FX";
static const string XXX = "X+YF";
static const string YYY = "FX-Y";

static int len;

// generating and print dragon curve by given parameters
// parameter "start" will be called by reference
static void curve(const string &seed, int gen, int &start) {
	// base case 1 : when the current generation is 0th, prints seed by lefting length 
	if (gen == 0) {
		cout << seed.substr(start, len);
		len -= seed.length();
		return;
	}

	// base case 2 : when the length is over, skip the leftover functions
	if (len <= 0)
		return;

	// generating skipping coefficient
	// length of a X/Y in current generation equals to skipping coefficient in last generation
	long long skips = 1;
	for(int i = 0; i < gen; i++) {
		skips = (skips * 2) + 2;
	}

	size_t i = 0;
	while (i < seed.length() && len > 0) {
		if(seed.at(i) == 'X' || seed.at(i) == 'Y') {
			if (start >= skips) {
				start -= skips;				// skip
			} else if (seed.at(i) == 'X') {
				curve(XXX, gen - 1, start); // apply next generation by transforming x recursively
			} else if (seed.at(i) == 'Y') {
				curve(YYY, gen - 1, start);	// apply next generation by transforming y recursively
			}
		} else {
			if (start >= 1) {
				start--;					// skip
			} else { 
				cout << seed.at(i);			// print single letter except x,y
				len--;
			}
		}
		i++;
	}
}

void p025() {

	AutomatedInput Input;
	Input.set(
		"4 "
		"0 1 2 "
		"1 1 5 "
		"2 6 5 "
		"42 764853475 30 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		int gen, start;
		Input >> gen >> start >> len;
		start--;

		curve(GEN0, gen, start);
		cout << endl;
	}
}