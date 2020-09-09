/*
	Problem 005
	ID : CLOCKSYNK

	There are 4x4 clocks collocated as grid pattern.
	all clocks point 12, 3, 6, 9, and we gonna make it to 12 all of it..
	the only way to edit clock is triggering 10 button.
	each button linked with 3~5 clock.
	if we trigger a button, clocks linked with the button move 3 hours plus.
	if we give times that each clock pointing, what is minimal time triggering button
*/

#include <iostream>
#include <vector>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

static const int MAX = 31; // Maximum possible counts of triggering switches
static const int NON = -1; // Used instead of NULL

static int SWITCH[10][5] = { // List of switche. Each switches include clocks that are affected when the switch triggered.
	{0, 1, 2, NON, NON},
	{3, 7, 9, 11, NON},
	{4, 10, 14, 15, NON},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15, NON},
	{3, 14, 15, NON, NON},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

static bool isAligned(const vector<int> &clocks) { // return true when all the clocks are pointing 12.
	for (int i = 0; i < 16; i++) {
		if (clocks.at(i) != 12)
			return false;
	}
	return true;
}

static void push(vector<int> &clocks, int sw) { // trigger a switch
	for (int j = 0; j < 5; j++) {
		int i = SWITCH[sw][j];

		if (i == NON) break;
		else if (clocks.at(i) == 12) clocks[i] = 3;
		else clocks.at(i) += 3;
	}
}

static int align(vector<int> clock, int sw) { // align all clocks

	if (isAligned(clock)) // if clocks aligned,
		return 0;
	else if (sw >= 10) // if clocks not aligned until ends, return MAX to notice that this recursion is not to be considered.
		return MAX;

	int result = MAX;
	for (int j = 0; j < 4; j++) {
		int n = align(clock, sw + 1) + j; // gets minimal value recursively
		result = n < result ? n : result; // chooses smaller one as result
		push(clock, sw);
	}

	return result;
}

static void print(const vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << i << " : " << v[i] << endl;
	}
}

void p005() {
	AutomatedInput Input; // since this question, introduced an AUTOMATED input.

	Input.set("2 "
			  "12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12 "
			  "12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6");
	int T;
	Input >> T;

	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		vector<int> clocks(16);
		int time;
		for (int i = 0; i < 16; i++) {
			Input >> time;
			clocks[i] = time;
		}

		result[trial] = align(clocks, 0);
	}

	for (int i = 0; i < T; i++)
		cout << (result[i] > 30 ? NON : result[i]) << endl;

	delete[] result;
}