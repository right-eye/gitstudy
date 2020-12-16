#include "restaurant.h"

void restaurant::FunctionList()const
{
	cout << "����Ϊ��ϵͳ�ṩ�Ĳ����������ʹ��" << endl;
	cout << "1.��Ʒ���"<< "\n2.��Ʒɾ��"
		 << "\n3.��Ʒ��Ϣ�޸�"<< "\n4.�����˵�"
		 << "\n5.��Ա��Ƹ"<< "\n6.��Ա���"
		 << "\n7.��Ա��Ϣ�޸�"<< "\n8.Ա����"
		 << "\n9.���ϵͳ" << "\n10.��Ŀ����"
		 << "\n11.�����˳�" << endl;
}

void restaurant::MainMenu()
{
	cout << "��ӭʹ�ñ���������ϵͳ���к��д����ܵĵط�����ӭָ��" << endl;
	bool flag = true;
	while (flag) {
		FunctionList();
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			string dish_name;
			cout << "�������Ʒ������:"; getchar();
			getline(cin, dish_name);
			double dish_price;
			cout << "�������Ʒ�ļ۸�:"; cin >> dish_price;
			dishesInsert(dish_name, dish_price);
		}break;
		case 2: {
			string dish_name;
			cout << "��������������Ĳ�Ʒ����"; getchar();
			getline(cin, dish_name);
			dishesDelete(dish_name);
		}break;
		case 3: {
			string dish_name;
			cout << "����������Ҫ�����Ĳ�Ʒ����"; getchar();
			getline(cin, dish_name);
			dishesModify(dish_name);
		}break;
		case 4: {
			cout << "���Ǳ���Ĳ˵���������!" << endl;
			dishesPrint();
		}break;
		case 5: {
			cout << "����������Ա������Ϣ(�������Ա�ְλ���绰�ţ�����)" << endl;
			getchar();
			string p_name, p_sex, p_position, p_number;
			double p_salary;
			getline(cin, p_name);
			getline(cin, p_sex);
			getline(cin, p_position);
			getline(cin, p_number);
			cin >> p_salary;
			personInsert(p_name, p_sex, p_position, p_number, p_salary);
		}break;
		case 6: {
			cout << "˵����������Ա�����ƣ����ǽ��������������!" << endl;
			string p_name;
			getchar();
			getline(cin, p_name);
			personDelete(p_name);
		}break;
		case 7: {
			cout << "��֪��λְԱ��Ϣ���ָ������أ�˵���������ְ�:";
			string p_name;
			getchar();
			getline(cin, p_name);
			personDelete(p_name);
		}break;
		case 8: {
			cout << "���ǵĴ��ͥ��" << endl;
			personView();
		}break;
		case 9: {
			string dish_name;
			cout << "��ѡ����Ҫѡ��Ĳ�Ʒ����:"; getchar();
			getline(cin, dish_name);
			dishesSell(dish_name);
		}break;
		case 10: {
			cout << "����һ��ķܶ������ǵ��Ͷ��ɹ�Ϊ:" << getTotSalary() << endl;
		}break;
		default: flag = false;
			break;
		}
	}
}

void restaurant::dishesInsert(string dish_name, double dish_price)
{
	int position = -1;
	if (dishes.Traverse(dish_name, position)) {
		cout << "�ò�Ʒ��ǰΪ�𱬲�Ʒ��ζ�����ѣ�����Ҫ�޸���Ŷ!" << endl;
		return;
	}
	else {
		dishesManage dish(dish_name, dish_price);
		dishes.Insert(1, dish); //�������µĲ�Ʒ�����һ��λ��
		cout << "��ף���ǵĲ͹��������Ӳ�Ʒһ�У��ؽ��ջ����ʳ��!" << endl;
	}
}

void restaurant::dishesDelete(string dish_name)
{
	int position = -1;
	if (dishes.Traverse(dish_name, position)) {
		dishesManage e;  //��ʱ��������ȡ��Ҫɾ���Ĳ�Ʒ
		dishes.Delete(position + 1, e);
		cout << "�ò�Ʒ�ƺ�����ϲ����,ϣ���´ε������������ζ!" << endl;
		cout << "��ο��ò�Ʒ���ݣ����к����޸�" << endl;
		e.dishPrint();
	}
}

