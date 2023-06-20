//#pragma once
#ifndef __SEQLIST__H__
#define __SEQLIST__H__

#include <stdio.h>
#include <string.h>

//增强数据可维护性
#define MAX_SIZE 10
typedef int SQDataType;

typedef struct SeqList
{
	SQDataType a[MAX_SIZE];
	int size;
}SL;

//typedef struct SeqList SL;


//增删查改等接口函数
//初始化
void SeqListInit(SL* ps);

//头插尾插，头删尾删
void SeqListPushBack(SL* ps, SQDataType x);
void SeqListPushFront(SL* ps, SQDataType x);
void SeqListPopback(SL* ps);
void SeqListPopFront(SL* ps);


#endif