/*
	Problem 044
	ID : POTION
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// getting gcd of two numbers
static int gcd(int p, int q) {
	if (q == 0) return p;
	return gcd(q, p % q);
}

// getting gcd of vector elements
static int arraygcd(const vector<int>& arr) {
	int t = arr[0];
	for (size_t i = 1; i < arr.size(); i++)
		t = gcd(t, arr[i]);
	return t;
}

// getting minimum amount of each ingredients
static vector<int> Process(const vector<int>& ingredients, vector<int>& already) {
	vector<int> res;

	const int GCD = arraygcd(ingredients);
	int coef = 1;
	bool finish = true;
	do {
		finish = true;
		for (size_t i = 0; i < ingredients.size(); i++) {
			if (ingredients[i] / GCD * coef < already[i]) {
				finish = false;
				coef++;
				break;
			}
		}
	} while (!finish);

	for (size_t i = 0; i < ingredients.size(); i++)
		res.push_back(ingredients[i] * coef / GCD);
	
	return res;
}

void p044() {
	AutomatedInput Input;
	Input.set(
		"3 "
		"4 "
		"4 6 2 4 "
		"6 4 2 4 "
		"4 "
		"4 6 2 4 "
		"7 4 2 4 "
		"3 "
		"4 5 6 "
		"1 2 3 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		int n;
		Input >> n; 

		vector<int> ingredients(n);
		for (int i = 0; i < n; i++)
			Input >> ingredients[i];

		vector<int> already(n);
		for (int i = 0; i < n; i++)
			Input >> already[i];

		vector<int> result = Process(ingredients, already);
		for (int i = 0; i < n; i++) {
			cout << result[i] - already[i] << " ";
		}
		cout << endl;
	}
}