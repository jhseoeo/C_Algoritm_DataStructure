/*
	Problem 019
	ID : POLY
*/

#include <iostream>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

static const int MOD = 10000000;

static int cache[101][101];

static int poly(int n, int upper) {
	if (n == 0) return 1;

	int& let = cache[n][upper];
	if (let != -1) return let;

	let = 0;
	if (upper != 0) {
		for (int i = 1; i <= n; i++) {
			// count case of number that next blocks stick onto top blocks
			let += ((upper + i - 1) * poly(n - i, i)) % MOD;
			// multply all cases that next blocks stick onto top blocks

			let %= MOD;
		}
	} else {
		for (int i = 1; i <= n; i++) {
			let += poly(n - i, i) % MOD;
			let %= MOD;
		}
	}
	return let;
}

void p019() {

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
			for(int j = 0; j < 101; j++)
				cache[i][j] = -1;

		int n;
		Input >> n;

		result[trial] = poly(n, 0);
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}