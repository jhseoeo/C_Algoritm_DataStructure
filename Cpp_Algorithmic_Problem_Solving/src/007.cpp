/*
	Problem 007
	ID : FENCE

	Entering the number of fences, 
	and lengths of each fences from user.
	Then getting largest area of rectangle
	that can be created from fences.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include "Problems.h"
#include "AutoInput.h"

using namespace std;

// Assuming that rectangle is include the center line, get largest area of rectangle.
static int getMiddleArea(const vector<int> &fences, int from, int to) {
	if (from == to)
		return fences[from];

	int mid = (from + to) / 2;

	int Max = 0;
	for (int i = mid; i >= from; i--) {
		for (int j = mid + 1; j <= to; j++) {
			int t = *(min_element(fences.begin()+i, fences.begin()+j+1)) * (j - i + 1); // minimum height * width
			Max = t > Max ? t : Max;
		}
	}

	return Max;
}

// getting largest rectangle area from array of fences.
static int getMaxArea(const vector<int> &fences, int from, int to) {
	if (from == to)
		return fences[from];

	int mid = (from + to) / 2;

	int left = getMaxArea(fences, from, mid); // largest rectangle is on left side
	int middle = getMiddleArea(fences, from, to); // largest rectangle is on right center
	int right = getMaxArea(fences, mid + 1, to); // largest rectangle is on right side

	return max({left, middle, right});
}

void p007() {
	AutomatedInput Input;
	Input.set(
		"3 "
		"7 "
		"7 1 5 9 6 7 3 "
		"7 " 
		"1 4 4 4 4 1 1 "
		"4 "
		"1 8 2 2 "
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		int fenceSize;
		Input >> fenceSize;
		vector<int> fences(fenceSize);
		for (auto i = fences.begin(); i != fences.end(); i++) {
			Input >> *i;
		}

		result[trial] = getMaxArea(fences, 0, fenceSize - 1);
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}