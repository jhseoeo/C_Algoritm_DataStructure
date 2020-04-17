#include "AVL_Tree.h"

static void Add(AVLNode** p, const Data n) {
	if (n == 0) {
		return;
	} else if (*p == NULL) {
		*p = AllocAVLNode(n, NULL, NULL);
	} else if ((*p)->data > n) {
		Add(&(*p)->left, n);
	} else if ((*p)->data < n) {
		Add(&(*p)->right, n);
	} else {
		return;
	}

	Rebalance(p);
}

static void Remove(AVLNode** root, AVLNode* p) {
	if (p == NULL)
		return;

	AVLNode* fRoot = AllocAVLNode(NULL, NULL, NULL);
	AVLNode* pNode = fRoot;
	AVLNode* cNode = *root;
	AVLNode* dNode;

	fRoot->right = *root;

	while (cNode != NULL && cNode->data != p->data) {
		pNode = cNode;
		if (p->data > cNode->data)
			cNode = cNode->right;
		else
			cNode = cNode->left;
	}

	if (cNode == NULL)
		return;

	dNode = cNode;
	if (dNode->left == NULL && dNode->right == NULL) {
		if (pNode->left == dNode)
			pNode->left = NULL;
		else
			pNode->right = NULL;

		free(dNode);

	} else if (dNode->left == NULL || dNode->right == NULL) {
		AVLNode* dcNode;

		if (dNode->left != NULL)
			dcNode = dNode->left;
		else
			dcNode = dNode->right;

		if (pNode->left == dNode)
			pNode->left = dcNode;
		else
			pNode->right = dcNode;

		free(dNode);

	} else {
		AVLNode* aNode = dNode->right;
		AVLNode* apNode = dNode;

		while (aNode->left != NULL) {
			apNode = aNode;
			aNode = aNode->left;
		}

		dNode->data = aNode->data;

		if (apNode->left == aNode)
			apNode->left = aNode->right;
		else
			apNode->right = aNode->right;


		free(aNode);
	}

	if (fRoot->right != *root)
		*root = fRoot->right;

	free(fRoot);
	Rebalance(root);
}

static AVLNode* Search(AVLNode* p, const Data n) {
	if (p == NULL) {
		return NULL;
	} else if (p->data > n) {
		return Search(p->left, n);
	} else if (p->data < n) {
		return Search(p->right, n);
	} else {
		return p;
	}
}

static void Print(AVLNode* p) {
	if (p != NULL) {
		Print(p->left);
		printf("%d ", p->data);
		Print(p->right);
	}
}

static void Clear(AVLNode* p) {
	if (p != NULL) {
		Clear(p->left);
		Clear(p->right);
		free(p);
	}
}

void AVL_Tree_Main() {
	AVLTree bst = NULL;
	printf("Binary Search Tree Created.\n");
	int input;
	while (1) {
		system(CLEAR);
		printf("BST (Inorder) : "); Print(bst); printf("\n");
		printf("\n");
		printf("Menu\n");
		printf("1. Add element\n");
		printf("2. Remove an element\n");;
		printf("3. Clear all nodes\n");
		printf("0. End\n");
		printf(">> "); scanf("%d", &input); putchar('\n');

		switch (input) {
		case 1:
			printf("Enter the value that you want to insert into tree\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			Add(&bst, input);
			break;
		case 2:
			printf("Enter the value that you want to remove from the tree\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			Remove(&bst, Search(bst, input));
			break;
		case 3:
			Clear(bst);
			bst = NULL;
			break;
		case 0:
			goto ENDLOOP;
			break;
		default:
			break;
		}
	} ENDLOOP:;
}