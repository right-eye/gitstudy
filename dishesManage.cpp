#include "dishesManage.h"
#include<iostream>
using namespace std;

dishesManage::dishesManage(string a_dishName, double a_price)
{
	dishName = a_dishName;
	price = a_price;
}

void dishesManage::setdishName(string a_dishName)
{
	dishName = a_dishName;
}

string dishesManage::getdishName() const
{
	return dishName;
}

void dishesManage::setPrice(double a_price)
{
	if (a_price < 0) {
		cout << "想赔钱？？重新输入!" << endl;
		cin >> a_price;
	}
	price = a_price;
}

double dishesManage::getPrice() const
{
	return price;
}

void dishesManage::dishPrint() const
{
	cout << "菜品名称:" << getdishName() 
		 << "	价格:"<< getPrice() << endl;
}