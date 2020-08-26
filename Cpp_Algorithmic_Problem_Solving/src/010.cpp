/*
	Problem 010
	ID : WILDCARD
	
	
*/

#include <iostream>
#include <string>
#include "Problems.h"
#include "AutoInput.h"

using namespace std;


bool match(const string &w, const string &s) {
	int pos = 0;
	while(pos < w.size() && pos < s.size() && w[pos] == s[pos] || w[pos] == '?') pos++;
	
	if (pos == w.size()) {
		return pos == s.size();
	} else if(w[pos] == '*') {
		for(int skip = 0; skip + pos < s.size(); skip++) {
			if(match(w.substr(pos+1), s.substr(pos+skip)))
				return true;
		}
	} else {
		return false;
	} 
}

void p010() {
	AutomatedInput Input;
	Input.set(
		"3 "
		"he?p "
		"3 "
		"help heap helpp "
		"*p* "
		"help papa hello "
		"*bb* "
		"1 "
		"babbbc "
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		string wild, str;
		int n;
		Input >> wild;
		Input >> n;
		for(int i = 0; i < n; i++) {
			Input >> str;
			if(match(wild, str))
				cout << str << endl;
		}
	}

	delete[] result;
}