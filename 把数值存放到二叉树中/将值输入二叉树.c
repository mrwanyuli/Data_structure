#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
}TNode;

TNode* CreateTree(char* a, int* pi)
{
	if (a[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}

	TNode* root = (TNode*)malloc(sizeof(TNode));
	if (root == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}

	root->val = a[*pi];
	++(*pi);
	root->left = CreateTree(a, pi);
	root->right = CreateTree(a, pi);

	return root;
}

//´òÓ¡,ÖÐÐò
void InOrder(TNode* root)
{
	if(root == NULL)
		return;

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

int main()
{
	char str[100];
	scanf("%s", str);

	int i = 0;
	TNode* root = CreateTree(str, &i);

	InOrder(root);

	return 0;
}


