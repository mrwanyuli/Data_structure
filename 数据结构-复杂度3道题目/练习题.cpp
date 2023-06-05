#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//1����ȱʧ����
//nums���������0 - n������һ��������o��n��ʱ�������
//int missingNumber(int* nums, int numsize)
//{
//    int x = 0;
//    for (int i = 0; i < numsize; i++)
//    {
//        x ^= nums[i];
//    }
//
//    for (int j = 0; j < nusize + 1; j++)
//    {
//        x ^= j;
//    }
//    return x;
//}



//2������һ�����齫�������ƶ�k��λ�ã�����k�ǷǸ�������תk��
//void rotate(int*, int numsize, int k)
//{
//    while (k--)
//    {
//        int tmp = nums[numsize - 1];
//        for (int end = numsize - 2; end >= 0; --end)
//        {
//            nums[end + 1] = nums[end];
//        }
//        nums[0] = tmp;
//    }
//}

//3.����
void Reverse(int* nums, int left, int right)
{
    int tmp = 0;
    tmp = nums[left];
    nums[left] = nums[right];
    nums[right] = tmp;
    ++left;
    ++right;
}

int main(int* nums, int numsize, int k)
{
    if (k > numsize)
    {
        k = k % numsize;
    }

    Reverse(nums, numsize - k, numsize - 1);
    Reverse(nums, 0, nums - k - 1);
    Reverse(nums, 0, numsize - 1);
}
