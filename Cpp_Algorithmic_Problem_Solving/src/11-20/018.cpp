/*
	Problem 018
	ID : ASYMTILING
*/

#include <iostream>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

static const int MOD = 1000000007;

static int cache[101];
static int tiling(int n) {
	int& let = cache[n];

	if (let != -1)
		return let;
	else if (n <= 1)
		return 1;

	return let = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

void p018() {

	AutomatedInput Input;
	Input.set(
		"3 "
		"2 "
		"4 "
		"92 "
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		for (int i = 0; i < 101; i++)
			cache[i] = -1;

		int n;
		Input >> n;
		int res = tiling(n);

		if (n % 2 == 1) // size of rectangle is even number
			res = (res - tiling(n / 2) + MOD) % MOD;	// subtract asymmetric case from every case of number.
		else {			// size of rectangle is odd number
			res = (res - tiling(n / 2) + MOD) % MOD;		
			res = (res - tiling(n / 2 - 1) + MOD) % MOD;	// subtract asymmetric case from every case of number.
		}

		result[trial] = res;
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}