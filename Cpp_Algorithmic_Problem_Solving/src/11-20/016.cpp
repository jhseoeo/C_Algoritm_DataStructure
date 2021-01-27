/*
	Problem 016
	ID : TILING2
*/

#include <iostream>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

static const int MOD = 987654321;

static int cache[101];
static int tiling(int n) {
	int& let = cache[n];

	if (n <= 1)
		return 1;
	else if (let != -1)
		return let;

	return (tiling(n - 1) + tiling(n - 2)) % MOD;
}

void p016() {

	AutomatedInput Input;
	Input.set(
		"1 "
		"5 "
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		for (int i = 0; i < 101; i++)
			cache[i] = -1;

		int n;
		Input >> n;

		result[trial] = tiling(n);
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}