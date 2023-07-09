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

 //查找
 ListNode* ListFind(ListNode* phead, LTDataType x);
 //在pos前插入x
 void ListInsert(ListNode* pos, LTDataType x);
 //删除pos位置的值
 void ListErase(ListNode* pos);
 //全部销毁
 void ListDestory(ListNode* pos);
