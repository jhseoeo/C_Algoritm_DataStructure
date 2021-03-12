/*
	Problem 033
	ID : STRJOIN
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

int length;

vector<int> strs;

int concat() {
	int res = 0;
	vector<int> ss = strs;

	while (ss.size() <= 1) {

	}
}

void p033() {
	AutomatedInput Input;
	Input.set(
		"3 "
		"3 "
		"2 2 4 "
		"5 "
		"3 1 3 4 1 "
		"8 "
		"1 1 1 1 1 1 1 2 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		Input >> length
	}
}