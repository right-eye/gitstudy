#include "personManage.h"
#include<iostream>
using namespace std;

personManage::personManage():name("δ֪"),sex("δ֪"),number("��")
{

}

personManage::personManage(string a_name, string a_sex, string a_position, string a_number, double a_salary):position(""),number("")
{
	this->name = a_name;
	this->sex = a_sex;
	this->position = a_position;
	this->number = a_number;
	this->salary = a_salary;

}
void personManage::setName(string a_name)
{
	bool judge = true;
	for (int i = 0; i < a_name.length(); i++) {
		if (a_name[i] == '!' || a_name[i] == '@' || a_name[i] == '#') {
			judge = false;
			break;
		}
	}
	if(!judge){
		cout << "�û����Ƿ������ɰ���'!','@','#'�ȷǷ��ַ�,����������:" << endl;
		getline(cin, a_name);
	}
	this->name = a_name;
}

string personManage::getName() const
{
	return name;
}

void personManage::setSex(string a_sex)
{
	sex = a_sex;
}

string personManage::getSex() const
{
	return sex;
}

void personManage::setPosition(string a_position)
{
	position = a_position;
}

string personManage::getPosition() const
{
	return position;
}

void personManage::setNumber(string a_number)
{
	bool judge = true;
	if (a_number.length() != 11) {
		cout << "�Ƿ�����,����������";
		getline(cin, a_number);
	}
	for (int i = 0; i < a_number.length(); i++) {
		if (a_number[i] >= '0' && a_number[i] <= '9');
		else {
			cout << "�Ƿ�����,����������";
			getline(cin, a_number);
		}
	}
	number = a_number;
}

string personManage::getNumber() const
{
	return number;
}

void personManage::setSalary(double a_salary)
{
	salary = a_salary;
}

double personManage::getSalary() const
{
	return salary;
}

void personManage::ViewInformation() const
{
	cout << "��Ա����ϢΪ:" << "\n����:" << getName()
		<< "\n�Ա�:" << getSex()
		<< "\nְλ:" << getPosition()
		<< "\n�绰����:" << getNumber() 
		<< "\n����:" << getSalary() << "\n" << endl;
}

