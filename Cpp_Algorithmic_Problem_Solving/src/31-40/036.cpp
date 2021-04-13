/*
	Problem 036
	ID : ALLERGY
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;
// number of people
static int numPeople;
// number of foods
static int numFoods;
// list of people who are edible foods 
static vector<int> ediable[20];
// huristic value
static int huristic = 0;
// get huristic value
static void getHuristic() {
	int satisfied = 0;
	for (int i = 0; i < numFoods; i++) {
		for (int j = 0; j < ediable[i].size(); j++) {
			satisfied |= (1 << ediable[i][j]);
		}

		// all the people are satisfied, finish the loop
		if (satisfied == (1 << numPeople) - 1)
			break;
		else
			huristic++;
	}
}
// find minimum value
static int find(const int stateSatisfied, int startSearchFrom, int depth) {
	// when all the people are satisfied
	if (stateSatisfied == (1 << numPeople) - 1)
		return 0;
	// when the depth of recursion become larger than huristic limit
	if (depth >= huristic)
		return 999999999;
	// when the starting index of foods are larger than number of foods
	if (startSearchFrom >= numFoods)
		return 999999999;

	int ret = 999999999;
	// finding minimum value
	for (int i = startSearchFrom; i < numFoods; i++) {
		int newState = stateSatisfied;
		// applying satisfaction
		for (int j = 0; j < ediable[i].size(); j++) {
			newState |= (1 << ediable[i][j]);
		}

		ret = min(ret, find(newState, i+1, depth+1) + 1);
	}

	return ret;
}

void p036() {
	AutomatedInput Input;
	Input.set(
		"2 "
		"4 6 "
		"cl bom dara minzy "
		"2 dara minzy "
		"2 cl minzy "
		"2 cl dara "
		"1 cl "
		"2 bom dara "
		"2 bom minzy "
		"10 7 "
		"a b c d e f g h i j "
		"6 a c d h i j "
		"3 a d i "
		"5 b c f h i "
		"4 b e g j "
		"5 b c g h i "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		Input >> numPeople >> numFoods;
		
		map<string, int> nameNumber;
		string nameTmp;
		// entering names 
		for (int i = 0; i < numPeople; i++) {
			Input >> nameTmp;
			nameNumber.insert({ nameTmp, i });
		}
		// entering foods ediable
		for (int i = 0; i < numFoods; i++) {
			int numPeopleEdibleFood;
			Input >> numPeopleEdibleFood;
			for (int j = 0; j < numPeopleEdibleFood; j++) {
				Input >> nameTmp;
				ediable[i].push_back(nameNumber[nameTmp]);
			}
		}

		// sort foods vector by size
		sort(ediable, ediable + numFoods, 
			[](const vector<int>& a, const vector<int>& b) {return a.size() > b.size(); });

		getHuristic();

		cout << find(0, 0, 0) << endl;
	}
}