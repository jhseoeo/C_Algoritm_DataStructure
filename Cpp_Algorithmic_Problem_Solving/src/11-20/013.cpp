/*
	Problem 013
	ID : JLIS 
*/

#include <iostream>
#include <algorithm>
#include <string>
#include "../AutoInput.h"

using namespace std;

int A[101], B[101];
int cache[101][101];

int jlis(int idxA, int idxB) {
	int& ret = cache[idxA][idxB];
	if (ret != -1) return ret;

	int a = (idxA == -1 ? -1 : A[idxA]);
	int b = (idxB == -1 ? -1 : B[idxB]);

	ret = 2;

	int m = max(a, b);


	for (int i = idxA + 1; A[i] != -1; i++) {
		if (m < A[i])
			ret = max(ret, jlis(i, idxB) + 1);
	}
	for (int i = idxB + 1; B[i] != -1; i++) {
		if (m > B[i])
			ret = max(ret, jlis(idxA, i) + 1);
	}
	return ret;
}


void p013() {

	AutomatedInput Input;
	Input.set(
		"1 "

		"3 3 "
		"1 2 4 "
		"3 4 7 "

		//"3 3 "
		//"1 2 3 "
		//"4 5 6 "

		//"5 3 "
		//"10 20 30 1 2 "
		//"10 20 30 "
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {

		int sizeA, sizeB;
		Input >> sizeA;
		A[sizeA] = -1;
		Input >> sizeB;
		B[sizeB] = -1;

		int num;
		for (int i = 0; i < sizeA; i++) {
			Input >> num;
			A[i] = num;
		}
	
		for (int i = 0; i < sizeB; i++) {
			Input >> num;
			B[i] = num;
		}

		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				cache[i][j] = -1;
		
		result[trial] = jlis(-1, -1);
		for (int i = 0; A[i] != -1; i++) {
			for (int j = 0; B[j] != -1; j++) {
				result[trial] = max(jlis(i, j), result[trial]);
			}
		}
		
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}