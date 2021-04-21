/*
	Problem 040
	ID : WITHDRAWL
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;
// number of subject
static int numSubject;
// number of subject that should be remaining
static int numRemainingSubject;
// rank on subject
static int RankSubject[1000];
// number of studnets on subject
static int numStudents[1000];

// returns if cumulative rank of subjects are less than given average
static bool decision(double avg) {
	vector<double> v(numSubject);
	for (int i = 0; i < numSubject; i++) {
		v[i] = avg * numStudents[i] - RankSubject[i];
	}
	sort(v.begin(), v.end(), [](const double a, const double b) { return a > b; });
	
	double sum = 0;

	for (int i = 0; i < numRemainingSubject; i++) {
		sum += v[i];
	}

	return sum >= 0;
}

// find value
static double optimize() {
	double high = 1, low = -1e-9;
	for (int i = 0; i < 100; i++) {
		double mid = (low + high) / 2;
		if (decision(mid))
			high = mid;
		else
			low = mid;
	}

	return high;
}

void p040() {
	AutomatedInput Input;
	Input.set(
		"3 "
		"3 2 "
		"1 4 6 10 10 17 "
		"4 2 "
		"4 8 9 12 3 10 2 5 "
		"10 5 "
		"70 180 192 192 1 20 10 200 6 102 60 1000 4 9 1 12 8 127 100 700 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		Input >> numSubject >> numRemainingSubject;
		for (int i = 0; i < numSubject; i++) {
			Input >> RankSubject[i] >> numStudents[i];
		}

		cout << optimize() << endl;
	}
}