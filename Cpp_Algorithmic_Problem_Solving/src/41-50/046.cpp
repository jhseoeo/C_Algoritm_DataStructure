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

using linear = struct {
	double x, y, dx, dy;
};

vector<linear> island;




static double solution() {



	return 0;
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

		double px1, py1, px2, py2;
		Input >> px1 >> py1;
		for (int i = 1; i < n; i++) {
			px2 = px1; py2 = py1;
			Input >> px1 >> py1;

			island.push_back({ px1, py1, px2, py2 });
		}
		island.push_back({ island[0].dx, island[0].dy, px1, py1 });

		cout << solution() << endl;
	}
}