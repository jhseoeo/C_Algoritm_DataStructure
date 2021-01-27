/*
	Problem 015
	ID : QUANTIZATION
*/

static const int INF = 987645321;

#include <iostream>
#include <algorithm>
#include <vector>
#include "../AutoInput.h"

static int n;
static int A[101];
static int pSum[101];	// for calculating partial sum of array value
static int pqSum[101];	// for calculating partial sum of squared array value

// returns min error
static int minError(int from, int to) {
	int sum = pSum[to] - (from == 0 ? 0 : pSum[from-1]);		// getting array sum of given section
	int sqsum = pqSum[to] - (from == 0 ? 0 : pqSum[from-1]);	// getting squared array sum of given section
	int avg = int(double(sum) / (to - from + 1) + 0.5);			// average value is minimizing error

	// expression of minimal error
	return sqsum - 2*avg*sum + avg*avg*(to - from + 1); 
}

static int cache[101][11];
static int quantize(int from, int parts) { // quantizing array
	if (from == n)
		return 0; // returns minimal number when search is successfully finished
	else if (parts == 0)
		return INF;	// returns largest number when search is finished but not leached end of the array
	int &ret = cache[from][parts];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int i = from; i < n; i++)
		ret = min(ret, minError(from, i) + quantize(i + 1, parts - 1));
	return ret;
}

void p015() {

	AutomatedInput Input;
	Input.set(
		"2 "
		"10 3 "
		"3 3 3 1 2 3 2 2 2 1 "
		"9 3 "
		"1 744 755 4 897 902 890 6 777 "
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 11; j++)
				cache[i][j] = -1;

		int size, quants;

		Input >> size >> quants;
		n = size;
		for(int i = 0; i < size; i++)
			Input >> A[i];

		sort(A, A+size);		// sort array before quantize
		pSum[0] = A[0];			// initialize partial sum array
		pqSum[0] = A[0] * A[0];	// initialize squared partial sum array
		for (int i = 1; i < size; i++) {
			pSum[i] = A[i] + pSum[i - 1];
			pqSum[i] = A[i] * A[i] + pqSum[i - 1];
		}

		result[trial] = quantize(0, quants);
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}