#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);

	if (ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = 0;

}

void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;

}

//入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	//满了->增容
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));//relloc用法
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}

	ps->a[ps->top] = x;
	ps->top++;
}
//出栈
void StackPop(ST* ps)
{
	assert(ps);
	//栈空了，直接终止程序报错
	assert(ps->top > 0);

	ps->top--;

}


//返回栈顶元素
STDataType StackTop(ST* ps)
{
	assert(ps);
	//栈空了，不能调用会报错
	assert(ps->top > 0);

	return ps->a[ps->top - 1];//因为top指向栈顶后一个，所以减去1
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}


//这种一行的数据也是要写的，因为直接写在测试函数，在别人用的时候值可能对不上，但是写在封装好的函数里面，就不用管外面的
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}//布尔值返回ture 或者false


