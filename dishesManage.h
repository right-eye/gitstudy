#pragma once
#include<string>
using namespace std;
class dishesManage
{
protected:
	string dishName; //菜品名
	double price; //菜品价格

public:
	dishesManage() :dishName(""), price(0) {};
	dishesManage(string a_dishName, double a_price);
	void setdishName(string a_name);  //设置菜品名称
	string getdishName() const; //获取菜品名称
	void setPrice(double a_price); //设置价格
	double getPrice() const; //获取价格
	void dishPrint() const;
};

