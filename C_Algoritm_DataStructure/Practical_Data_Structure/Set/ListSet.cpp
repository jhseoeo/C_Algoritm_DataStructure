#include "ListSet.h"

static ListSet MakeListSet(int size) {
	ListSet a;
	a.max = size;
	a.size = 0;
	a.set = (int*)malloc(size * sizeof(int));
	return a;
}

static int isMember(const ListSet *s, int n) {
	for(int i = 0; i < s->size; i++)
		if(s->set[i] == n)
			return i;
	return -1;
}

static void Add(ListSet *s, int n) {
	if( s->size < s->max && isMember(s, n) == -1 )
		s->set[s->size++] = n;
}

static void Remove(ListSet *s, int n) {
	int idx = isMember(s, n);
	if( idx != -1 )
		s->set[idx] = s->set[--s->size];	
}

static int Size(const ListSet* s) {
	return s->size;
}

static void Assign(ListSet* s1, const ListSet* s2) {
	s1->max = s2->max;
	s1->size = s2->size;
	if(s1->set != NULL) free(s1->set);
	s1->set = (int*)malloc(s1->max * sizeof(int));
	for(int i = 0; i < s2->size; i++) {
		s1->set[i] = s2->set[i];
	}
}

static int Equal(const ListSet* s1, const ListSet* s2) {
	if (s1->size != s2->size) return 0;
	
	for(int i = 0; i < s1->size; i++) {
		for(int j = 0; j < s2->size; j++) {
			if(s1->set[i] == s2->set[j]) break;
			if(j == s2->size)	return 0;
		}
	}
	return 1;
}

static ListSet* Union(ListSet* s1, const ListSet* s2, const ListSet* s3) {
	Assign(s1, s2);
	for(int i = 0; i < s3->size; i++)
		Add(s1, s3->set[i]);
	return s1;
}

static ListSet* Intersection(ListSet* s1, const ListSet* s2, const ListSet* s3) {
	s1->size = 0;
	for(int i = 0; i < s2->size; i++) {
		if(isMember(s3, s2->set[i]) != -1)
			Add(s1, s2->set[i]);
	}
	return s1;
}

static ListSet* Difference(ListSet* s1, const ListSet* s2, const ListSet* s3) {
	s1->size = 0;
	for(int i = 0; i < s2->size; i++) {
		if(isMember(s3, s2->set[i]) == -1)
			Add(s1, s2->set[i]);
	}
	return s1;
}

static void Print(const ListSet* s) {
	for(int i = 0; i < s->size; i++)
		printf("%d ", s->set[i]);
}

static void Terminate(ListSet* s) {
	if(s->set != NULL) free(s->set);
	s->size = s->max = 0;
}

static ListSet* SymmetricDifference(ListSet* s1, const ListSet* s2, const ListSet* s3) {
	Difference(s1, Union(&MakeListSet(10), s2, s3), Intersection(&MakeListSet(10), s2, s3));
	return s1;
}

static int IsSubset(const ListSet* s1, const ListSet* s2) {
	for (int i = 0; i < s1->size; i++) {
		if(isMember(s2, s1->set[i]) == -1)
			return 0;
	}
	return 1;
}

static void GetSetNum(int& i) {
	printf("Enter the number of set you want to do action\n");
	printf(">> "); scanf("%d", &i); i--;
}

void ListSetMain() {
	ListSet s[3];
	s[0] = MakeListSet(10); s[1] = MakeListSet(10); s[2] = MakeListSet(10);
	printf("Two sets created.\n");
	int input, i;
	while (1) {
		system(CLEAR);
		printf("Current State\n");
		printf("Set 1 : "); Print(&s[0]); printf("\n");
		printf("Set 2 : "); Print(&s[1]); printf("\n");
		printf("\n");
		printf("Menu\n");
		printf("1. Add\n");
		printf("2. Remove\n");
		printf("3. Size\n");
		printf("4. Assign\n");
		printf("5. Equal\n");
		printf("6. Union\n");
		printf("7. Intersection\n");
		printf("8. Difference\n");
		printf("9. Symmetric Difference\n");
		printf("10. Subset\n");
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
			printf("Size of set %d : %d", i+1, Size(&s[i]));
			sleep(1500);
			break;

		case 4:
			printf("1. set 1 = set 2\n");
			printf("2. set 2 = set 1\n");
			printf(">> "); scanf("%d", &input);
			Assign(&s[input == 1 ? 0 : 1], &s[input == 1 ? 1 : 0]);
			break;

		case 5:
			printf("%s\n", Equal(&s[0], &s[1]) ? "True" : "False");
			sleep(1500);
			break;

		case 6:
			Union(&s[2], &s[0], &s[1]);
			printf("Union : "); Print(&s[2]); printf("\n");
			sleep(1500);
			break;
		case 7:
			Intersection(&s[2], &s[0], &s[1]);
			printf("Intersection : "); Print(&s[2]); printf("\n");
			sleep(1500);
			break;

		case 8:
			printf("1 : set1 - set2\n");
			printf("2 : set2 - set1\n");
			printf("Choose one : "); scanf("%d", &input); printf("\n");
			if (input == 1) Difference(&s[2], &s[0], &s[1]);
			if (input == 2) Difference(&s[2], &s[1], &s[2]);
			printf("Difference : "); Print(&s[2]); printf("\n");
			sleep(1500);
			break;

		case 9:
			SymmetricDifference(&s[2], &s[0], &s[1]);
			printf("Symmetric Difference : "); Print(&s[2]); printf("\n");
			sleep(1500);
			break;

		case 10:
			printf("1 : set1 is subset of set2\n");
			printf("2 : set2 is subset of set1\n");
			printf("Choose one : "); scanf("%d", &input); printf("\n");
			if (input == 1) input = IsSubset(&s[1], &s[0]);
			if (input == 2) input = IsSubset(&s[0], &s[1]);
			printf("%s\n", input ? "True" : "False" ); 
			sleep(1500);
			break;

		case 0:
			Terminate(&s[0]);
			Terminate(&s[1]);
			Terminate(&s[2]);
			printf("Set Terminated\n");
			goto ENDLOOP;
			break;

		default:
			break;
		}
	} ENDLOOP:;
}
