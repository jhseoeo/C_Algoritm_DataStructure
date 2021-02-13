/*
	Problem 021
	ID : PACKING
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

static int cache[1000][100];

static string s[100];
static int v[100], q[100];
static int n, vn;

static int pack(int capacity, int item) {
	if (capacity > vn)
		return -999999999;
	if (item == vn)
		return 0;

	int& let = cache[capacity][item];
	if (let != -1)
		return let;

	let = 0;
	// get larger one of two cases.
	// one case is adding stuff, and another is not.
	return let = max(pack(capacity, item + 1), q[item] + pack(capacity + v[item], item + 1));
}

// Trackback recursion
static void reconstruct(int capacity, int item,
	vector<int>& picked) {
	if (item == vn)
		return;

	// when stuff is not added
	if (pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, picked);
	} else {
		picked.push_back(item);
		reconstruct(capacity + v[item], item + 1, picked);
	}
}

void p021() {

	AutomatedInput Input;
	Input.set(
		"2 "
		"6 10 "
		"laptop 4 7 "
		"camera 2 10 "
		"xbox 6 6 "
		"grinder 4 7 "
		"dumbell 2 5 "
		"encyclopedia 10 4 "
		"6 17 "
		"laptop 4 7 "
		"camera 2 10 "
		"xbox 6 6 "
		"grinder 4 7 "
		"dumbell 2 5 "
		"encyclopedia 10 4 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		
		Input >> n >> vn;

		for (int i = 0; i < n; i++) {
			Input >> s[i] >> v[i] >> q[i];
		}

		for (int i = 0; i < 1000; i++)
			for (int j = 0; j < 100; j++)
				cache[i][j] = -1;
		cout << pack(0, 0) << " ";

		vector<int> ss;
		reconstruct(0, 0, ss);
		cout << ss.size() << endl;
		for (int i = 0; i < ss.size(); i++) {
			cout << s[ss[i]] << endl;
		}
		cout << endl;
	}
}