#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


//打印用的函数PrintMaze


//动态开辟二维数组

//IsPass判断是否可以走
//GetMazePath
//cur为当前位置


//释放开辟的空间

//栈用来记录通路
//栈里面的STDataType是
//栈是后进先出的，再创建一个栈rpath，倒过来就好了

//头文件

//PT是位置



//开辟二维数组空间
//二维数组输入
//找通路 ，entry是坐标

////////////////////////////
//创建栈

typedef struct Position
{
	int row;
	int col;
}PT;
//////////////////
//////////////////

typedef PT STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);
// 入栈
void StackPush(ST* ps, STDataType x);
// 出栈
void StackPop(ST* ps);
STDataType StackTop(ST* ps);

int StackSize(ST* ps);
bool StackEmpty(ST* ps);

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

// 入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	// 满了-》增容
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
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

// 出栈
void StackPop(ST* ps)
{
	assert(ps);
	// 栈空了，调用Pop，直接中止程序报错
	assert(ps->top > 0);

	//ps->a[ps->top - 1] = 0;
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	// 栈空了，调用Top，直接中止程序报错
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}


////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////

ST path;


bool IsPass(int** maze,int N, int M, PT pos)
{
	if (pos.row >= 0 && pos.row < N
		&& pos.col >= 0 && pos.col < M
		&& maze[pos.row][pos.col] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void PrintMaze(int** maze, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}


void PrintPath()
{
	ST rpath;
	StackInit(&rpath);

	while (!StackEmpty(&path))
	{
		StackPush(&rpath, StackTop(&path));
		StackPop(&path);
	}

	while (!StackEmpty(&rpath))
	{
		PT top = StackTop(&rpath);
		printf("(%d,%d)\n", top.row, top.col);
		StackPop(&rpath);
	}

	StackDestory(&rpath);
}



bool GetMazePath(int** maze, int N, int M, PT cur)
{
	StackPush(&path, cur);

	// 如果走到出口
	if (cur.row == N - 1 && cur.col == M - 1)
		return true;

	// 探测cur位置得上下左右四个方向
	PT next;
	maze[cur.row][cur.col] = 2;

	// 上
	next = cur;
	next.row -= 1;
	if (IsPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}

	// 下
	next = cur;
	next.row += 1;
	if (IsPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}


	// 左
	next = cur;
	next.col -= 1;
	if (IsPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}

	// 右
	next = cur;
	next.col += 1;
	if (IsPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}

	StackPop(&path);

	return false;
}


int main()
{
	//多个案例输入
	int N = 0, M = 0;
	while (scanf("%d%d", &N, &M) != EOF)
	{
		//开辟二维数组N行M列，最后记得要free掉开辟的空间
		// 动态开辟二维数组
		int** maze = (int**)malloc(sizeof(int*) * N);
		for (int i = 0; i < N; ++i)
		{
			maze[i] = (int*)malloc(sizeof(int) * M);
		}

		// 二维数组得输入
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				scanf("%d", &maze[i][j]);
			}
		}
	
		//打印输入的值
		PrintMaze(maze, N, M);




		PT entry;
		entry.row = 0;
		entry.col = 0;
		//入口为 [0][0]
		
		//创建栈，初始化，最后销毁
		StackInit(&path);


		if (GetMazePath(maze, N, M, entry))
		{
			PrintPath();
		}
		else
		{
			printf("failed\n");
		}


		StackDestory(&path);

		//释放空间:1，释放maze里面指针指向的空间
		//         2，释放maze自己的空间
		for (int i = 0; i < N; i++)
		{
			free(maze[i]);
		}
		free(maze);
		maze = NULL;
	}


	return 0;

}
