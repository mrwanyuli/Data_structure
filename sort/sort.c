#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void printfArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void TestInsertSort()
{
	int a[] = { 5 ,2 ,4, 6, 1, 3 };
	InsertSort(a, sizeof(a) / sizeof(int));
	printfArray(a, sizeof(a) / sizeof(int));
}


int main()
{
	TestInsertSort();
	return 0;
}
