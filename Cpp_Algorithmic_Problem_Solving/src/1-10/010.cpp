/*
	Problem 010
	ID : WILDCARD
	
	
*/

#include <iostreasm>
#include <string>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// variables for memoization.
// declare 101x101 array because maximum input is 100(length of string). 
int cache[101][101];

bool match(const string& w, const string& s,
	const int &wl, const int &sl) {

	int& ret = cache[wl][sl];
	if (ret != -1) return ret;

	if (w.size() == 1 && w[0] == '*')
		return ret = 1;

	if (!w.empty() && !s.empty()) {
		if (w[0] == s[0] || w[0] == '?') {
			return match(w.substr(1), s.substr(1), wl+1, sl+1);
		} else if (w[0] == '*') {
			for (int i = 0; i < s.size(); i++) {
				if (match(w.substr(1), s.substr(i), wl+1, sl+i))
					return ret = 1;
			}
		}
	} else if (w.empty() && s.empty()) {
		return ret = 1;
	}
	return ret = 0;
}
 
void p010() {

	AutomatedInput Input;
	Input.set(
		"3 "

		"he?p "
		"3 "
		"help heap helpp "

		"*p* "
		"3 "
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

			// reinitialize cache before call function
			for (int i = 0; i < 101; i++) {
				for (int j = 0; j < 101; j++) {
					cache[i][j] = -1;
				}
			}

			if(match(wild, str, 0, 0))
				cout << str << endl;
		}
	}

	delete[] result;
}