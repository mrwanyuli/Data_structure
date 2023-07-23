#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>



typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BTDataType* left;
	struct BTDataType* right;
	BTDataType data;
}BTNode;

//放在BTNode之后，因为Queue.h用到了，如果放在头部，那么预处理，复制过来的时候会报错
#include "Queue.h"


void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL  ");
		return;
	}


	printf("%c  ", root->data);


	PrevOrder(root->left);
	PrevOrder(root->right);
}


int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//叶子节点的个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//层序遍历
//核心思路就是上一层出的时候带下一层进
void LevelOrder(BTNode* root)
{
	assert(root);
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c", front->data);

		if (front->left)
		{
			QueuePush(&q,front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}

	printf("\n");
	QueueDestory(&q);

}


//二叉树的销毁
void DestoryTree(BTNode* root)
{
	if (root == NULL)
		return;

	DestoryTree(root->left);
	DestoryTree(root->right);
	
	free(root);

}

int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	//PrevOrder(A);
	//printf("\n");


	//printf("%d \n", TreeSize(A));

	//printf("%d \n", TreeSize(B));

	//printf("%d \n", TreeLeafSize(A));
	//printf("%d \n", TreeLeafSize(B));
	LevelOrder(A);
}





