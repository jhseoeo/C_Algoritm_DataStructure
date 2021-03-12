/*
	Problem 032
	ID : LUNCHBOX
*/

#include <iostream>
#include <algorithm>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

static pair<int, int> heat[10000];


static int TimeToEat(int n) {
	int sum = 0, eat = 0;

	for (int i = n - 1; i >= 0; i--) {
		sum += heat[i].second;
		if (eat - heat[i].second > heat[i].first)
			eat = ((eat - heat[i].second) < 0 ? 0 : eat - heat[i].second);
		else
			eat = heat[i].first;
	}

	return sum + eat;
}

void p032() {
	AutomatedInput Input;
	Input.set(
		"2 "
		"3 "
		"2 2 2 "
		"2 2 2 "
		"3 "
		"1 2 3 "
		"1 2 1 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		int n;
		Input >> n;
		
		for (int i = 0; i < n; i++) {
			Input >> heat[i].second; // spending time to heat lunchbox
		}

		for (int i = 0; i < n; i++) {
			Input >> heat[i].first; // spending time to eat lunchbox
		}

		sort(heat, heat + n);

		cout << TimeToEat(n) << endl;
	}
}