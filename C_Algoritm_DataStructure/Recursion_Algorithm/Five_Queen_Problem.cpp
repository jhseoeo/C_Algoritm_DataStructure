#include "Five_Queen_Problem.h"

const char* POSITION[8] = {
	"■□□□□□□□",
	"□■□□□□□□",
	"□□■□□□□□",
	"□□□■□□□□",
	"□□□□■□□□",
	"□□□□□■□□",
	"□□□□□□■□",
	"□□□□□□□■" };

void set(int i) {
	static int pos[8] = {0, };
	static int flag[8] = {0, };
	static int flag1[15] = {0, };
	static int flag2[15] = {0, };
	
	for(int j = 0; j < 8; j++) {
		if(!(flag[j] || flag1[i + j] || flag2[i - j + 7])) {
			pos[i] = j;
			
			if (i == 7)
				print(pos, 8);
			else {
				flag[j] = flag1[i+j] = flag2[i - j + 7] = 1;
				set(i + 1);
				flag[j] = flag1[i+j] = flag2[i - j + 7] = 0;
			}
		}
	}
}

void print(int* pos, int n) {
	for(int i = 0; i < n; i++) {
		printf("%s\n", POSITION[pos[i]]);
	}
	printf("\n");
}

void Five_Queen_Problem() {
	set(0);
}