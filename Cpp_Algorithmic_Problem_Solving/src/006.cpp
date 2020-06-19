/*
	Problem 006
	ID : CLOCKSYNK

	Entered quad-tree form from user,
	return an upside down quad tree entered.
*/

#include <iostream>
#include <vector>
#include <string>
#include "AutoInput.h"
#include "Problems.h"

using namespace std;

static string reverse(string::iterator &asd) { // passing iterater argument by reference, making function useful for calculate string length in recursive call.
	if (*asd == 'x') {
		asd++; string s1 = reverse(asd);
		asd++; string s2 = reverse(asd);
		asd++; string s3 = reverse(asd);
		asd++; string s4 = reverse(asd);
		return "x" + s3 + s4 + s1 + s2;	// rearrange string sequence
	} else if (*asd == 'b') {
		return "b";
	} else if (*asd == 'w') {
		return "w";
	} else { 
		cout << "뭐해ㅂ시발롬이" << endl;
	}
}

void p006() {
	AutomatedInput Input;

	Input.set(	// setting automated input form
		"4 "
		"w "
		"xbwwb "
		"xbwxwbbwb "
		"xxwwwbxwxwbbbwwxxxwwbbbwwwwbb "
	);

	int T;
	Input >> T;
	string* result = new string[T];

	for (int trial = 0; trial < T; trial++) {
		string qtree;
		Input >> qtree;
	
		auto tmp = qtree.begin();
		result[trial] = reverse(tmp);
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}