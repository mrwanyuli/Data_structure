#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"



void SeqListInit(SL* ps)
{
	memset(ps->a, 0, sizeof(SQDataType) * MAX_SIZE);//memset按字节初始化,初始化MAX_SIZE个，每个sizeof(SQDataType) 大小
	ps->size = 0;

}


void SeqListPushBack(SL* ps, SQDataType x)
{
	if (ps->size = MAX_SIZE)
	{
		printf("SeqList is full\n");
		return;
	}
	ps->a[ps->size] = x;
	ps->size++;
}


void SeqListPushFront(SL* ps, SQDataType x);
void SeqListPopback(SL* ps);
void SeqListPopFront(SL* ps);

