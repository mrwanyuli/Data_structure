#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"



void SeqListInit(SL* ps)
{
	memset(ps->a, 0, sizeof(SQDataType) * MAX_SIZE);//memset���ֽڳ�ʼ��,��ʼ��MAX_SIZE����ÿ��sizeof(SQDataType) ��С
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

