/*
	Problem 012
	ID : LIS
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "../AutoInput.h"

using namespace std;


int cache[100], A[100] = {3, 2, 1, 7, 5, 4, 2, 6, -1, };

int lis(int pos) {

	if (A[pos] == -1) return 0;
	
	int& ret = cache[pos];
	if (ret != -1) return ret;
	ret = 1;

	for (int i = pos+1; A[i] != -1; i++) {
		if (A[i] > A[pos])
			ret = max(ret, 1 + lis(i));
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
