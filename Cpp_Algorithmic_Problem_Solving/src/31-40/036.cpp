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

int numPeople, numFoods;

static vector<int> eatable[20];

int huristic = 0;
static void getHuristic() {
	int satisfied = 0;
	for (int i = 0; i < numFoods; i++) {
		for (int j = 0; j < eatable[i].size(); j++) {
			satisfied |= (1 << eatable[i][j]);
		}

		if (satisfied == (1 << numPeople) - 1)
			break;
		else
			huristic++;
	}
}

static int find(const int stateSatisfied, int startSearchFrom, int depth) {

	if (stateSatisfied == (1 << numPeople) - 1)
		return 0;

	if (depth >= huristic)
		return 999999999;

	if (startSearchFrom >= numFoods)
		return 999999999;

	int ret = 999999999;
	for (int i = startSearchFrom; i < numFoods; i++) {
		int newState = stateSatisfied;
		for (int j = 0; j < eatable[i].size(); j++) {
			newState |= (1 << eatable[i][j]);
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
		for (int i = 0; i < numPeople; i++) {
			Input >> nameTmp;
			nameNumber.insert({ nameTmp, i });
		}

		for (int i = 0; i < numFoods; i++) {
			int numPeopleEatableFood;
			Input >> numPeopleEatableFood;
			for (int j = 0; j < numPeopleEatableFood; j++) {
				Input >> nameTmp;
				eatable[i].push_back(nameNumber[nameTmp]);
			}
		}

		sort(eatable, eatable + numFoods, 
			[](const vector<int>& a, const vector<int>& b) {return a.size() > b.size(); });

		getHuristic();

		cout << find(0, 0, 0) << endl;
	}
}