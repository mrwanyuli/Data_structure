//#pragma once
#ifndef __SEQLIST__H__
#define __SEQLIST__H__

#include <stdio.h>
#include <string.h>

//��ǿ���ݿ�ά����
#define MAX_SIZE 10
typedef int SQDataType;

typedef struct SeqList
{
	SQDataType a[MAX_SIZE];
	int size;
}SL;

//typedef struct SeqList SL;


//��ɾ��ĵȽӿں���
//��ʼ��
void SeqListInit(SL* ps);

//ͷ��β�壬ͷɾβɾ
void SeqListPushBack(SL* ps, SQDataType x);
void SeqListPushFront(SL* ps, SQDataType x);
void SeqListPopback(SL* ps);
void SeqListPopFront(SL* ps);


#endif