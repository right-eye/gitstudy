#pragma once
#include"personManage.h"
#include"dishesManage.h"
#include"SqDishManage.h"
#include"LinkListPersonManage.h"
#include"SqQueueDishesManage.h"

class restaurant
{
protected:
	LinkListPersonManage<personManage> pm; //人员管理,使用链表
	SqDishManage<dishesManage> dishes; //菜品名称,使用线性表
	double tot_salary;

	bool FindPerson(string p_name, personManage& e, int& position);
	void FunctionList()const;

public:
	restaurant():tot_salary(0){}
	/*~restaurant();*/
	void MainMenu();
	//菜品管理
	void dishesInsert(string dish_name, double dish_price);
	void dishesDelete(string dish_name);
	void dishesSell(string dish_name);
	void dishesModify(string dish_name);
	double getTotSalary()const;
	void dishesPrint()const;

	//人员管理
	void personInsert(string p_name, string p_sex, string p_position, string p_number, double p_salary);
	void personDelete(string p_name);
	void personModify(string p_name);
	void personView()const;
};

