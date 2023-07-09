#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void TestList1()
{
	//ListNode* plist = NULL;
	//plist = ListInit(plist);//这样，外部的实参plist不会被内部的形参取代，用二级指针传地址也行
	ListNode* plist = ListInit();//直接赋值给他返回值的方法代替，二级指针


	//添加
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListPushFront(plist, 0);

	ListPrint(plist);

	//删除
	ListPopBack(plist);
	ListPopFront(plist);

	ListPrint(plist);

	//查找
	ListNode* pos = ListFind(plist,3);
	if (pos)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没有找到");
	}
	ListInsert(pos, 5);

	ListErase(pos);



	ListPrint(plist);

	

	//全部销毁
	ListDestory(plist);

}


int main()
{

	TestList1();

	return 0;
}



