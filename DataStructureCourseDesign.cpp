// DataStructureCourseDesign.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "personManage.h"
#include"restaurant.h"
using namespace std;

int main()
{
	restaurant r;
	r.MainMenu();
	/* 人员插入的检测
	personManage p("张三", "男", "阿迪", "15704688885");
	p.setName("李四");
	//personManage p;
	p.ViewInformation();
	*/
	/*restaurant r;
	r.personInsert("张三", "男", "厨师", "1570688885", 1200);
	r.personInsert("李四", "男", "高管", "1570688886", 5000);
	r.personInsert("王五", "男", "厨师", "1570688854", 4000);
	r.personView();
	//r.personDelete("李四");
	r.personModify("李四");
	r.personView();*/
	
	// 插入菜品与删除菜品的检测
	/*restaurant r;
	r.dishesInsert("红烧肉", 25.5);
	r.dishesInsert("红烧肉", 25.5);
	r.dishesInsert("锅包肉", 45);
	//r.dishesDelete("红烧肉");
	r.dishesPrint();
	r.dishesModify("红烧肉");
	r.dishesPrint();
	/*r.dishesSell("锅包肉");
	r.dishesSell("锅包肉");
	r.dishesSell("锅包肉");
	cout << r.getSalary() << endl;;*/
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
