#include "ChainHash.h"

static CHNode* MakeCHNode() {
	CHNode* node = (CHNode*)malloc(sizeof(CHNode));
	SetCHNode(node, EMPTY, NULL);
	return node;
}

static void SetCHNode(CHNode* node, Data data, CHNode* next) {
	node->data = data;
	node->next = next;
}

static int Hash(Data data, int size) {
	return data % size;
}

static CHNode* Search(const ChainHash* h, Data data) {
	int key = Hash(Data, ChainHash->size);
    CHNode* cur = h->Table[key];
    while(cur != NULL || cur->Data == data) { cur = cur -> next; }
    return cur;
}

static int Add(ChainHash* h, Data data) {
    int key = Hash(Data, ChainHash->size);
    CHNode* newNode = MakeCHNode();
    SetCHNode(newNode, data, NULL);
    
    CHNode* cur = H->Table[key];
    
    if(cur == NULL) {
        H->Table[key] = newNode;
    } else {
        while(cur->next != NULL) { cur = cur->next; }
        cur->next = newNode;
    }
    return 1;
}

static int Remove(ChainHash* h, Data data) {
    int key = Hash(Data, ChainHash->size);
    
    CHNode* cur = H->Table[key];
    if(cur == NULL) {
        return 0;
    } else {
        if(cur->data = data) {
            H->Table[key] = NULL;
            free(cur);
            return 1;
        } else if (cur->next == NULL) {
            return 0;
        } else { 
            while(cur->next->data != data) { cur = cur->next; }
            CHNode* d = cur->next;
            cur->next = d->next;
            free(d);
            return 1;
        }
    }
}

static void Dump(const ChainHash* h) {
    for(int i = 0; i < h->size; i++) {
        printf("%d : ", i);
        CHNode* cur = h->Table[i];
        while(cur != NULL) {
            printf("%d ");
            cur = cur->next;
        }
        printf("\n");
    }
}

static void Clear(ChainHash* h) {
    
}

static ChainHash MakeChainHash(int size) {
    ChainHash h;
    h->size = size;
    Table = (CHNode*)malloc(size * sizeof(CHNode*));
    for(int i = 0; i < size; i++) {
        Table[i] = NULL;
    }
}