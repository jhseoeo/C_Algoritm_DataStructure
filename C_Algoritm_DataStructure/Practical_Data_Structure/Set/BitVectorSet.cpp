#include "BitVectorSet.h"

static int CheckSize(int n) {
	return BitSetMin < n && n < BitSetMax;
}

static int IsMember(const BitSet& s, int n) {
	if(CheckSize(n))
		return s & SetOf(n);
}

static void Add(BitSet* s, int n) {
	if (CheckSize(n))
		*s |= SetOf(n);
}

static void Remove(BitSet* s, int n) {
	if (CheckSize(n))
		*s &= ~SetOf(n);
}

static int Size(const BitSet& s) {
	int size = 0;
	for (int i = BitSetMin; i <= BitSetMax; i++) {
		if (s & SetOf(i))
			size++;
	}
	return size;
}

static void Print(const BitSet& s) {
	for (int i = BitSetMin; i <= BitSetMax; i++) {
		if (s & SetOf(i))
			printf("%d ", i);
	}
}

static int Equal(const BitSet& s1, const BitSet& s2) {
	return s1 == s2;
}

static BitSet Union(const BitSet& s1, const BitSet& s2) {
	return s1 | s2;
}

static BitSet Intersection(const BitSet& s1, const BitSet& s2) {
	return s1 & s2;
}

static BitSet Difference(const BitSet& s1, const BitSet& s2) {
	return s1 & ~s2;
}

static BitSet MakeBitSet() {
	return BitSetNull;
}

static BitSet SymmetricDifference(const BitSet& s1, const BitSet& s2) {
	return (s1 | s2) & ~(s1 & s2);
}

static int IsSubset(const BitSet& s1, const BitSet& s2) {
	return (s2 & ~s1) == BitSetNull;
}

static void GetSetNum(int& i) {
	printf("Enter the number of set you want to do action\n");
	printf(">> "); scanf("%d", &i); i--;
}

void BitVectorSetMain() {
	BitSet s[2];
	s[0] = MakeBitSet(); s[1] = MakeBitSet();

	printf("Two sets created.\n");
	int input, i;
	while (1) {
		system(CLEAR);
		printf("Current State\n");
		printf("Set 1 : "); Print(s[0]); printf("\n");
		printf("Set 2 : "); Print(s[1]); printf("\n");
		printf("\n");
		printf("Menu\n");
		printf("1. Add\n");
		printf("2. Remove\n");
		printf("3. Size\n");
		printf("4. Equal\n");
		printf("5. Union\n");
		printf("6. Intersection\n");
		printf("7. Difference\n");
		printf("8. Symmetric Difference\n");
		printf("9. Subset\n");
		printf("0. End\n");
		printf(">> "); scanf("%d", &input); putchar('\n');

		switch (input) {
		case 1:
			printf("Enter the value that you want to add in the set\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			GetSetNum(i);
			Add(&s[i], input);
			break;

		case 2:
			printf("Enter the value that yo want to remove from the stack\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			GetSetNum(i);
			Remove(&s[i], input);
			break;

		case 3:
			GetSetNum(i);
			printf("Size of set %d : %d", i + 1, Size(s[i]));
			sleep(1500);
			break;

		case 4:
			printf("%s\n", Equal(s[0], s[1]) ? "True" : "False");
			sleep(1500);
			break;

		case 5:
			printf("Union : "); Print(Union(s[0], s[1])); printf("\n");
			sleep(1500);
			break;
		case 6:
			printf("Intersection : "); Print(Intersection(s[0], s[1])); printf("\n");
			sleep(1500);
			break;

		case 7:
			printf("1 : set1 - set2\n");
			printf("2 : set2 - set1\n");
			printf("Choose one : "); scanf("%d", &input); printf("\n");
			printf("Difference : ");
			if (input == 1) Print(Difference(s[0], s[1]));
			if (input == 2) Print(Difference(s[1], s[0]));	
			printf("\n");
			sleep(1500);
			break;

		case 8:
			printf("Symmetric Difference : "); Print(SymmetricDifference(s[0], s[1])); printf("\n");
			sleep(1500);
			break;

		case 9:
			printf("1 : set1 is subset of set2\n");
			printf("2 : set2 is subset of set1\n");
			printf("Choose one : "); scanf("%d", &input); printf("\n");
			if (input == 1) printf("%s\n", IsSubset(s[1], s[0]) ? "True" : "False");
			else if (input == 2) printf("%s\n", IsSubset(s[0], s[1]) ? "True" : "False");
			sleep(1500);
			break;

		case 0:
			printf("Set Terminated\n");
			goto ENDLOOP;
			break;

		default:
			break;
		}
	} ENDLOOP:;
}