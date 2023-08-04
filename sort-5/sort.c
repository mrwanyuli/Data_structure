#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Stack.h"

//打印
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序
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



void TestInsertSort()
{
	int a[] = { 5 ,2 ,4, 6, 1, 3 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end + gap] < tmp)
				{
					a[end + gap] = tmp;
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
	     }
	}
}

//交换
void Swap(int* p1,int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



//向下调整
void AdjustDwon(int* a, int n, int root)//只改变a里面的，所以其他可以不用传地址过来
//root是从第几个开始向下调整
{
	//先定义父级，和孩子，默认左孩子
	//选出左右孩子中大的一个，放到父级那


	int parent = root;
	int child = parent * 2 + 1;//左子树
	while (child < n)//不能超出数组的范围n
	{
		if (child + 1 < n && a[child] < a[child+1])//child + 1 < n考虑到可能没有右孩子
		{
			child++;//把左子变成右子，即大的
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);//传递至过去交换两个变量

			//交换完成，child放parent里面，就是现在算子级的了
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
		//只要遇到某个节点正好为大堆就会跳出来，只考虑当前节点，后面的不考虑
	}	
}



//排序排升序
void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i++)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, n, 0);
		end--;
	}



}

//直接选择排序，将最大的放尾部，最小的放在首位，从两头向中间夹
void SelectSort(int* a, int n)
{
	int end = n - 1;
	int begin = 0;

	while (begin < end)
	{
		int mini = begin, max = end;
		for (int i = begin; i <= end ; i++)
		{
			if (a[begin] < a[i])
			{
				mini = i;
			}
			if (a[end] > a[i])
			{
				max = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (max == begin)
		{
			max = mini;
		}
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}





//冒泡排序
//时间复杂度o(n*n)
//最好情况o(n)
//exchange作用是，如果一次过去都没换那就说明本来就是顺序的，就不用在排序了
void BubbleSort(int* a, int n)
{
	//int end = n;
	//while (end > 0)
	//{
	//	for (int i = 1; i < end; i++)
	//	{
	//		if (a[i-1] < a[i])
	//		{
	//			Swap(&a[i - 1], &a[i]);
	//		}
	//	}
	//	end--;
	//}
	for (int j = 0; j < n; j++)
	{
		int exchange = 0;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}


}


//三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;//十进制数向右移动，位运算都是算比特的，所以右移1个就是除2

	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}


//挖坑法
int PartSort1(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int begin = left;//定义头
	int end = right;//定义尾
	int pivot = begin;//定义坑
	int key = a[begin];//定义关键字，先找这个关键字的位置

	while (begin < end)
	{
		//左边begin为坑pivot，从右边找出小的值放到坑里，然后右边的end就又出来一个坑
		while (begin < end && a[end] >= key)//begin < end，用来防止内部直接就先begin > end了
		{
			end--;
		}
		a[begin] = a[end];
		pivot = end;

		//左边找大的移到坑里
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[end] = a[begin];
		pivot = begin;
	}
	//end和begin 相等，关键字填入坑中
	pivot = begin;
	a[pivot] = key;

	return pivot;
}


//挖坑法变形-左右变形
int PartSort2(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int begin = left;
	int end = right;
	int keyi = a[begin];

	while (begin < end)
	{
		while (begin < end && a[end] >= a[keyi])
		{
			end--;
		}

		while (begin < end && a[begin] <= a[keyi])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}

	//begin和end重合
	Swap(&a[begin], &a[keyi]);
	
	return begin;//返回关键字插入的位置
}


//前后指针法
int PartSort3(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int prev = left;
	int cur = left + 1;
	int keyi = left;

	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[prev], a[keyi]);

	return prev;
}


//快速排序
//挖坑法
//分治递归
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyIndex = PartSort3(a, left, right);

	if (keyIndex - 1 - left > 10)
	{
		QuickSort(a, left, keyIndex - 1);
	}
	else
	{
		InsertSort(a + left, keyIndex - 1 - left + 1);
	}

	if (keyIndex - 1 - left > 10)
	{
		QuickSort(a, keyIndex + 1, right);
	}
	else
	{
		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);//长度为right-（pivot+1）
	}
}


//快速排序，非递归
void QuickSortNonP(int* a, int n)
{
	//定义栈、初始化
	ST st;
	StackInit(&st);

	StackPush(&st, n - 1);
	StackPush(&st, 0);

	while(!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		int KeyIndex = PartSort1(a, left, right);//获取关键字
		//[left,KeyIndex-1] KeyIndex [KeyIndex+1,right]

		//入栈先入右栈，后左栈，栈的话先进后出

		if (right > KeyIndex + 1)
		{
			StackPush(&st, right);
			StackPush(&st, KeyIndex + 1);
		}


		if (left < KeyIndex - 1)
		{
			StackPush(&st, KeyIndex - 1);
			StackPush(&st, left);
		}

	}
	StackDestory(&st);
}

void TestQuickSortNonP()
{
	//int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	//int a[] = { 10, 6, 7, 1, 3, 9, 4};
	//int a[] = { 10, 6, 7 ,1, 3, 9, 4, 2, 8,10 };
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2, 8};
	QuickSortNonP(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

}



//归并排序
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//归并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] > a[begin2])
		{
			tmp[index++] = a[begin2++];
		}
		else
		{
			tmp[index++] = a[begin1++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}


	 while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	 for (int i = left; i <= right; i++)
	 {
		 a[i] = tmp[i];
	 }
}

void MergeSort(int* a, int n)
{

	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n-1, tmp);
	free(tmp);
}






//非递归，归并排序
void MergeSortNonP(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	
	int gap = 1;//每组数据个数
	while(gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + gap + gap - 1;


			//右半边不存在直接break,左半区间已经有序了
			if (begin2 >= n)
				break;
			//多了就修正
			if (end2 >= n)
			{
				end2 = n - 1;
			}



			int index = i;
			//[i,i + gap - 1],[i+gap,i+gap+gap - 1]
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] > a[begin2])
				{
					tmp[index++] = a[begin2++];
				}
				else
				{
					tmp[index++] = a[begin1++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}


			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}

			//将tmp的值传给数组a
			//每一次值是tmp的i -> end2
			for (int j = i; j <= end2; j++)
			{
				a[j] = tmp[j];
			}


		}

		
		gap *= 2;
	}

	free(tmp);//tmp不用了，销毁开辟的空间
}





void TestMergeSortNonP()
{
	//int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	//int a[] = { 10, 6, 7, 1, 3, 9, 4};
	//int a[] = { 10, 6, 7 ,1, 3, 9, 4, 2, 8,10 };
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2};
	MergeSortNonP(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

}



void TestMergeSort()
{
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}




void TestShellSort()
{
	int a[] = { 3, 5, 2, 7, 8, 6, 1, 9, 4, 0 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort()
{
	int a[] = { 3, 5, 2, 7, 8, 6, 1, 9, 4, 0 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	int a[] = { 3, 5, 2, 7, 8, 6, 1, 9, 4, 0 };
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);//传递左右子树的值
	PrintArray(a, sizeof(a) / sizeof(int));
}




// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 10000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];

	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	////QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	////MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	//printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}



int main()
{
	//TestOP();
	TestQuickSortNonP();
	return 0;
}
