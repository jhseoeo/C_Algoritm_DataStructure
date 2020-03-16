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
	 = Hash();

}



static ChainHash MakeChainHash(int size) {
	
}