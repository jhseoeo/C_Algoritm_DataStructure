#include "ClosedHash.h"

static ClosedNode SetNode(Status status, Data data) {
	ClosedNode node;
	node.status = status;
	node.data = data;
	return node;
}

static int Hash(Data data, int size) {
	return data % size;
}

static ClosedNode* Search(const ClosedHash* h, Data data) {
	int key = Hash(data, h->size);
	do {
		if (h->Table[key].status == OCCUPIED && h->Table[key].data == data)
			return &h->Table[key];
		else if (h->Table[key].status == EMPTHY)
			return NULL;
		key = Hash(key + 1, h->size);
	} while (key != Hash(data, h->size));
	return NULL;
}

static int Add(ClosedHash* h, Data data) {
	int key = Hash(data, h->size);
	do {
		if (h->Table[key].status == EMPTHY || h->Table[key].status == DELETED) {
			h->Table[key] = SetNode(OCCUPIED, data);
			return 1;
		} else if (h->Table[key].status == OCCUPIED && Hash(h->Table[key].data, h->size) != Hash(data, h->size)) {
			return 0;
		} else if (h->Table[key].status == OCCUPIED && h->Table[key].data == data) {
			return 0;
		}
		key = Hash(key + 1, h->size);
	} while (key != Hash(data, h->size));
	return 0;
}

static int Remove(ClosedHash* h, Data data) {
	int key = Hash(data, h->size); 
	do {
		if (h->Table[key].status == OCCUPIED && h->Table[key].data == data) {
			h->Table[key] = SetNode(DELETED, -1);
			return 1;
		} else if (h->Table[key].status == DELETED) {
			return 0;
		}
		key = Hash(key + 1, h->size);
	} while (key != Hash(data, h->size));
	return 0;
}

static void Dump(const ClosedHash* h) {
	for (int i = 0; i < h->size; i++) {
		printf("%d : ", i);
		if (h->Table[i].status == OCCUPIED) {
			printf("%d(%d)\n", h->Table[i].data, Hash(h->Table[i].data, h->size));
		} else if (h->Table[i].status == DELETED) {
			printf("Removed\n");
		} else if (h->Table[i].status == EMPTHY) {
			printf("Empty\n");
		}
	}
}

static void Clear(ClosedHash* h) {
	for (int i = 0; i < h->size; i++) {
		h->Table[i] = SetNode(EMPTHY, -1);
	}
}

static void Terminate(ClosedHash* h) {
	free(h->Table);
}

static ClosedHash MakeClosedHash(int size) {
	ClosedHash h;
	h.size = size;
	h.Table = (ClosedNode*)malloc(size * sizeof(ClosedNode));
	for (int i = 0; i < size; i++) {
		h.Table[i] = SetNode(EMPTHY, -1);
	}
	return h;
}

void ClosedHashMain() {
	ClosedHash h = MakeClosedHash(13);
	printf("Hash table created.\n");
	int input;
	while (1) {
		system(CLEAR);
		Dump(&h);
		printf("\n");
		printf("Menu\n");
		printf("1. Add value\n");
		printf("2. Delete value\n");
		printf("3. Check exist\n");
		printf("4. Clear\n");
		printf("0. End\n");
		printf(">> "); scanf("%d", &input); putchar('\n');

		switch (input) {
		case 1:
			printf("Enter the value that you want to add to the hash table\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			Add(&h, input);
			break;
		case 2:
			printf("Enter the value that you want to remove from the hash table\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			Remove(&h, input);
			break;
		case 3:
			printf("Enter the value that you want to check if it exist from the hash table\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			printf("%s\n", Search(&h, input) != NULL ? "True" : "False");
			sleep(1500);
			break;
		case 4:
			Clear(&h);
			break;
		case 0:
			Terminate(&h);
			goto ENDLOOP;
			break;
		default:
			break;
		}
	} ENDLOOP:;
}