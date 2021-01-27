/*
	Problem 017
	ID : TRIPATHCNT
*/

#include <iostream>
#include <algorithm>
#include "../AutoInput.h"
#include "../Problems.h"

using namespace std;

static int SIZE;

static int triangle[101][101], cache[101][101];
static int findPath(int y, int x) {
	int& res = cache[y][x];

	if (res != -1)
		return res;

	if (y == SIZE - 1)
		return res = triangle[y][x];	// if current posotion is bottom, return its own value.

	int a = triangle[y][x] + findPath(y + 1, x);	 // getting downside maximum 
	int b = triangle[y][x] + findPath(y + 1, x + 1); // getting downside left maximum
	// getting both values and choose bigger one

	return res = (a > b ? a : b);
}

static int cache2[101][101];
static int countPath(int y, int x) {
	if (y == SIZE - 1)
		return 1;

	int& let = cache2[y][x];
	if (let != -1)
		return let;

	if (findPath(y + 1, x) > findPath(y + 1, x + 1))	// selecting bigger subpath
		return countPath(y + 1, x);
	else if (findPath(y + 1, x) < findPath(y + 1, x + 1))
		return countPath(y + 1, x + 1);
	else												// when subpaths equals
		return countPath(y + 1, x) + countPath(y + 1, x + 1);	// 
}

void p017() {
	AutomatedInput Input;
	Input.set(
		"1 "
		"4 "
		"9 "
		"5 7 "
		"1 3 2 "
		"3 5 5 6 "
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				cache[i][j] = -1;
				cache2[i][j] = -1;
				triangle[i][j] = 0;
			}
		}

		Input >> SIZE;

		for (int i = 1; i <= SIZE; i++) {
			for (int j = 1; j <= i; j++) {
				Input >> triangle[i-1][j-1];
			}
		}

		result[trial] = countPath(0, 0);
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}