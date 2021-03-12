/*
	Problem 030
	ID : SHUSI
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// number of foods types
static int foods;
// prices of each foods
static int price[20];
// preference figures of each foods
static int preference[20];
// cache
static int cache[201];
// getting maximum preferences sum by given budget
static int getPref(int budget) {

	int ret = 0;
	cache[0] = 0;

	// searching all cases
	for (int bud = 1; bud <= budget; bud++) {
		int calc = 0;
		// traverse all cases of food type
		for (int food = 0; food < foods; food++) {
			// for only foods those price larger than current budget
			if (bud >= price[food])
				calc = max(calc, cache[(bud - price[food]) % 201] + preference[food]);
		}
		cache[bud % 201] = calc;
		ret = max(ret, calc);
	}

	return ret;
}


void p030() {

	AutomatedInput Input;
	Input.set(
		"2 "
		"6 10000 "
		"2500 7 "
		"3000 9 "
		"4000 10 "
		"5000 12 "
		"10000 20 "
		"15000 1 "
		"6 543975612 "
		"2500 7 "
		"3000 9 "
		"4000 10 "
		"5000 12 "
		"10000 20 "
		"15000 1 "
	);
	
	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		int budget;
		Input >> foods >> budget;
		for (int i = 0; i < foods; i++) {
			Input >> price[i];
			price[i] /= 100;
			Input >> preference[i];
		}

		cout << getPref(budget/100) << endl;
	}
}