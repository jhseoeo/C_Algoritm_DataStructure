/*
	Problem 046
	ID : TRESURE
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// position vector of each point of polygon
using point = struct {
	double x, y;
};

using polygon = vector<point>;

// island polygon
polygon island;

// return area of polygon
static double getArea(const polygon& poly) {
	double ret = 0;
	for (size_t i = 0; i < poly.size(); i++) {
		int j = (i + 1) % poly.size();
		ret += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
	}

	return fabs(ret) / 2.0;
}

// return positives when the vector b is located in more counter-clock wised direction than a based on p
static double ccw(const point& p, const point& a, const point& b) {
	point a1 = { a.x - p.x, a.y - p.y };
	point b1 = { b.x - p.x, b.y - p.y };
	int k1 = a1.x * b1.y;
	int k2 = a1.y * b1.x;
	return a1.x * b1.y - a1.y * b1.x;
}

// return intersection point of two vectors
point IntersectionPoint1(const point& p1, const point& p2, const point& p3, const point& p4) {
	return {
		((p1.x * p2.y - p1.y * p2.x) * (p3.x - p4.x) - (p1.x - p2.x) * (p3.x * p4.y - p3.y * p4.x)) / ((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x)),
		((p1.x * p2.y - p1.y * p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x * p4.y - p3.y * p4.x)) / ((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x))
	};
}

// cut polygon by vector(a to b)
static polygon cutPoly(polygon& p, const point& a, const point& b) {
	int n = p.size();

	// prerocesssing
	// record whether each points of polygon are inside of halfplane
	vector<bool> inside(n);
	for (int i = 0; i < n; i++)
		inside[i] = ccw(a, b, p[i]) >= 0;


	polygon ret;
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		// add points inside of halfplane
		if (inside[i]) ret.push_back(p[i]);
		// add intersection of two vectors
		if (inside[i] != inside[j]) {
			point ps = IntersectionPoint1(p[i], p[j], a, b);
			ret.push_back(ps);
		}
	}
	return ret;
}

// cut polygon by four vectors of rectangle
static double solution(double x1, double y1, double x2, double y2) {
	point a = { x1, y1 },
		b = { x2, y1 },
		c = { x2, y2 },
		d = { x1, y2 };
	// cut polygon by each vectors of rectangle
	polygon ret = cutPoly(island, a, b);
	ret = cutPoly(ret, b, c);
	ret = cutPoly(ret, c, d);
	ret = cutPoly(ret, d, a);
	return getArea(ret);
}

void p046() {
	AutomatedInput Input;
	Input.set(
		"2 "
		"26 34 76 72 15 "
		"41 52 "
		"50 71 "
		"42 87 "
		"26 84 "
		"16 58 "
		"33 33 "
		"51 23 "
		"64 32 "
		"73 17 "
		"86 14 "
		"97 38 "
		"92 68 "
		"82 79 "
		"68 45 "
		"61 58 "
		"50 20 70 80 4 "
		"86 50 "
		"30 10 "
		"90 50 "
		"30 90 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		island.clear();

		double x1, y1, x2, y2; int n;
		Input >> x1 >> y1 >> x2 >> y2 >> n;

		double px, py;
		for (int i = 0; i < n; i++) {
			Input >> px >> py;
			island.push_back({ px, py });
		}

		cout << solution(x1, y1, x2, y2) << endl;
	}
}