/*
	Problem 033
	ID : STRJOIN
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

static int concat(const vector<int> &strs) {
	int res = 0;
	vector<int> ss = strs;

	while (ss.size() > 1) {

		// get sum of two shortest strings and delete them
		int sum = ss[0] + ss[1];
		res += sum;
		ss.erase(ss.begin(), ss.begin() + 2);

		// re-insert the sum into array
		int idx;
		for (idx = 0; idx < ss.size(); idx++)
			if (ss[idx] > sum)
				break;
		ss.insert(ss.begin() + idx, sum);
	}

	return res;
}

void p033() {
	AutomatedInput Input;
	Input.set(
		"3 "
		"3 "
		"2 2 4 "
		"5 "
		"3 1 3 4 1 "
		"8 "
		"1 1 1 1 1 1 1 2 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		
		int length;
		Input >> length;

		vector<int> strs(length);
		for (int i = 0; i < length; i++) {
			Input >> strs[i];
		}

		sort(strs.begin(), strs.end());

		cout << concat(strs) << endl;
	}
}