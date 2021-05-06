/*
	Problem 042
	ID : FOSSIL
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;
// unit point
using Point = struct {
	double x, y;

};
// significant digit of question
const double MINERROR = 0.0000001;
// number of points that consists with each polygon
int numPoint1, numPoint2;
// two polygons
vector<Point> Polygon1, Polygon2;
// two polygons consists with lines
vector<pair<Point, Point>> Sides1, Sides2;
// area of each polygons
double Area1, Area2;
// polygon of union shape
vector<Point> Union;
// center line of union shape
pair<Point, Point> centerLine;

// return if two floats equals
static inline bool isEquals(double a, double b) {
	return fabs(a - b) < MINERROR;
}

// return if xPos is in lines x range
static inline bool inLinearRange(const pair<Point, Point> &li, const double xPos) {
	return (li.first.x <= xPos && xPos < li.second.x) || (li.second.x <= xPos && xPos < li.first.x);
}

// return length of line
static inline double getLength(const Point& p1, const Point& p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// return meet of two lines
static Point getMeet(const pair<Point, Point> &l1, const pair<Point, Point> &l2) {
	Point answer;
	answer.x = -1;
	answer.y = -1;

	double denom = (l1.first.x - l1.second.x) * (l2.first.y - l2.second.y) - (l1.first.y - l1.second.y) * (l2.first.x - l2.second.x);
	double coef1 = (l1.first.x * l1.second.y - l1.first.y * l1.second.x);
	double coef2 = (l2.first.x * l2.second.y - l2.first.y * l2.second.x);

	if (denom != 0) { 
		answer.x = (coef1 * (l2.first.x - l2.second.x) - coef2 * (l1.first.x - l1.second.x)) / denom;
		answer.y = (coef1 * (l2.first.y - l2.second.y) - coef2 * (l1.first.y - l1.second.y)) / denom;
	}

	return answer;
}

// return ypos of line when xpos was given
static double YPos(const pair<Point, Point>& l, const double xPos) {
	double x1 = l.first.x, x2 = l.second.x;
	double y1 = l.first.y, y2 = l.second.y;

	return ((y2 - y1) / (x2 - x1)) * (xPos - x1) + y1;
};

// return area of polygon when point inside of polygon was given
static double getArea(const vector<pair<Point, Point>> &sides, const Point &pt) {
	double sumArea = 0;
	
	// divide polygon by triangles and sum areas of triangles
	for (int i = 0; i < sides.size(); i++) {
		double a = getLength(sides[i].first, sides[i].second);
		double b = getLength(sides[i].first, pt);
		double c = getLength(sides[i].second, pt);
		double s = (a + b + c) / 2;

		sumArea += sqrt(s * (s - a) * (s - b) * (s - c));
	}

	return sumArea;
}

// set union polygon and center line
static void getUnion() {
	Union.clear();

	// add meets of two polygons
	for (int i = 0; i < numPoint1; i++) {
		for (int j = 0; j < numPoint2; j++) {
			Point meet = getMeet(Sides1[i], Sides2[j]);
			if (meet.x == -1)
				continue;
			if (inLinearRange(Sides1[i], meet.x) && inLinearRange(Sides2[j], meet.x))
				Union.push_back(meet);
		}
	}

	// add points of each polygion that is inside of another polygon
	for (int i = 0; i < numPoint1; i++) {
		if (isEquals(Area2, getArea(Sides2, Polygon1[i]))) {
			Union.push_back(Polygon1[i]);
		}
	}
	for (int i = 0; i < numPoint2; i++) {
		if (isEquals(Area1, getArea(Sides1, Polygon2[i]))) {
			Union.push_back(Polygon2[i]);
		}
	}
	
	if(Union.size() != 0) {
		Point mini = *min_element(Union.begin(), Union.end(), [](const Point& a, const Point& b) { return a.x > b.x; });
		Point maxi = *max_element(Union.begin(), Union.end(), [](const Point& a, const Point& b) { return a.x > b.x; });
		centerLine = {mini, maxi};
	}
}

// get height of union polygon on given xpos
static double getHeight(double xPos) {
	if (!inLinearRange(centerLine, xPos))
		return 0;

	double mid = YPos(centerLine, xPos);
	double high[2], low[2];
	int hi = 0, li = 0;

	for (int i = 0; i < numPoint1; i++) {
		if (inLinearRange(Sides1[i], xPos)) {
			if (YPos(Sides1[i], xPos) > mid)
				high[0] = YPos(Sides1[i], xPos);
			else
				low[0] = YPos(Sides1[i], xPos);
		}
	}

	for (int i = 0; i < numPoint2; i++) {
		if (inLinearRange(Sides2[i], xPos)) {
			if (YPos(Sides2[i], xPos) > mid)
				high[1] = YPos(Sides2[i], xPos);
			else
				low[1] = YPos(Sides2[i], xPos);
		}
	}

	return min(high[0], high[1]) - max(low[0], low[1]);
}

// get highest height of union polygon
static double optimize() {
	double low = 0, high = 100;
	for (int i = 0; i < 100; i++) {
		double aab = (2 * low + high) / 3;
		double abb = (low + high * 2) / 3;
		if (getHeight(aab) > getHeight(abb))
			high = abb;
		else
			low = aab;
	}
	return (low + high) / 2;
}

void p042() {
	cout.precision(10);
	cout.setf(ios::showpoint);

	AutomatedInput Input;
	Input.set(
		"2 "
		"5 5 "
		"35.74 35.85 69.64 50.00 73.52 82.55 43.50 92.22 17.67 76.18 "
		"16.47 8.02 60.98 14.62 66.80 37.74 45.89 67.22 13.04 55.19 "
		"4 3 "
		"73.84 11.41 71.61 32.72 39.87 38.84 22.41 17.87 "
		"75.13 51.64 47.72 87.34 15.97 64.56 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		Input >> numPoint1 >> numPoint2;

		Point tmp, before, centroid = {0, 0};
		// initialize vectors
		Polygon1.clear(); Polygon2.clear();
		Sides1.clear(); Sides2.clear();
		// getting input 
		for (int i = 0; i < numPoint1; i++) {
			Input >> tmp.x >> tmp.y;
			Polygon1.push_back(tmp);
			Sides1.push_back({before, tmp});
			before = tmp;
			centroid.x += tmp.x; centroid.y += tmp.y;
		}
		Sides1[0] = {Polygon1[numPoint1-1], Polygon1[0]};
		centroid = { centroid.x / numPoint1, centroid.y / numPoint1 };
		Area1 = getArea(Sides1, centroid);

		for (int i = 0; i < numPoint2; i++) {
			Input >> tmp.x >> tmp.y;
			Polygon2.push_back(tmp);
			Sides2.push_back({ before, tmp });
			before = tmp;
			centroid.x += tmp.x; centroid.y += tmp.y;
		}
		Sides2[0] = { Polygon2[numPoint2 - 1], Polygon2[0] };
		centroid = { centroid.x / numPoint2, centroid.y / numPoint2 };
		Area2 = getArea(Sides2, centroid);

		getUnion();

		cout << getHeight(optimize()) << endl;

	}
}