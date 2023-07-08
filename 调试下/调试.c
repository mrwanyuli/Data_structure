#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

//Çó×Ö·û³¤¶È

int my_strlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str != '0')
	{
		str++;
		count++;
	}
	return count;


}






int main()
{
	char arr[] = "hellow bit";
	int len = my_strlen(arr);
	printf("%d", len);
	return 0;
}







