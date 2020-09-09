/*
	Problem 003
	ID : PICNIC
*/

#include <iostream>
#include <set>
#include <algorithm>
#include "../Problems.h"

using namespace std;

// first trial of problem 3

static int Pairing(const set<int>* pairsList, // data of students pairs 
	const int& numStudents,	// number of stduents
	const int& start,	// parameter for recursion. starting point of iteration
	const set<int>& matched) {	// set of stduents who already matched

	int result = 0;
	for (int i = start; i < numStudents; i++) {	// start iteration from starting point

		if (find(matched.begin(), matched.end(), i) != matched.end()) // if a student who has smaller number in pairs is already matched, pass him
			continue;

		for (auto j = pairsList[i].begin(); j != pairsList[i].end(); j++) {	// find friend pair 
			if (find(matched.begin(), matched.end(), *j) != matched.end())
				continue;
			set<int> copied = matched;
			copied.insert(i);
			copied.insert(*j);
			result += Pairing(pairsList, numStudents, i, copied);
			cout << result << " : " << i << ", " << *j << endl;
		}
	}

	if (matched.size() == numStudents)
		return 1;
	else 
		return result;
}


void p003() {

	int T; // number of trial

	cin >> T;

	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		int Students, Friends; // number of students, and number of students pairing(friends)
		cin >> Students >> Friends;
		
		set<int>* PairsList = new set<int>[Students];	// data of students pairs;

		for (int i = 0; i < Friends; i++) {	// making pairslist data
			int f1, f2;
			cin >> f1 >> f2;

			if (f1 > f2)
				PairsList[f2].insert(f1);
			else if (f1 < f2)
				PairsList[f1].insert(f2);
		}

		set<int> matched;
		result[trial] = Pairing(PairsList, Students, 0, matched);
	}

	for (int i = 0; i < T; i++)
		cout << result[i] << endl;
}