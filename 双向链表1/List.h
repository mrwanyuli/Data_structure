#pragma once
#include <stdio.h>
#include <stdlib.h>

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
