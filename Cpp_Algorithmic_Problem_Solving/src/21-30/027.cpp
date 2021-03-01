/*
	Problem 027
	ID : RESTORE
*/

#include <iostream>
#include <algorithm>
#include <string>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// number datas
static int n;
// datas
static string datas[15];
// cache
static int cache[1<<15][16];

// function for handle when the index of list is -1
static string getData(const int& i) {
	return (i == -1) ? "" : datas[i];
}

// get the number of intersection of two string.
// a is located in front of b
static int getCombinedLength(const int& a, const int& b) {
	if (a == -1) {
		return 0;
	}

	const string& A = datas[a];
	const string& B = datas[b];

	// calculating intersections
	int uni = min(A.length(), B.length()) - 1;
	for (; uni > 0; uni--) {
		bool stop = false;
		for (int j = 0; j <= uni; j++) {
			if (A[A.length() - uni] != B[j])
				break;
			else
				stop = true;
		}

		if (stop)
			break;
	}

	return uni;
}

// calculating length of minimum string
static int generate(int bitmask, int before) {
	// base case. all cases are satisfied
	if (bitmask == ((1 << n) - 1))
		return getData(before).length();

	int& res = cache[bitmask][before + 1];
	if (res != -1) return res;
	res = 1999999999;

	for (int i = 0; i < n; i++) {
		// for only datas that aren't calculated yet
		if ((bitmask & (1 << i)) == 0) {
			// get next cases
			int tmp = generate(bitmask | (1 << i), i) + getData(before).length() - getCombinedLength(before, i);
			if (tmp < res) {
				res = tmp;
			}
		}
	}
	
	return res;
}

// traceback the origin string
static string reconstruct(int bitmask, int before) {
	if (bitmask == ((1 << n) - 1))
		return "";

	for (int i = 0; i < n; i++) {
		if ((bitmask & (1 << i)) == 0) {
			// for cases that has corresponding length of string.
			if (generate(bitmask, before) == 
				generate(bitmask | (1 << i), i) + getData(before).length() - getCombinedLength(before, i)) {
				
				return getData(i).substr(getCombinedLength(before, i)) + reconstruct(bitmask | (1 << i), i);
			}
		}
	}
	return "@@fuck@@";
}

void p027() {

	AutomatedInput Input;
	Input.set(
		"3 "
		"3 "
		"geo "
		"oji "
		"jing "
		"2 "
		"world "
		"hello "
		"3 "
		"abrac "
		"cadabra "
		"dabr "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		Input >> n;
		string tmp;

		// removing string that contained by other string.
		for (int i = 0; i < n; i++) {
			Input >> tmp;
			datas[i] = tmp;	
			for (int j = 0; j < i; j++) {
				if (datas[j].find(tmp) != -1) {
					i--; n--;
				}
			}
		}

		for (int i = 0; i < (1 << 15); i++) {
			for (int j = 0; j < 16; j++) {
				cache[i][j] = -1;
			}
		}

		cout << generate(0, -1) << " - " << reconstruct(0, -1) << endl;
	}
}