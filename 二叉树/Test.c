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

//����BTNode֮����ΪQueue.h�õ��ˣ��������ͷ������ôԤ�������ƹ�����ʱ��ᱨ��
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

//Ҷ�ӽڵ�ĸ���
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

//�������
//����˼·������һ�����ʱ�����һ���
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


//������������
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





