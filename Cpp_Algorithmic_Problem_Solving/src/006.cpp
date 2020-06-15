#include "006.h"

#define MAXSIZE 20

static char board[MAXSIZE][MAXSIZE] = { {0,}, };



void p006() {
	AutomatedInput Input;

	Input.set(
		"4 "
		"w "
		"xbwwb "
		"xbwxwbbwb "
		"xxwwwbxwxwbbbwwxxxwwbbbwwwwbb "
	);

	int T;
	Input >> T;
	int* result = new int[T];

	for (int trial = 0; trial < T; trial++) {
		string pic;
		Input >> pic;

	
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;
}