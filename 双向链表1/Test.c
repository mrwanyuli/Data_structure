#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void TestList1()
{

	//ListNode* plist = NULL;
	//plist = ListInit(plist);这样，外部的实参plist不会被内部的形参取代，用二级指针传地址也行
	ListNode* plist = ListInit(plist);//直接赋值给他返回值的方法代替，二级指针


	ListDestory(plist);

}


int main()
{

	TestList1();

	return 0;
}



