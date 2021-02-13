/*
	Problem 020
	ID : NUMB3RS
*/

#include <iostream>
#include <vector>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

static const int MOD = 10000000;

static double cache[101][51];
static int v, d, s;
static int connection[51][51], deg[51];

static double search(int days, int starts, const int& des) {
	if (days == 0) return (starts == des ? 1.0 : 0.0);

	double& ret = cache[days][starts];
	if (ret > -0.5) return ret;

	ret = 0.0;
	for (int i = 0; i < v; i++) {
		if (connection[starts][i]) {
			// accumulating all possibilities of satisfying given conditions
			ret += search(days - 1, i, des) / deg[starts]; 
			// divide into the number of edges of current node.

			/*cout << "search(" << days << ", " << starts << ", " << des << ") -> ";
			cout << "search(" << days-1 << ", " << i << ", " << des << ") / " << deg[starts] << " : " << ret << endl;*/
		}
	}
	
	return ret;
}

void p020() {

	AutomatedInput Input;
	Input.set(
		"2 "
		"5 2 0 "
		"0 1 1 1 0 "
		"1 0 0 0 1 "
		"1 0 0 0 0 "
		"1 0 0 0 0 "
		"0 1 0 0 0 "
		"3 "
		"0 2 4 "
		"8 2 3 "
		"0 1 1 1 0 0 0 0 "
		"1 0 0 1 0 0 0 0 "
		"1 0 0 1 0 0 0 0 "
		"1 1 1 0 1 1 0 0 "
		"0 0 0 1 0 0 1 1 "
		"0 0 0 1 0 0 0 1 "
		"0 0 0 0 1 0 0 0 "
		"0 0 0 0 1 1 0 0 "
		"4 "
		"3 1 2 6 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		
		for (int i = 0; i < 51; i++) {
			deg[i] = 0;
		}

		Input >> v >> d >> s;

		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				Input >> connection[i][j];
				deg[i] += connection[i][j];
			}
		}

		int n;
		Input >> n;
		
		for (int o = 0; o < n; o++) {
			int k;
			Input >> k;

			for (int i = 0; i < 101; i++) {
				for (int j = 0; j < 51; j++) {
					cache[i][j] = -1;
				}
			}

			cout << search(d, s, k) << " ";
		}
		cout << endl;
	}
}