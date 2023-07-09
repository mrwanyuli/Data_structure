#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->Data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}


ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}


void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->Data);
		cur = cur->next;
	}
	printf("\n");
}


void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

}


void ListPushFront(ListNode* phead, LTDataType x) 
{
	assert(phead);

	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);

	newnode->next = first;
	newnode->prev = phead;
	first->prev = newnode;
	phead->next = newnode;


	//如果不用fiirst
	//ListNode* newnode = BuyListNode(x);
	//newnode->prev = phead;
	//newnode->next = phead->next
	//phead->next->prev = newnode
	//phead->next = newnode;


	//ListInsert(phead->next,x);
}


void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* first = phead->next;
	ListNode* second = first->next;

	phead->next = second;
	second->prev = phead;

	free(first);
	first = NULL;

}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;

	prev->next = phead;
	phead->prev = prev;

	free(tail);
	tail = NULL;

}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->Data = x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 在pos前插入x
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);

	//不加prev
	//pos->prev->next = newnode;
	//newnode->prev = pos->prev;
	//newnode->next = pos;
	//pos->prev = newnode;

	ListNode* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;


}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;

	free(pos);

}

//全部销毁
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;

	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;

}










