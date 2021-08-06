/*
	Problem 047
	ID : NERDS
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// nerd factors expressed as a coordinates
using point = struct {
	double x, y;
};

// two factors to distinguish
vector<point> nerdFactorA;
vector<point> nerdFactorB;

// returns whether two float numbers are technically equal
static bool fequals(double a, double b) {
	return fabs(a - b) < 0.00001;
}

// returns whether two points are equal
static bool pequals(const point& a, const point& b) {
	return fequals(a.x, b.x) && fequals(a.y, b.y);
}

// returns whether two lines are has an intersection
static bool hasIntersection(const point& p1, const point& p2, const point& p3, const point& p4) {
	point p = {
		((p1.x * p2.y - p1.y * p2.x) * (p3.x - p4.x) - (p1.x - p2.x) * (p3.x * p4.y - p3.y * p4.x)) / ((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x)),
		((p1.x * p2.y - p1.y * p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x * p4.y - p3.y * p4.x)) / ((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x))
	};

	return ((p1.x <= p.x && p.x <= p2.x) || (p2.x <= p.x && p.x <= p1.x)) &&
		((p3.x <= p.x && p.x <= p4.x) || (p4.x <= p.x && p.x <= p3.x));
}

// returns whether the point is inside of the polygon
static bool isInside(point p, const vector<point>& poly) {
	int crosses = 0;

	for (size_t i = 0; i < poly.size(); i++) {
		size_t j = (i + 1) % poly.size();
		if ((poly[i].y > p.y) != (poly[j].y > p.y)) {
			double atX = (poly[j].x - poly[i].x) * (p.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x;
			if (p.x < atX) crosses++;
		}
	}

	return crosses % 2 > 0;
}

// returns how much degrees is a angle between vector pa and pb
static double ccw(const point& p, const point& a, const point& b) {
	double at = atan2(a.y - p.y, a.x - p.x);
	double bt = atan2(b.y - p.y, b.x - p.x);
	double d = bt - at;

	if (fequals(d, 0))	return 0;
	else				return (d >= 0 ? 2 * M_PI - d : -d);
}

// returns shall polygon of points
static vector<point> getShall(const vector<point>& factors) {
	vector<point> ret;

	// set left point and its less ccw point as starting points
	auto left = min_element(factors.begin(), factors.end(), [](const point& a, const point& b) { return a.x < b.x; });
	ret.push_back(*left);

	auto second = factors.begin() == left ? factors.begin() + 1 : factors.begin();
	for (auto iter = factors.begin() + 1; iter != factors.end();  iter++) {
		if (iter == left) continue;

		double before = ccw(*left, { left->x, left->y + 1 }, *second) * 57.2957951;
		double after = ccw(*left, { left->x, left->y + 1 }, *iter) * 57.2957951;

		if (before > after)
			second = iter;
	}
	ret.push_back(*second);

	// start searching shall points
	while (true) {
		point ph = *(ret.end() - 1);
		point phk = *(ret.end() - 2);
		int next = (pequals(factors[0], ph) || pequals(factors[0], phk) ? 
					(pequals(factors[1], ph) || pequals(factors[1], phk) ? 2 : 1) : 0);

		for (size_t i = 0; i < factors.size(); i++) {
			// skip some points
			if (pequals(ph, factors[i])) continue;
			else if (pequals(phk, factors[i])) continue;
			else if (i == next) continue;

			double before = ccw(ph, { 2 * ph.x - phk.x, 2 * ph.y - phk.y }, factors[next]) * 57.2957951;
			double after = ccw(ph, { 2 * ph.x - phk.x, 2 * ph.y - phk.y }, factors[i]) * 57.2957951;
			// get less ccw point
			if (before > after)
				next = i;
		}

		// if the point is starting point, end loop
		if (pequals(factors[next], *left)) break;
		// add point
		ret.push_back(factors[next]);
	}

	return ret;
}

// returns whether a polygon overlaps another
static bool polyIntersects(const vector<point>& p, const vector<point>& q) {
	if (isInside(p[0], q) || isInside(q[0], p))
		return false;

	int m = p.size(), n = q.size();
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (hasIntersection(p[i], p[(i + 1) % m], q[j], q[(j + 1) % n]))
				return false;
	
	return true;
}

static bool solution() {
	nerdFactorA = getShall(nerdFactorA);
	nerdFactorB = getShall(nerdFactorB);

	return polyIntersects(nerdFactorA, nerdFactorB);
}

void p047() {
	AutomatedInput Input;
	Input.set(
		"3 "

		"8 "
		"1 2 3 "
		"1 3 4 "
		"1 4 5 "
		"1 2 5 "
		"0 4 1 "
		"0 5 5 "
		"0 3 3 "
		"0 4 4 "
		
		"6 "
		"1 1 5 "
		"1 5 1 "
		"1 1 1 "
		"0 2 2 "
		"0 4 1 "
		"0 1 4 "
		
		"6 "
		"1 10 10 "
		"0 10 10 "
		"1 5 15 "
		"1 5 5 "
		"0 15 15 "
		"0 15 5 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		size_t n;
		Input >> n;

		nerdFactorA.clear();
		nerdFactorB.clear();
	
		for (size_t i = 0; i < n; i++) {
			int p; double x, y;
			Input >> p >> x >> y;

			if (p)	nerdFactorA.push_back({ x, y });
			else	nerdFactorB.push_back({ x, y });
		}

		cout << (solution() ? "VALID" : "INVALID") << endl;
	}
}