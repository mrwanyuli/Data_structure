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


//����char*��Ϊ��ʵ����ʽ����,��һ�������ķ���ֵ��Ϊ��һ�������Ĳ���
//strcpy�������ص���Ŀ��ռ����ʼ��ַ
char* mystrcpy(char* dest, const char* src)
{
	char* ret = dest;
	//����
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


	printf("%s\n", mystrcpy(arr1, arr2));//��һ�������ķ���ֵ��Ϊ��һ�������Ĳ���
	return 0;
}

