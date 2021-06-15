/*
	Problem 045
	ID : PINBALL
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

using point = struct {
	double x, y;
};

using linear = struct {
	point p; // starting point
	double dx, dy;
};

using circle = struct {
	point p; // center of circle
	double rad; // radius 
};

static vector<circle> circles;

// (overloading) returns distances of given line and point
static double distance(const linear& l, const point& p) {
	double a = l.dy, b = -l.dx, c = l.dx * l.p.y - l.dy * l.p.x;
	double x0 = p.x, y0 = p.y;
	return abs(a * x0 + b * y0 + c) / sqrt(a * a + b * b);
}

// (overloading) returns distances of given two points
static double distance(const point& p1, const point& p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// returns if given line and circle meet
static inline bool isMeets(const linear& l, const circle& o) {
	return distance(l, o.p) < o.rad;
}

// returns intersection(near one) of given line and circle
// given line and circle should meet at two points
static point intersection(const linear& l, const circle& o)
{
    double m, n;
	double A, B1, C, D;
	double X, Y;
	point pt1, pt2;

    m = l.dy / l.dx;
    n = l.p.y - m * l.p.x;

    A = m * m + 1;
    B1 = (m * n - m * o.p.y - o.p.x);
    C = (o.p.x * o.p.x + o.p.y * o.p.y - o.rad * o.rad + n * n - 2 * n * o.p.y);
    D = B1 * B1 - A * C;

    X = -(B1 + sqrt(D)) / A;
    Y = m * X + n;
    pt1.x = X;
    pt1.y = Y;

    X = -(B1 - sqrt(D)) / A;
    Y = m * X + n;
	pt2.x = X;
	pt2.y = Y;

	return (distance(pt1, l.p) < distance(pt2, l.p) ? pt1 : pt2);
}

// prints number of circle that given line reaches first
// returns reflected line at reaching point
static linear findReachingCircle(const linear& l) {
	int idx = -1;
	point nearp = {-999, -999};

	for (size_t i = 0; i < circles.size(); i++) {
		if (distance(l, circles[i].p) > circles[i].rad) continue; // skip circles that do not meets
		point p = intersection(l, circles[i]);
		
		if (abs(distance(l.p, circles[i].p) - circles[i].rad) < 0.0001) continue; // skip circle on which current line starts
		if ((l.dx > 0 && l.p.x > p.x) || (l.dx < 0 && l.p.x < p.x)) continue; // skip circles on opposite direction

		 if (nearp.x == -999 || distance(l.p, nearp) > distance(l.p, p)) { // choose nearest circle
			nearp = p;
			idx = i;
		}
	}

	// when there is no circle on line
	if (idx == -1)
		return { {-999, -999}, -999, -999 };
	cout << idx << " ";

	// calculating gradient of reflected line
	double t1 = atan(-(nearp.x - circles[idx].p.x) / (nearp.y - circles[idx].p.y));
	double t2 = atan(l.dy / l.dx);
	double tmpDeg = tan(2 * t1 - t2);
	point tmpdp = { nearp.x + 0.001, nearp.y + 0.001 * tmpDeg };

	// decide direction of line
	if (distance(nearp, circles[idx].p) > distance(tmpdp, circles[idx].p))
		return { nearp, -1, -tmpDeg };
	else
		return { nearp, 1, tmpDeg };
}

static vector<int> process(const linear& start) {
	vector<int> res;
	linear next = start;
	do {
		next = findReachingCircle(next);
	} while (next.p.x != -999);
	return res; 
}

void p045() {
	AutomatedInput Input;
	Input.set(
		"1 "
		"5 5 1 1 5 "
		"22 40 12 "
		"61 26 20 "
		"19 78 21 "
		"51 86 7 "
		"84 57 15 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		double x, y, dx, dy, r; int n;
		Input >> x >> y >> dx >> dy >> n;
		linear startLine = { {x, y}, dx, dy };

		for (int i = 0; i < n; i++) {
			Input >> x >> y >> r;
			circle o = { {x, y}, r+1 };
			circles.push_back(o);
		}
		
		process(startLine);
		cout << endl;
	}
}