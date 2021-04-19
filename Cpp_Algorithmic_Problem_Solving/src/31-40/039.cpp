/*
	Problem 039
	ID : CANADATRIP
*/

#include <iostream>
#include <algorithm>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;
// number of city
static int numCity;
// order of flag to search
static int numFlags;
// distances of each cities from start line
static int distanceCity[5000];
// distances of flags appearance from the city
static int flagStart[5000];
// intervals of flags appearance
static int interval[5000];

// returns if number of flags started counting from starting point to given points are more than numFlags
static bool decision(const int dist) {
	int nums = 0;

	for (int i = 0; i < numCity; i++) {
		for (int pos = distanceCity[i] - flagStart[i]; pos < dist && pos <= distanceCity[i]; pos += interval[i])
			nums++;
	}

	return nums >= numFlags;
}

// finds position of numFlags
static int optimize() {
	int low = 0, high = 8030000, mid;
	while (low <= high) {
		mid = (low + high) / 2;

		if (decision(mid))
			high = mid - 1;
		else
			low = mid + 1;

	}
	return mid;
}

void p039() {
	AutomatedInput Input;
	Input.set(
		"2 "
		
		"3 15 "
		"500 100 10 "
		"504 16 4 "
		"510 60 6 "
		
		"2 1234567 "
		"8030000 8030000 1 "
		"2 2 1 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		Input >> numCity >> numFlags;
		
		memset(distanceCity, 0, sizeof(distanceCity));
		memset(flagStart, 0, sizeof(flagStart));
		memset(interval, 0, sizeof(interval));

		for (int i = 0; i < numCity; i++) {
			Input >> distanceCity[i] >> flagStart[i] >> interval[i];
		}

		cout << optimize() << endl;
	}
}