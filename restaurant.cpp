#include "restaurant.h"

void restaurant::FunctionList()const
{
	cout << "下面为本系统提供的操作，请合理使用" << endl;
	cout << "1.菜品添加"<< "\n2.菜品删除"
		 << "\n3.菜品信息修改"<< "\n4.餐厅菜单"
		 << "\n5.人员招聘"<< "\n6.人员解雇"
		 << "\n7.人员信息修改"<< "\n8.员工表"
		 << "\n9.点餐系统" << "\n10.账目汇总"
		 << "\n11.程序退出" << endl;
}

void restaurant::MainMenu()
{
	cout << "欢迎使用本餐厅管理系统，有何招待不周的地方，欢迎指出" << endl;
	bool flag = true;
	while (flag) {
		FunctionList();
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			string dish_name;
			cout << "请输入菜品的名称:"; getchar();
			getline(cin, dish_name);
			double dish_price;
			cout << "请输入菜品的价格:"; cin >> dish_price;
			dishesInsert(dish_name, dish_price);
		}break;
		case 2: {
			string dish_name;
			cout << "请输入您不满意的菜品名称"; getchar();
			getline(cin, dish_name);
			dishesDelete(dish_name);
		}break;
		case 3: {
			string dish_name;
			cout << "请输入您需要调整的菜品名称"; getchar();
			getline(cin, dish_name);
			dishesModify(dish_name);
		}break;
		case 4: {
			cout << "这是本店的菜单，请阅览!" << endl;
			dishesPrint();
		}break;
		case 5: {
			cout << "请依次输入员工的信息(姓名，性别，职位，电话号，工资)" << endl;
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
			cout << "说出您不满的员工名称，我们将进行最公正的审判!" << endl;
			string p_name;
			getchar();
			getline(cin, p_name);
			personDelete(p_name);
		}break;
		case 7: {
			cout << "不知哪位职员信息出现浮动了呢，说出他的名字吧:";
			string p_name;
			getchar();
			getline(cin, p_name);
			personDelete(p_name);
		}break;
		case 8: {
			cout << "我们的大家庭！" << endl;
			personView();
		}break;
		case 9: {
			string dish_name;
			cout << "请选择您要选择的菜品名称:"; getchar();
			getline(cin, dish_name);
			dishesSell(dish_name);
		}break;
		case 10: {
			cout << "经过一天的奋斗，我们的劳动成果为:" << getTotSalary() << endl;
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
		cout << "该菜品当前为火爆菜品，味道极佳，不需要修改了哦!" << endl;
		return;
	}
	else {
		dishesManage dish(dish_name, dish_price);
		dishes.Insert(1, dish); //将所用新的菜品加入第一个位置
		cout << "庆祝我们的餐馆又新增加菜品一列，必将收获广大的食客!" << endl;
	}
}

void restaurant::dishesDelete(string dish_name)
{
	int position = -1;
	if (dishes.Traverse(dish_name, position)) {
		dishesManage e;  //临时变量，获取需要删除的菜品
		dishes.Delete(position + 1, e);
		cout << "该菜品似乎不受喜爱呢,希望下次的相遇会更加美味!" << endl;
		cout << "请参考该菜品数据，进行合理修改" << endl;
		e.dishPrint();
	}
}

void restaurant::dishesSell(string dish_name)
{



	//原销售操作的完成，现想要添加队列这种数据结构，完成点菜清单的制作，然后清空来达成点餐成功.
	/*int position = -1;
	if (dishes.Traverse(dish_name, position)) {
		dishesManage e;
		dishes.GetElem(position + 1, e);
		cout << "所选择的菜品信息如下:" << endl;
		e.dishPrint();
		cout << "请问您要点这道佳肴嘛?" << endl;
		cout << "1.没错，就决定是你啦！			2.我再考虑以下" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			cout << "客人，您的菜来咯!下次再来哦" << endl;
			tot_salary += e.getPrice();
		}
		else {
			cout << "那咱们再去看看别的菜吧!" << endl;
		}
	}
	else {
		cout << "抱歉，没有您想寻找的美食，我们会马上调整！" << endl;
	}*/
}

void  restaurant::dishesModify(string dish_name)
{
	int position = -1;
	if (dishes.Traverse(dish_name, position)) {
		dishesManage e;
		dishes.GetElem(position + 1, e);
		e.dishPrint();
		cout << "店长，您要进行什么基操呢？" << endl;
		cout << "1.菜名好low		2.价钱emmm，不合适吧" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			string new_dishname;
			cout << "来个大气的名字吧：" << endl;
			getchar();
			getline(cin, new_dishname);
			e.setdishName(new_dishname);
			dishes.SetElem(position + 1, e);
		}
		else {
			double new_price;
			cout << "请说出您的决策：";
			cin >> new_price;
			e.setPrice(new_price);
		}
		cout << "信息修改成功，不知店长是否满意!" << endl;
		e.dishPrint();
	}
	else {
		cout << "店长，您是生病了吗，咱们莫有这道菜呀！" << endl;
	}
}

void restaurant::dishesPrint()const
{
	cout << "菜单如下:" << endl;
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
	cout << "入职成功!" << endl;
}

void restaurant::personDelete(string p_name)
{
	personManage e;
	bool flag = false;
	int position = -1;
	flag = FindPerson(p_name, e, position);
	if (flag) {
		cout << "查询员工信息如下:" << endl;
		e.ViewInformation();
		cout << "是否要给他一份鱿鱼?" << endl;
		cout << "1.毫无感情，给了			2.算了吧" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			pm.Delete(position, e);
			cout << "已斩断你我间的羁绊" << endl;
		}
	}
	else {
		cout << "请核对信息正确性，查无此人" << endl;
	}

}

void restaurant::personModify(string p_name)
{
	personManage e;
	bool flag = false;
	int position = -1;
	flag = FindPerson(p_name, e, position);
	cout << "所要查找的员工信息如下:" << endl;
	e.ViewInformation();
	cout << "请选择您要修改的信息：" << endl;
	cout << "1.职位       2.电话号       3.薪水" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		cout << "请分配一个新的职位:";
		string p_position;
		getchar();
		getline(cin, p_position);
		e.setPosition(p_position);
	}
	else if (choice == 2) {
		string p_number;
		cout << "新的电话号是:";
		getchar();
		getline(cin, p_number);
		e.setNumber(p_number);
	}
	else if (choice == 3) {
		double p_salary;
		cout << "更改薪资为:";
		cin >> p_salary;
		e.setSalary(p_salary);
	}
	pm.SetElem(position, e);
	cout << "信息修改成功" << endl;
}

void restaurant::personView()const
{
	pm.Traverse();
}