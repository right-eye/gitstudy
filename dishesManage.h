#pragma once
#include<string>
using namespace std;
class dishesManage
{
protected:
	string dishName; //��Ʒ��
	double price; //��Ʒ�۸�

public:
	dishesManage() :dishName(""), price(0) {};
	dishesManage(string a_dishName, double a_price);
	void setdishName(string a_name);  //���ò�Ʒ����
	string getdishName() const; //��ȡ��Ʒ����
	void setPrice(double a_price); //���ü۸�
	double getPrice() const; //��ȡ�۸�
	void dishPrint() const;
};

