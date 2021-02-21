/*
	Problem 024
	ID : KLIS
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// maximum value of return value
const int MAX = 2000000001;
// sequence
static int A[501];
// length of sequence
static int len;
// cache 
static int cache[501];
// count number of lis that can be found from given pos
static int lis(int pos) {
	int& ret = cache[pos + 1];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = pos + 1; i < len; i++) {
		if (pos == -1 || A[pos] < A[i])
			ret = max(ret, lis(i) + 1);
	}
	return ret;
}

// cache for function cacheCnt
int cacheCnt[501];
// count number of lis that can be found from given pos
static int count(int start) {
	if (lis(start) == 1) return 1;
	
	int& ret = cacheCnt[start + 1];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = start+1; i < len; i++) {
		if ((start == -1 || A[start] < A[i]) &&	// count what has larger value of sequence
			lis(start) == lis(i) + 1)			// count what has 1 lower lis in sequence
			ret = min<long long>(MAX, (long long)ret + count(i));	// accumulating count numbers
	}
	return ret;
}

// traceback and print kth lis 
static void reconstruct(int start, int skip) {
	for (int i = start + 1; i < len; i++) {

		if ((start == -1 || A[start] < A[i]) &&
			lis(start) == lis(i) + 1) {	 // same condition with count function

			// search 
			if (skip < count(i)) {		// when kth lis is in current searching range
				cout << A[i] << " ";	// print
				reconstruct(i, skip);	// traceback next element recursively
				break;
			} else {					// or when kth lis is outta current searching range
				skip -= (skip <= 0 ? 0 : count(i));	// reduce searching range
			}
		}
	}
}

void p024() {

	AutomatedInput Input;
	Input.set(
		"3 "
		"8 6 "
		"5 1 6 4 3 2 8 7 "
		"8 4 "
		"2 1 4 3 6 5 8 7 "
		"8 2 "
		"5 6 7 8 1 2 3 4 "
	);

	int T;
	Input >> T;

	for(int trial = 0; trial < T; trial++) {

		int k;
		Input >> len >> k;
		for(int i = 0; i < len; i++) {
			Input >> A[i];
		}

		for (int i = 0; i < 501; i++) {
			cacheCnt[i] = cache[i] = -1;
		}

		cout << lis(-1)-1 << " " << count(-1) << endl;
		reconstruct(-1, count(-1)-k);
		cout << endl;
	}
}