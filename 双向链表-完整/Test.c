#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void TestList1()
{
	//ListNode* plist = NULL;
	//plist = ListInit(plist);//�������ⲿ��ʵ��plist���ᱻ�ڲ����β�ȡ�����ö���ָ�봫��ַҲ��
	ListNode* plist = ListInit();//ֱ�Ӹ�ֵ��������ֵ�ķ������棬����ָ��


	//���
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListPushFront(plist, 0);

	ListPrint(plist);

	//ɾ��
	ListPopBack(plist);
	ListPopFront(plist);

	ListPrint(plist);

	//����
	ListNode* pos = ListFind(plist,3);
	if (pos)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("û���ҵ�");
	}
	ListInsert(pos, 5);

	ListErase(pos);



	ListPrint(plist);

	

	//ȫ������
	ListDestory(plist);

}


int main()
{

	TestList1();

	return 0;
}



