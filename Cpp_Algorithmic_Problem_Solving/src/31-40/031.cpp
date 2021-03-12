/*
	Problem 031
	ID : GENIUS
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// length of each songs
static int length[50];
// chances to jump song a to b
static double chances[50][50];
// number of songs
int n;
// minutes to jum
int m;
// number of favorite songs
int f;

// get probabillity by recursion
static double getProb(const int &song, int crnt, int minute) {

	if (minute < 0)
		return song == crnt;

	double c = 0;
	for(int i = 0; i < n; i++) {
		c += getProb(song, i, minute - length[i]) * chances[crnt][i];
	}

	return c;
}

// get probabillity by iteration
static vector<double> getProb() {
	// initialize
	double c[5][50];	// because lengths of each songs do not exceed 4, set vertical size 5.
	memset(c, 0, sizeof(c));
	c[0][0] = 1.0;
	
	// for every times
	for (int time = 1; time <= m; time++) {
		// traveling every songs
		for (int s = 0; s < n; s++) {
			double& prob = c[time%5][s];
			prob = 0;

			// summing chances
			for (int last = 0; last < n; last++) {
				prob += c[(time - length[last] + 5) % 5][last] * chances[last][s];
			}
		}
	}

	// calculating possibilities by traveling every times
	vector<double> ret(m);
	for (int s = 0; s < n; s++) {
		for (int start = m - length[s] + 1; start <= m; start++) {
			ret[s] += c[start % 5][s];
		}
	}

	return ret;
	
}

void p031() {
	cout.precision(8);
	cout.setf(ios::showpoint);

	AutomatedInput Input;
	Input.set(
		"3 "
		"3 6 3 " // number of songs, minute later, number of favorites 
		"4 4 2 " // length of each songs
		"0.18 0.40 0.42 "
		"0.15 0.46 0.39 "
		"0.58 0.23 0.19 "
		"0 1 2 " // to get possibilities
		
		"4 10 4 "
		"1 3 2 4 "
		"0.26 0.07 0.49 0.18 "
		"0.21 0.33 0.15 0.31 "
		"0.41 0.20 0.38 0.01 "
		"0.28 0.31 0.18 0.23 "
		"2 0 3 1 "
		
		"4 1000 4 "
		"4 3 4 4 "
		"0.08 0.47 0.12 0.33 "
		"0.10 0.02 0.39 0.49 "
		"0.08 0.33 0.35 0.24 "
		"0.14 0.19 0.58 0.09 "
		"1 3 2 0 "


	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		
		Input >> n >> m >> f;

		for (int i = 0; i < n; i++) {
			Input >> length[i];
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				Input >> chances[i][j];
			}
		}

		vector<double> res = getProb();
		for (int i = 0; i < f; i++) {
			int x;
			Input >> x;
			cout << res[x] << " ";
		}

		cout << endl;
	}
}