#pragma once
#include<string>
using namespace std;

class personManage
{
protected:
	string name; //����
	string sex; //�Ա�
	string position; //ְλ
	string number; //�绰��
	double salary; //н��

public:
	personManage();
	personManage(string name, string sex, string position, string number, double salary);
	//virtual ~personManage();
	void setName(string name);
	string getName() const;
	void setSex(string sex);
	string getSex() const;
	void setPosition(string post);
	string getPosition() const;
	void setNumber(string number);
	string getNumber() const;
	void setSalary(double salary);
	double getSalary() const;
	void ViewInformation() const;
};

