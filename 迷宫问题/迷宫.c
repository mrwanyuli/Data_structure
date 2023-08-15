#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


//��ӡ�õĺ���PrintMaze


//��̬���ٶ�ά����

//IsPass�ж��Ƿ������
//GetMazePath
//curΪ��ǰλ��


//�ͷſ��ٵĿռ�

//ջ������¼ͨ·
//ջ�����STDataType��
//ջ�Ǻ���ȳ��ģ��ٴ���һ��ջrpath���������ͺ���

//ͷ�ļ�

//PT��λ��



//���ٶ�ά����ռ�
//��ά��������
//��ͨ· ��entry������

////////////////////////////
//����ջ

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
// ��ջ
void StackPush(ST* ps, STDataType x);
// ��ջ
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

// ��ջ
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	// ����-������
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

// ��ջ
void StackPop(ST* ps)
{
	assert(ps);
	// ջ���ˣ�����Pop��ֱ����ֹ���򱨴�
	assert(ps->top > 0);

	//ps->a[ps->top - 1] = 0;
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	// ջ���ˣ�����Top��ֱ����ֹ���򱨴�
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

	// ����ߵ�����
	if (cur.row == N - 1 && cur.col == M - 1)
		return true;

	// ̽��curλ�õ����������ĸ�����
	PT next;
	maze[cur.row][cur.col] = 2;

	// ��
	next = cur;
	next.row -= 1;
	if (IsPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}

	// ��
	next = cur;
	next.row += 1;
	if (IsPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}


	// ��
	next = cur;
	next.col -= 1;
	if (IsPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}

	// ��
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
	//�����������
	int N = 0, M = 0;
	while (scanf("%d%d", &N, &M) != EOF)
	{
		//���ٶ�ά����N��M�У����ǵ�Ҫfree�����ٵĿռ�
		// ��̬���ٶ�ά����
		int** maze = (int**)malloc(sizeof(int*) * N);
		for (int i = 0; i < N; ++i)
		{
			maze[i] = (int*)malloc(sizeof(int) * M);
		}

		// ��ά���������
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				scanf("%d", &maze[i][j]);
			}
		}
	
		//��ӡ�����ֵ
		PrintMaze(maze, N, M);




		PT entry;
		entry.row = 0;
		entry.col = 0;
		//���Ϊ [0][0]
		
		//����ջ����ʼ�����������
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

		//�ͷſռ�:1���ͷ�maze����ָ��ָ��Ŀռ�
		//         2���ͷ�maze�Լ��Ŀռ�
		for (int i = 0; i < N; i++)
		{
			free(maze[i]);
		}
		free(maze);
		maze = NULL;
	}


	return 0;

}
