#include "003.h"



// first trial of problem 3

static int Pairing(const set<int>* pairsList,
	const int& numStudents,
	const int& start,
	const set<int>& matched) {

	int result = 0;
	for (int i = start; i < numStudents; i++) {

		if (find(matched.begin(), matched.end(), i) != matched.end())
			continue;

		for (auto j = pairsList[i].begin(); j != pairsList[i].end(); j++) {
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
		int Students, Friends;
		cin >> Students >> Friends;
		
		set<int>* PairsList = new set<int>[Students];

		for (int i = 0; i < Friends; i++) {
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