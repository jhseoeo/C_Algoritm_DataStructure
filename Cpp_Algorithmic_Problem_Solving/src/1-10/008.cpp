/*
	Problem 008
	ID : FANMEETING
*/

#include <iostream>
#include <vector>
#include <string>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

/*
vector<int> karatsuba(const vector<int>& A, const vector<int>& B) { 
	int an = A.size(), bn = B.size();
	if(an < bn) return karatsuba(B, a);

	if(an == 0 || bn == 0) return vector<int>();
	if(an <= 50) return multyply (a,b);

	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0); addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half+half);
	return ret;
}
*/
// Originally, it should be used Karatsuba Algorithm. 
// I used common multiplying algorithm instead of it just because of readability.
vector<int> karatsuba(const vector<int>& A, const vector<int>& B) { 
	vector<int> C(int(A.size() + B.size()-1));
	
	// Don't consider carrying
	for (int i = 0; i < B.size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			C[i + j] += A[j] * B[i];
		}
	}

	// multiplying two vectorized number
	for (int i = 0; i < C.size(); i++) {
		cout << C[i];
	}

	cout << endl;
	return C;
}

int getHugCnt(string m, string f) {	
	vector<int> M(m.size()), F(f.size());

	//Male is 1, female is 0 on this algorithm.
	for (int i = 0; i < m.size(); i++) M[i] = (m[i] == 'M');

	// Reverse digit of operand.
	for (int i = 0; i < f.size(); i++) F[f.size() - i - 1] = (f[i] == 'M');

	int hugCnt = 0;

	// number of 0 on specific area of the result is exactly same with number of cases that males don't meet each other.
	vector<int> Z = karatsuba(M, F); 
	for (int i = M.size() - 1; i < F.size(); i++) {
		if (Z[i] == 0)
			hugCnt++;
	}

	return hugCnt;
}

void p008() {
	AutomatedInput Input;
	Input.set(
		"4 "
		"FFFMMM "
		"MMMFFF "
		"FFFFF "
		"FFFFFFFFFF "
		"FFFFM "
		"FFFFFMMMMF "
		"MFMFMFFFMMMFMF "
		"MMFFFFFMFFFMFFFFFFMFFFMFFFFMFMMFFFFFFF "
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		string Mem, Fan;
		Input >> Mem >> Fan;
		
		result[trial] = getHugCnt(Mem, Fan);
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}