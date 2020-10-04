/*
	Problem 015
	ID : QUANTIZATION
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "../AutoInput.h"

#define INF 9876564321

using namespace std; 

int v[100], pSum[100], pSqSum[100];
int siz;
int cache[101][11];


static int sumPart(const int* pSum, int from, int to) {
	return pSum[to] - pSum[from];
}


static int minError(int from, int to) {
	int r = (sumPart(pSum, from, to)) / (to - from + 1);
	
	return (to - from + 1) * r * r + 2 * r * sumPart(pSum, from, to) + sumPart(pSqSum, from, to);
}


static int Quantize(int idx, int quants) {
	if (idx == siz) return 0;
	if (quants == 0) return INF;
	
	int& ret = cache[idx][quants];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = idx; i + quants < siz; i++) {
		ret = min(ret, minError(idx, i) + Quantize(i+1, quants-1));
	}

	return ret;
}

void p015() {

	AutomatedInput Input;
	Input.set(
		"2 "
		"10 3 "
		"3 3 3 1 2 3 2 2 2 1 "
		"9 3 "
		"1 744 755 4 897 902 890 6 777 "
		"12673939 "
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		int quants;
		Input >> siz >> quants;

		for (int i = 0; i < siz; i++) {
			Input >> v[i];
		}
		sort(v, v+ siz);

		pSum[0] = v[0];
		pSqSum[0] = v[0] * v[0];
		for (int i = 1; i < siz; i++) {
			pSum[i] = pSum[i - 1] + v[i];
			pSqSum[i] = pSqSum[i - 1] + v[i] * v[i];
		}

		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				cache[i][j] = -1;

		result[trial] = Quantize(0, quants);
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}