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

//����ı������ͷָ�룬�ʹ�һ��ָ��
void SListPrint(SLTNode* phead);

//���ܻ�ı������ͷָ�룬������ָ��
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushFront(SLTNode** pphead, SLTDataType x);

void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** pphead);

//����
//���޸ģ�һ��ָ��
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//��posǰ�����
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//ɾ��posλ�õ�ֵ
void SListErase(SLTNode** pphead, SLTNode* pos);






