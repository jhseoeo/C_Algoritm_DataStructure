#include "ChainHash.h"

static ChainNode* MakeCHNode() {
	ChainNode* node = (ChainNode*)malloc(sizeof(ChainNode));
	SetCHNode(node, 0, NULL);
	return node;
}

static void SetCHNode(ChainNode* node, Data data, ChainNode* next) {
	node->data = data;
	node->next = next;
}

static int Hash(Data data, int size) {
	return data % size;
}

static ChainNode* Search(const ChainHash* h, Data data) {
	int key = Hash(data, h->size);
    ChainNode* cur = h->Table[key];
    while(cur != NULL && cur->data != data) { cur = cur -> next; }
    return cur;
}

static int Add(ChainHash* h, Data data) {
    int key = Hash(data, h->size);
    ChainNode* newNode = MakeCHNode();
    SetCHNode(newNode, data, NULL);
    ChainNode* cur = h->Table[key];
    
    if(cur == NULL) {
        h->Table[key] = newNode;
    } else {
        while(cur->next != NULL) { cur = cur->next; }
        newNode->next = cur->next;
        cur->next = newNode;
    }
    return 1;
}

static int Remove(ChainHash* h, Data data) {
    int key = Hash(data, h->size);
    
    ChainNode* cur = h->Table[key];
    if(cur == NULL) {
        return 0;
    } else {
        if(cur->data == data) {
            h->Table[key] = cur->next;
            free(cur);
            return 1;
        } else if (cur->next == NULL) {
            return 0;
        } else { 
            while(cur->next->data != data) { cur = cur->next; }
            ChainNode* d = cur->next;
            cur->next = d->next;
            free(d);
            return 1;
        }
    }
}

static void Dump(const ChainHash* h) {
    for(int i = 0; i < h->size; i++) {
        printf("%d : ", i);
        ChainNode* cur = h->Table[i];
        while(cur != NULL) {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
}

static void Clear(ChainHash* h) {
    for (int i = 0; i < h->size; i++) {
        ChainNode* cur = h->Table[i];
        while (cur != NULL) {
            ChainNode* tmp = cur->next;
            free(cur);
            cur = tmp;
        }
        h->Table[i] = NULL;
    }
}

static void Terminate(ChainHash* h) {
    Clear(h);
    free(h->Table);
}

static ChainHash MakeChainHash(int size) {
    ChainHash h;
    h.size = size;
    h.Table = (ChainNode**)malloc(size * sizeof(ChainNode*));
    for(int i = 0; i < size; i++) {
        h.Table[i] = NULL;
    }
    return h;
}

void ChainHashMain() {
    ChainHash h = MakeChainHash(13);
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