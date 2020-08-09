/*
	Problem 008
	ID : FANMEETING

	
*/

#include <iostream>
#include <vector>
#include <string>
#include "Problems.h"
#include "AutoInput.h"

using namespace std;

vector<int> & convertInt(string s) { // convert entered string into vectorized number
	vector<int> num((unsigned int)s.size());

	for (int i = 0; i < (unsigned int)s.size(); i++) {
		num[i] = (s[i] == 'F' ? 0 : 1);
	}

	return num;
}

int changeInt(vector<int>& v) { // change vectorized number into integer
	int num = 0, mult = 1; // mult is multfly coefficient

	for (int i = 0; i < (unsigned int)v.size(); i++) {
		num += v[i] * mult;
		mult *= 10;
	}

	return num;
}

int getHugCnt(string m, string f) {
	vector<int> G; int L;
	if (m.size() > f.size()) {
		G = convertInt(m);
		L = changeInt(convertInt(m));
	}

	int cnt = 0;
	for (int i = L - 1; i < G.size() - L + 1; i++) {
		if (G[i] * L == 0)
			cnt++;
	}
}

void p008() {
	AutomatedInput Input;
	Input.set(
		"4 "
		"FFFMMM "
		"MMMFFF"
		"FFFFF"
		"FFFFFFFFFF"
		"FFFFM"
		"FFFFFMMMMF"
		"MFMFMFFFMMMFMF"
		"MMFFFFFMFFFMFFFFFFMFFFMFFFFMFMMFFFFFFF"
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		string Mem, Fan;
		Input >> Mem;
		Input >> Fan;
		
		result[trial] = getHugCnt();
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}