/*
	Problem 043
	ID : PASS486
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

static const int MAXNUM = 10000000;

static const int MAXPRIME = 3163;

static bool numb[MAXPRIME];

static vector<int> primes;

static int numFactors[MAXNUM];

static void Initialize() {
	memset(numb, true, sizeof(numb));
	numb[0] = numb[1] = 0;
	int cur = 2;
	while (cur < MAXPRIME) {
		if (numb[cur]) {
			for (int i = cur * cur; i < MAXPRIME; i += cur) {
				numb[i] = false;
			}
			primes.push_back(cur);
		}
		cur++;
	}

	memset(numFactors, 0, sizeof(numFactors));
	numFactors[1] = 1;
	for (int i = 2; i < MAXNUM; i++) {
		int p = -1, l;
		for (int j = 0; j < primes.size(); j++) {
			if (i % primes[j] == 0) {
				p = i / primes[j];
				l = primes[j];
				break;
			}
		}

		if (p == -1) {
			numFactors[i] = 2;
			continue;
		}

		int times;
		for (times = 0; p % l == 0; times++) {
			p /= l;
		}
	
		numFactors[i] = numFactors[i / l] * (times + 2) / (times + 1);

	}
}

static int getNumFactors(int n) {
	vector<int> factors(MAXPRIME);

	for (int i = primes.size() - 1; n > 1 && i >= 0;) {
		if (n % primes[i] == 0) {
			n /= primes[i];
			factors[primes[i]]++;
			//cout << n << " " << primes[i] << " " << factors[primes[i]] << endl;
		} else 
			i--;
	}

	if (n != 1) factors[0]++;

	int ret = 1;
	for (int i = 2; i < MAXPRIME; i++) {
		ret *= (factors[i] + 1);
	}
	
	return ret;
}

static int Process(int low, int high, int numDivisor) {
	int ret = 0;
	for (int i = low; i <= high; i++) {
		if (numFactors[i] == numDivisor)
			ret++;
		//cout << i << " ";
	}
	return ret;
}

void p043() {
	AutomatedInput Input;
	Input.set(
		"3 "
		"2 2 10 "
		"12 486 486 "
		"200 1000000 2000000 "
	);

	Initialize();
	int T;
	Input >> T;


	for (int trial = 0; trial < T; trial++) {
		int numDivisor, low, high;
		Input >> numDivisor >> low >> high;

		cout << Process(low, high, numDivisor) << endl;
	}
	cout << "го©ю";
}