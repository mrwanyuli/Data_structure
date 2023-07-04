#include "SList.h"

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);//传地址他的值，出了调用的函数才会被改变
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFront(&plist, 0);

	SListPopFront(&plist);

	SListPrint(plist);
	SListPopFront(&plist);

}

void TestSList2()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);//传地址他的值，出了调用的函数才会被改变
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFront(&plist, 0);


	//在3前面插入30
	SLTNode* pos = SListFind(plist, 3);
	SListInsert(&plist, pos, 30);

	SListPrint(plist);

	if (plist == NULL)
	{
		printf("NULL\n");
	}

}





int main()
{
	TestSList2();
	return 0;
}

