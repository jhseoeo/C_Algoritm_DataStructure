#include "Binary_Search_Tree.h"


static void Add(BSTNode* &p, const Data n) {
	if (p == NULL) {
		p = AllocBSTNode();
		SetBSTNode(p, NULL, NULL, n);
	} else if (p->data > n) {
		Add(p->left, n);
	} else if (p->data < n) {
		Add(p->right, n);
	} else {
		return;
	}
}

static void Remove(BSTNode** root, BSTNode* p) {
	if (*root == p) {
		*root = NULL;
		free(p);
		return;
	} else if( p == NULL) {
		return;
	}

	BSTNode* prnt = *root;
	while (p != prnt->left && p != prnt->right) {
		if (prnt->data > p->data)
			prnt = prnt->left;
		else if (prnt->data < p->data)
			prnt = prnt->right;
	}

	printf("%s", (prnt->left == p || prnt->right == p) ? "しし" : "いい"); sleep(1000);

	if (p->left == NULL && p->right == NULL) {
		if (prnt->left == p)
			prnt->left = NULL;
		else 
			prnt->right = NULL;
		free(p);
	} else if (p->left == NULL && p->right != NULL) {
		prnt->left == p ? prnt->left : prnt->right = p->right;
		free(p);
	} else if (p->left != NULL && p->right == NULL) {
		prnt->left == p ? prnt->left : prnt->right = p->left;
		free(p);
	} else {
		BSTNode* leftMost;
		for (leftMost = p->left; leftMost->right != NULL; leftMost = leftMost->right);
		BSTNode* prntLeftMost = (p->left == leftMost || p -> right == leftMost ? p : p->left);
		while(prntLeftMost->right != leftMost && prntLeftMost->left != leftMost) {
			prntLeftMost = prntLeftMost->right;
		}

		prntLeftMost->left = leftMost->left;
		p->data = leftMost->data;
		free(leftMost);
	}
}

static BSTNode* Search(BSTNode* p, const Data n) {
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

static void Print(BSTNode* p) {
	if (p != NULL) {
		Print(p->left);
		printf("%d ", p->data);
		Print(p->right);
	}
}

static void Clear(BSTNode* p) {
	if (p != NULL) {
		Clear(p->left);
		Clear(p->right);
		free(p);
	}
}

BSTNode* AllocBSTNode() {
	BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
	node->left = node->right = NULL;
	node->data = NULL;
	return node;
}

void SetBSTNode(BSTNode* node, BSTNode* leftChild, BSTNode* rightChild, Data data) {
	node->data = data;
	node->left = leftChild;
	node->right = rightChild;
}

void Binary_Search_Tree_Main() {
	BinarySearchTree bst = NULL;
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
			Add(bst, input);
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