/*
	Problem 043
	ID : PASS486
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;
// maximum number
static const int MAXNUM = 10000001;
// minimum factor of given number
static int minFactors[MAXNUM];
// how many the number is powered by minFactors 
static int minFactorsPower[MAXNUM];
// nuber of factors
static int numFactors[MAXNUM];
// 
static void Initialize() {
	// initialize arrays
	memset(minFactors, 0, sizeof(minFactors));
	memset(minFactorsPower, 0, sizeof(minFactorsPower));
	minFactors[0] = 1;
	minFactorsPower[1] = 0;
	numFactors[1] = 1;

	// getting factors of every numbers on area 
	for (int i = 2; i < MAXNUM; i++) {
		if (minFactors[i] == 0) {
			minFactors[i] = i;
			minFactorsPower[i] = 1;
			for (int j = i * i; j < MAXNUM; j += i) {
				if(minFactors[j] == 0) {
					minFactors[j] = i;
					minFactorsPower[j] = minFactorsPower[j / i] + 1;
				}
			}
		}
	}

	// calculate factors of every numbers on area 
	for (int i = 2; i < MAXNUM; i++) {
		int p = i / minFactors[i];
		int k = i / minFactors[i];
		numFactors[i] = numFactors[k] / minFactorsPower[i] * (minFactorsPower[i] + 1);
	}
}

// counting the number of factors in given area
static int Process(int low, int high, int numDivisor) {
	int ret = 0;
	for (int i = low; i <= high; i++) {
		if (numFactors[i] == numDivisor) {
			ret++;
		}
	}
	return ret;
}

void p043() {
	AutomatedInput Input;
	Input.set(
		"3 "
		"2 2 10 "
		"12 486 486 "
		"200 1000000 2000000 "
	);

	Initialize();
	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		int numDivisor, low, high;
		Input >> numDivisor >> low >> high;

		cout << Process(low, high, numDivisor) << endl;
	}
}