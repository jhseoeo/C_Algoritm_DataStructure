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

// island polygon
vector<point> island;

// 
vector<vector<point>> polygons;

// rectangle polygon
vector<point> rectangle;

static bool equals(double a, double b) {
	return fabs(a - b) < 0.00001;
}


// check if a point is inside of given polygon
static bool isInside(const vector<point>& poly, point p) {
	int crosses = 0;
	for (size_t i = 0; i < poly.size(); i++) {
		int j = (i + 1) % poly.size();
		if ((poly[i].y > p.y) != (poly[j].y > p.y)) {
			double atX = (poly[j].x - poly[i].x) * (p.y - poly[i].y) /
						 (poly[j].y - poly[i].y) + poly[i].x;
			if (p.x < atX)
				crosses++;
		}
	}

	return crosses % 2 > 0;
}

//
static bool isInside(const vector<point>& island, const vector<point> poly) {
	double x = (poly[0].x + poly[1].x + poly[2].x) / 3.0;
	double y = (poly[0].y + poly[1].y + poly[2].y) / 3.0;

	return isInside(island, {x, y});
}


//
static double getArea(const vector<point>& poly) {
	double ret = 0;
	for (size_t i = 0; i < poly.size(); i++) {
		int j = (i + 1) % poly.size();
		ret += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
	}

	return fabs(ret) / 2.0;
}

//
static vector<point> getMeets(const vector<point>& rect, const point& p1, const point& p2) {
	vector<point> result;
	double A, B, E;
	double C, D, F;
	A = p2.y - p1.y;
	B = p2.x - p1.x;
	E = A * p1.x + B * p1.y;

	for (int i = 0; i < 4; i++) {
		int j = (i + 1) % 4;
		C = rect[j].y - rect[i].y;
		D = rect[j].x - rect[i].x;
		F = C * rect[i].x + D * rect[i].y;

		double DE = (A * D) - (B * C);

		if (DE != 0) {
			double X = ((E * D) - (B * F)) / DE;
			double Y = ((A * F) - (E * C)) / DE;

			if (p1.x < X && X < p2.x || p2.x < X && X < p1.x) {
				result.push_back({ X, Y });
			}
		}
	}

	return result;
}


//
static void getPolygons() {
	vector<point> semi;

	for (size_t i = 0; i < island.size(); i++) {
		int j = (i - 1) % island.size();
		vector<point> meets = getMeets(rectangle, island[j], island[i]);
	}
}

//
static double solution(double x1, double y1, double x2, double y2) {
	rectangle.push_back({ x1, y1 });
	rectangle.push_back({ x1, y2 });
	rectangle.push_back({ x2, y2 });
	rectangle.push_back({ x2, y1 });	// make rectangle
	getPolygons();						// initialize

	return 0;
}

void p046() {
	AutomatedInput Input;
	Input.set(
		"1 "
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
		//"50 20 70 80 4 "
		//"86 50 "
		//"30 10 "
		//"90 50 "
		//"30 90 "
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