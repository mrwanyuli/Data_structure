#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void TestList1()
{

	//ListNode* plist = NULL;
	//plist = ListInit(plist);�������ⲿ��ʵ��plist���ᱻ�ڲ����β�ȡ�����ö���ָ�봫��ַҲ��
	ListNode* plist = ListInit(plist);//ֱ�Ӹ�ֵ��������ֵ�ķ������棬����ָ��


	ListDestory(plist);

}


int main()
{

	TestList1();

	return 0;
}