void restaurant::dishesSell(string dish_name)
{



	//ԭ���۲�������ɣ�����Ҫ��Ӷ����������ݽṹ����ɵ���嵥��������Ȼ���������ɵ�ͳɹ�.
	/*int position = -1;
	if (dishes.Traverse(dish_name, position)) {
		dishesManage e;
		dishes.GetElem(position + 1, e);
		cout << "��ѡ��Ĳ�Ʒ��Ϣ����:" << endl;
		e.dishPrint();
		cout << "������Ҫ�����������?" << endl;
		cout << "1.û���;�����������			2.���ٿ�������" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			cout << "���ˣ����Ĳ�����!�´�����Ŷ" << endl;
			tot_salary += e.getPrice();
		}
		else {
			cout << "��������ȥ������Ĳ˰�!" << endl;
		}
	}
	else {
		cout << "��Ǹ��û������Ѱ�ҵ���ʳ�����ǻ����ϵ�����" << endl;
	}*/
}

void  restaurant::dishesModify(string dish_name)
{
	int position = -1;
	if (dishes.Traverse(dish_name, position)) {
		dishesManage e;
		dishes.GetElem(position + 1, e);
		e.dishPrint();
		cout << "�곤����Ҫ����ʲô�����أ�" << endl;
		cout << "1.������low		2.��Ǯemmm�������ʰ�" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			string new_dishname;
			cout << "�������������ְɣ�" << endl;
			getchar();
			getline(cin, new_dishname);
			e.setdishName(new_dishname);
			dishes.SetElem(position + 1, e);
		}
		else {
			double new_price;
			cout << "��˵�����ľ��ߣ�";
			cin >> new_price;
			e.setPrice(new_price);
		}
		cout << "��Ϣ�޸ĳɹ�����֪�곤�Ƿ�����!" << endl;
		e.dishPrint();
	}
	else {
		cout << "�곤������������������Ī�������ѽ��" << endl;
	}
}

void restaurant::dishesPrint()const
{
	cout << "�˵�����:" << endl;
	for (int i = 0; i < dishes.Length(); i++) {
		dishesManage e;
		dishes.GetElem(i + 1, e);
		e.dishPrint();
	}
}

double restaurant::getTotSalary()const
{
	return tot_salary;
}

bool restaurant::FindPerson(string p_name, personManage& e, int& position)
{
	for (position = 1; position <= pm.Length(); position++) {
		pm.GetElem(position, e);
		if (e.getName() == p_name) {
			return true;
		}
	}
	return false;
}

void restaurant::personInsert(string p_name, string p_sex, string p_position, string p_number, double p_salary)
{
	personManage e(p_name, p_sex, p_position, p_number, p_salary);
	pm.Insert(1, e);
	cout << "��ְ�ɹ�!" << endl;
}

void restaurant::personDelete(string p_name)
{
	personManage e;
	bool flag = false;
	int position = -1;
	flag = FindPerson(p_name, e, position);
	if (flag) {
		cout << "��ѯԱ����Ϣ����:" << endl;
		e.ViewInformation();
		cout << "�Ƿ�Ҫ����һ������?" << endl;
		cout << "1.���޸��飬����			2.���˰�" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			pm.Delete(position, e);
			cout << "��ն�����Ҽ���" << endl;
		}
	}
	else {
		cout << "��˶���Ϣ��ȷ�ԣ����޴���" << endl;
	}

}

void restaurant::personModify(string p_name)
{
	personManage e;
	bool flag = false;
	int position = -1;
	flag = FindPerson(p_name, e, position);
	cout << "��Ҫ���ҵ�Ա����Ϣ����:" << endl;
	e.ViewInformation();
	cout << "��ѡ����Ҫ�޸ĵ���Ϣ��" << endl;
	cout << "1.ְλ       2.�绰��       3.нˮ" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		cout << "�����һ���µ�ְλ:";
		string p_position;
		getchar();
		getline(cin, p_position);
		e.setPosition(p_position);
	}
	else if (choice == 2) {
		string p_number;
		cout << "�µĵ绰����:";
		getchar();
		getline(cin, p_number);
		e.setNumber(p_number);
	}
	else if (choice == 3) {
		double p_salary;
		cout << "����н��Ϊ:";
		cin >> p_salary;
		e.setSalary(p_salary);
	}
	pm.SetElem(position, e);
	cout << "��Ϣ�޸ĳɹ�" << endl;
}

void restaurant::personView()const
{
	pm.Traverse();
}