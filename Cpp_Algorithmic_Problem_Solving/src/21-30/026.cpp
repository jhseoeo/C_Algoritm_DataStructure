/*
	Problem 026
	ID : ZIMBABWE
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// MOD
static const int MOD = 1000000007;
// price of products. declare as string to handle digit
static string price;
// sorted price by ascending order
static string digit;
// number to divide price of products
static int n;
// length(number of digit) of price
static int len;
// cache
static int cache[1<<14][20][2];
// duplicated digits in prices
static int NUM[10];

// factorial
static int factorial(int n) {
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

static int generate(int index, int bitmask, int mod, bool less) {
	// base cases
	if (index == len)
		if (less && mod == 0)
			return 1;
		else
			return 0;
	
	int &res = cache[bitmask][mod][less];
	if (res != -1) return res;
	res = 0;

	for (int i = 0; i < len; i++) {
		if ((bitmask & (1 << i)) == 0) {
			// calculateing mods
			int MOD = (mod*10 + digit[i]) % n;

			// when current digit is lower than original price
			if (less || price[index] > digit[i]) {
				// count every cases
				res += generate(index + 1, bitmask | (1 << i), MOD, true);
				
			// when current digit equals with original price
			} else if (price[index] == digit[i]) {
				// count cases strictly
				res += generate(index + 1, bitmask | (1 << i), MOD, false);
			
			// when current digit is larger with original price
			} else {
				break;
			}
		}
		res %= MOD;
	}

	return res;
}

void p026() {
	
	AutomatedInput Input;
	Input.set(
		"4 "
		"321 3 "
		"123 3 "
		"422 2 "
		"12738173912 7 "
	);
	
	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {
		Input >> price >> n;

		// precalc
		digit = price;
		sort(digit.begin(), digit.end());
		len = price.length();

		// initialize caches
		for (int i = 0; i < (1 << 14); i++) {
			for (int j = 0; j < 20; j++) {
				cache[i][j][0] = -1;
				cache[i][j][1] = -1;
			}
		}

		for (int i = 0; i < 10; i++) {
			NUM[i] = 0;
		}

		// counting duplicating digits
		for (int i = 0; i < len; i++) {
			NUM[price[i]-'0']++;
		}

		// removing duplicated cases
		int res = generate(0, 0, 0, false);
		for (int i = 0; i < 10; i++) {
			if(NUM[i] != 0)
				res /= factorial(NUM[i]);
		}

		cout << res << endl;
	}
}