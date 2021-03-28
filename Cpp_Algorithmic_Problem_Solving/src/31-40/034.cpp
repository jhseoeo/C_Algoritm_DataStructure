/*
	Problem 034
	ID : MINASTIRITH
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// PI
static const double PI = 3.14159265;
// custom biggest value
static const int INF = 987654321;
// number of bunkers
static int n;
// bunkers, start angle and end angle
pair<double, double> bunkers[101];

// transfer radian into degree
static inline double rad2deg(double rad) {
	return rad * 180 / PI;
}

// get degree value from point on center circle
static inline double rad2deg(double x, double y) {
	if (x >= 0)
		return rad2deg(acos(y / 8));
	else
		return rad2deg(acos(-y / 8)) + 180;
}

// revalue degree into degree range(0~360)
static inline double deg(double deg) {
	return fmod(deg + 360.0, 360.0);
}

// return whether a bunker includes given point
static bool isIncludes(double point, pair<double, double> bunker) {
	if (bunker.first <= bunker.second)
		return (bunker.first <= point && point <= bunker.second);
	else
		return (bunker.first <= point || point <= bunker.second);
}

// start searching from given bunker
static int solveLinear(int startIdx) {
	int ret = 0;
	int idx = startIdx;

	do {
		int longestIdx = idx;
		for (int i = (idx + 1) % n; i != idx; i = (i + 1) % n) {

			// for bunkers which first point is included by base bunker
			if (isIncludes(bunkers[i].first, bunkers[idx])) {

				// current bunker includes starting bunker's first point
				if (isIncludes(bunkers[i].second, bunkers[startIdx])) {
					longestIdx = startIdx;
					break;
				}

				// current bunker's seconds point is on the more right position
				if (bunkers[longestIdx].second < bunkers[i].second)
					longestIdx = i;

			} else {
				break;
			}
		}

		// no bunkers which first point is not included by current bunker
		if (longestIdx == idx)
			return 987654321;

		idx = longestIdx;
		ret++;

	} while (idx != startIdx);

	return ret;
}

// start searching from the bunkers that includes origin
static int solveCircular() {
	int ret = 987654321;

	for (int i = n - 1; i >= 0; i--) {
		// for bunkers includes origin
		if (bunkers[i].first > bunkers[i].second)
			ret = min(ret, 1 + solveLinear(i));
	}

	if (ret == 987654321)
		return -1;
	return ret;
}

void p034() {
	cout.precision(8);
	cout.setf(ios::showpoint);

	AutomatedInput Input;
	Input.set(
		"3 "
		"10 "
		"7.02066050 -3.83540431 4.0 "
		"-7.23257714 -3.41903904 2.0 "
		"0.00000000 -8.00000000 8.0 "
		"-8.00000000 -0.00000000 4.8 "
		"-6.47213595 4.70228202 3.2 "
		"-4.70228202 6.47213595 4.8 "
		"7.60845213 -2.47213595 1.6 "
		"-2.47213595 -7.60845213 8.8 "
		"6.47213595 4.70228202 7.6 "
		"-0.00000000 8.00000000 4.8 "

		"4 "
		"8.00000000 0.00000000 8.00 "
		"0.00000000 -8.00000000 8.00 "
		"-8.00000000 -0.00000000 8.00 "
		"1.25147572 7.90150672 5.40 "

		"1 "
		"8 0 15.99 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		double x, y, r, delta, centre;
		Input >> n;
		
		// getting bunkers position
		for (int i = 0; i < n; i++) {
			Input >> x >> y >> r;
			delta = 2 * rad2deg(asin(r / 16));
			centre = rad2deg(x, y);
			bunkers[i].first = deg(centre - delta);
			bunkers[i].second = deg(centre + delta);
		}

		sort(bunkers, bunkers + n);
		cout << solveCircular() << endl;
	}
}