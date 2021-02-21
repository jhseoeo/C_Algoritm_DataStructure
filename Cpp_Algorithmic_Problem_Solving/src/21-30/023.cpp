/*
	Problem 023
	ID : MORSE
*/

#include <iostream>
#include <string>
#include <cmath>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

int K = 1000000000 + 100;

// pre-calculated binomial coefficient
static int bin[201][201];
// calculate above.
static void binSet() {
	memset(bin, 0, sizeof(bin));

	for (int i = 0; i <200; i++) {
		bin[i][0] = bin[i][i] = 1;
		for (int j = 1; j < i; j++) {
			bin[i][j] = min(K, bin[i - 1][j] + bin[i - 1][j - 1]);
		}
	}
}

// variable to skip answers
static int skip;

//static void generate(int n, int m, string s) {
//
//	if (skip < 0)
//		return;
//
//	if (n == 0 && m == 0) {
//		if (skip == 0)
//			cout << s << endl;
//		skip--;
//		return;
//	}
//
//	// skip when remaining recursons are large enough
//	if (skip >= bin[n+m][m]) {
//		skip -= bin[n+m][m];
//		return;
//	}
//
//	if (n > 0)generate(n - 1, m, "-" + s);
//	if (m > 0)generate(n, m - 1, "o" + s);
//}

static string generate(int n, int m, int skip) {
	// base case
	if (n == 0) {
		return string(m, 'o');
	} 
	// don't skip 
	else if (skip < bin[n + m - 1][n - 1]) {
		return "-" + generate(n - 1, m, skip);
	} 
	// skip 
	else {
		return "o" + generate(n, m - 1, skip - bin[n + m - 1][n - 1]);
	}
}


void p023() {

	AutomatedInput Input;
	Input.set(
		"2 2 2 "
	);

	int n, m;

	Input >> n >> m >> skip;

	binSet();
	//generate(n, m, "");
	cout << generate(n, m, skip);
}