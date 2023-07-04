#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int SLTDataType;
struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
};
typedef struct SListNode SLTNode;

//不会改变链表的头指针，就传一级指针
void SListPrint(SLTNode* phead);

//可能会改变链表的头指针，传二级指针
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushFront(SLTNode** pphead, SLTDataType x);

void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** pphead);

//查找
//不修改，一级指针
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//在pos前面插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* pos);






