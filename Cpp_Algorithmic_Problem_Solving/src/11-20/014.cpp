/*
	Problem 014
	ID : PI
*/

#include <iostream>
#include <algorithm>
#include <string>
#include "../AutoInput.h"

using namespace std;

static string A;
static int cache[10001];

static int decidePattern(int from, int num) {	// deciding pattern 
	string subA = A.substr(from, num);
	bool progressive = true, alternating = true;
	
	if (subA == string(num, subA[0]))	// when the all chars in str are same
		return 1;

	for (int i = from; i < from + num-1; i++) {		// when the all numbers in str are in/decreasing by certain difference
		if (A[i+1] - A[i] != A[from+1] - A[from])
			progressive = false;
	}

	if (progressive && abs(A[from + 1] - A[from]) == 1) return 2;		// it is progressive and its difference is 1

	for (int i = from; i < from + num-1; i++) {		// when the characters in str alternately appear
		if (A[i] != A[i % 2])
			alternating = false;
	}

	if (alternating) return 4;
	if (progressive) return 5;

	return 10;
}

static int getPI(int idx) {
	if (A.size() == idx) return 0;

	int& ret = cache[idx];		// applying memoization.
	if (ret != -1) return ret;	
	ret = 87654321;	// initialize as maximized value (cuz we finding minimum value)

	for(int i = 3; i <= 5; i++) {
		if (idx + i > A.size())
			break;
		ret = min(ret, getPI(idx + i) + decidePattern(idx, i));	// finding minimum pattern value.
	}

	return ret;
}

void p014() {

	AutomatedInput Input;
	Input.set(
		"5 "
		"12341234 "
		"11111222 "
		"12122222 "
		"22222222 "
		"12673939 "
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {

		Input >> A;

		for (int i = 0; i < 10001; i++)
			cache[i] = -1;
		result[trial] = getPI(0);
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}