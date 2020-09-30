/*
	Problem 012
	ID : LIS
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "../AutoInput.h"

using namespace std;

static int cache[100], A[100] = {3, 2, 1, 7, 5, 4, 2, 6, -1, };

static int lis(int pos) {

	if (A[pos] == -1) return 0; // when it reached end of the array.
	
	int& ret = cache[pos];		// memoization applied.
	if (ret != -1) return ret;		
	ret = 1;		// at any posotion, basic lenth is 1.

	for (int i = pos+1; A[i] != -1; i++) {
		if (A[i] > A[pos])		// only when the number of given position is grater than before one.
			ret = max(ret, 1 + lis(i));	// decide the number 
	}
	return ret;
}


void p012() {
	
	for (int i = 0; i < 100; i++) {
		cache[i] = -1;
	}

	int x = 0;
	for (int i = 0; A[i] != -1; i++) {
		x = max(x, lis(i));
	}

	cout << x << endl;
}
