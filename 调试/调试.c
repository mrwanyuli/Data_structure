#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int ret = 1;
//	int j = 0;
//	int sum = 0;
//
//	for (j = 1; j <= n; j++)
//	{
//
//		for (i = 1; i <= j; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//		ret = 1;
//	}
//
//	printf("%d", sum);
//	return 0;
//
//}


//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//}
#include <string.h>
#include <assert.h>


//返回char*是为了实现链式访问,把一个函数的返回值作为另一个函数的参数
//strcpy函数返回的是目标空间的起始地址
char* mystrcpy(char* dest, const char* src)
{
	char* ret = dest;
	//断言
	assert(src != NULL);
	assert(dest != NULL);

	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[20] = "xxxxxxxxxxxxxxxx";
	char arr2[] = "hellow bit";


	printf("%s\n", mystrcpy(arr1, arr2));//把一个函数的返回值作为另一个函数的参数
	return 0;
}

