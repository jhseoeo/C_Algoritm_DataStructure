#include "AVL_TreeNode.h"

AVLNode* AllocAVLNode(Data data, AVLNode* left, AVLNode* right) {
	AVLNode* node = (AVLNode*)malloc( sizeof(AVLNode) );
	node->left = left;
	node->right = right;
	node->data = data;
	return node;
}

static int GetHeight(AVLNode* node) {
	if (node == NULL)
		return 0;
	
	int lefth = GetHeight(node->left);
	int righth = GetHeight(node->right);

	if (lefth > righth)
		return lefth + 1;
	else
		return righth + 1;
}

static int GetBFactor(AVLNode* node) {
	if (node == NULL)
		return 0;

	int lefth = GetHeight(node->left);
	int righth = GetHeight(node->right);

	return lefth - righth;
}

static AVLNode* RotateLL(AVLNode* node) {
	AVLNode* pNode = node;
	AVLNode* cNode = node->left;

	pNode->left = cNode->right;
	cNode->right = pNode;

	return cNode;
}

static AVLNode* RotateRR(AVLNode* node) {
	AVLNode* pNode = node;
	AVLNode* cNode = node->right;

	pNode->right = cNode->left;
	cNode->left = pNode;

	return cNode;
}

static AVLNode* RotateLR(AVLNode* node) {
	AVLNode* pNode = node;
	AVLNode* cNode = node->left;

	pNode->left = RotateRR(cNode);
	return RotateLL(pNode);
}

static AVLNode* RotateRL(AVLNode* node) {
	AVLNode* pNode = node;
	AVLNode* cNode = node->right;

	pNode->right = RotateLL(cNode);
	return RotateRR(pNode);
}

AVLNode* Rebalance(AVLNode** node) {
	int BFactor = GetBFactor(*node);

	printf(">>%d<<\n", BFactor);

	if (BFactor > 1) {
		if (GetBFactor((*node)->left) > 0) {
			*node = RotateLL(*node);
		} else {
			*node = RotateLR(*node);
		}

	} else if(BFactor < -1) {
		if (GetBFactor((*node)->right) < 0) {
			*node = RotateRR(*node);
		} else {
			*node = RotateRL(*node);
		}
	}

	return *node;
}