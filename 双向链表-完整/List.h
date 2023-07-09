#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

 typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType Data;

}ListNode;

 
 ListNode* ListInit();
 void ListDestory(ListNode* phead);
 void ListPushBack(ListNode* phead, LTDataType x);
 void ListPushFront(ListNode* phead, LTDataType x);
 void ListPopBack(ListNode* phead);
 void ListPopFront(ListNode* phead);

 void ListPrint(ListNode* phead);

 //����
 ListNode* ListFind(ListNode* phead, LTDataType x);
 //��posǰ����x
 void ListInsert(ListNode* pos, LTDataType x);
 //ɾ��posλ�õ�ֵ
 void ListErase(ListNode* pos);
 //ȫ������
 void ListDestory(ListNode* pos);
