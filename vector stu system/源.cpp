#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 100   
struct User
{
	int number;
	string name;
	int age;
	string male;
	float nMath;
	float nChin;
	float nEngl;
	float nsum;
	string Tname;
	string Tpass;
};
 vector<User> stu;
User tec[SIZE] = {};

void menu();
void menu2();
void returnmenu(char ts) {
	int n;
	cout << "按0返回主菜单" << endl; cin >> n;
	system("cls");
	if (n == 0) {
		if (ts == 't') { menu(); }
		if (ts == 's') { menu2(); }
	}
}
void show(char ts)
{
	cout << "学号" << "\t"
		<< "姓名" << "\t"
		<<"年龄"<< "\t"
		<<"性别"<< "\t"
		<< "语文" << "\t"
		<< "数学" << "\t"
		<< "英语" << "\t"
		<< "总成绩" << "\t" << endl;
	for (int i = 0; i < stu.size(); i++)
	{
		cout << stu[i].number << "\t"
			<< stu[i].name << "\t"
			<< stu[i].age << "\t"
			<< stu[i].male<<"\t"
			<< stu[i].nChin << "\t"
			<< stu[i].nMath << "\t"
			<< stu[i].nEngl << "\t"
			<< stu[i].nsum << "\t" << endl;
	}
	returnmenu(ts);
	return;
}
void input(char ts)
{
	User input;
	char c;
	do {
		printf("请输入学号(1-100)，姓名，年龄，性别，数学 语文 英语成绩\n");
		
		cin >> input.number >> input.name >> input.age>>input.male>>input.nChin >> input.nMath >> input.nEngl;
		input.nsum = input.nMath + input.nChin + input.nEngl;
		stu.push_back(input);

		printf("是否继续录入学生信息?(Y or N)");
		rewind(stdin);
		scanf_s("%c", &c, sizeof(c));
		cout << endl;
	} while (c != 'N'&&c != 'n');
	returnmenu(ts);
	return;
}

void findByID(char ts)
{
	cout << "输入要查询的学生的学号：";
	int num;
	cin >> num;
	vector<User>::iterator iter;
	iter = find_if(stu.begin(), stu.end(), [num](struct User a) {return a.number == num; });
	if (iter != stu.end())
	{
		cout << "学号" << "\t"
			<< "姓名" << "\t"
			<<"年龄" <<"\t"
			<< "语文" << "\t"
			<< "数学" << "\t"
			<< "英语" << "\t"
			<< "总成绩" << "\t" << endl;
		cout << iter->number << "\t"
			<< iter->name << "\t"
			<<iter->age<<"\t"
			<< iter->male << "\t"
			<< iter->nChin << "\t"
			<< iter->nMath << "\t"
			<< iter->nEngl << "\t"
			<< iter->nsum << endl;
	}
	else cout << "没有这个学生的信息" << endl;
	returnmenu( ts);
	return;
}
void findByName(char ts)
{
	cout << "输入要查询的学生的名字：";
	string name;
	cin >> name;
	vector<User>::iterator iter;
	iter = find_if(stu.begin(), stu.end(), [name](struct User a) {return a.name == name; });
	if (iter != stu.end())
	{
		cout << "学号" << "\t"
			<< "姓名" << "\t"
			<< "年龄" << "\t"
			<< "语文" << "\t"
			<< "数学" << "\t"
			<< "英语" << "\t"
			<< "总成绩" << "\t" << endl;
		cout << iter->number << "\t"
			<< iter->name << "\t"
			<< iter->age << "\t"
			<< iter->male << "\t"
			<< iter->nChin << "\t"
			<< iter->nMath << "\t"
			<< iter->nEngl << "\t"
			<< iter->nsum << endl;

	}
	else cout << "没有这个学生的信息" << endl;
	returnmenu(ts);
	return;
}
void find(char ts)
{
	cout << "查询方式：" << endl;
	cout << "按\t1    通过学号查询：" << endl;
	cout << "按\t2    通过姓名查询：" << endl;
	cout << "按\t0    返回主菜单" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:findByID(ts); break;
	case 2:findByName(ts); break;
	case 0:returnmenu(ts);
	default:cout << "输入无效，请重新输入：" << endl; break;
	}
}

void removeByID(char ts)
{
	cout << "输入要删除的学生的学号：";
	int num;
	cin >> num;
	vector<User>::iterator iter;
	iter = find_if(stu.begin(), stu.end(), [num](struct User a) {return a.number == num; });
	if (iter != stu.end())
	{
		stu.erase(iter);
	}
	returnmenu(ts);
}
void removeByName(char ts)
{
	cout << "输入要删除的学生的姓名：";
	string name;
	cin >> name;
	vector<User>::iterator iter;
	iter = find_if(stu.begin(), stu.end(), [name](struct User a) {return a.name == name; });
	if (iter != stu.end())
	{
		stu.erase(iter);
	}
	returnmenu(ts);
}
void remove(char ts)
{
	cout << "查询方式：" << endl;
	cout << "按\t1    通过学号查询删除：" << endl;
	cout << "按\t2    通过姓名查询删除：" << endl;
	cout << "按\t0    返回主菜单" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:removeByID(ts); break;
	case 2:removeByName(ts); break;
	case 0:returnmenu(ts);
	default:cout << "输入无效" << endl << "按\t1重新输入：" << endl << "按其他数字返回删除菜单" << endl;
		cin >> n;
		switch (n)
		{
		case 1:remove(ts); break;
		case 2:break;
		}
	}
}
void insert(char ts)
{
	cout << "输入要插入的学生的信息：" << endl;
	User input;
	printf("请输入学号(1-100)，姓名，,年龄，性别，数学 语文 英语成绩\n");
	
	cout << endl;
	cin >> input.number >> input.name >>input.age>>input.male>> input.nChin >> input.nMath >> input.nEngl;

	input.nsum = input.nMath + input.nChin + input.nEngl;

	vector<User>::iterator iter;
	cout << "输入要插入的位置：";
	int pos;
	cin >> pos;
	iter = stu.begin() + (pos - 1);

	stu.insert(iter, input);
	show(ts);
}
void modify(char ts)
{
	cout << "输入要修改的学生的学号进行查找：" << endl;
	int num;
	cin >> num;

	User input;
	vector<User>::iterator iter;
	iter = find_if(stu.begin(), stu.end(), [num](struct User a) {return a.number == num; });
	if (iter != stu.end())
	{
		cout << "该学生的信息如下：" << endl;

		cout << "学号" << "\t"
			<< "姓名" << "\t"
			<< "年龄" << "\t"
			<< "语文" << "\t"
			<< "数学" << "\t"
			<< "英语" << "\t"
			<< "总成绩" << "\t" << endl;
		cout << iter->number << "\t"
			<< iter->name << "\t"
			<< iter->age << "\t"
			<< iter->male << "\t"
			<< iter->nChin << "\t"
			<< iter->nMath << "\t"
			<< iter->nEngl << "\t"
			<< iter->nsum << endl;

		cout << "请重新输入你想要修改的信息" << endl;

		int n;
		cout << "按1\t修改学生姓名：" << endl;
		cout << "按2\t修改学生姓名：" << endl; 
		cout << "按3\t修改学生姓名：" << endl;
		cout << "按4\t修改学生的语文成绩：" << endl;
		cout << "按5\t修改学生的数学成绩： " << endl;
		cout << "按6\t修改学生的英语成绩：" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "该学生的姓名是：" << iter->name << endl;
			cout << "输入要更新的数据：";
			cin >> input.name;
			iter->name = input.name;
			cout << "更新完毕！" << endl;
			break;
		case 2:
			cout << "该学生的年龄是：" << iter->age << endl;
			cout << "输入要更新的数据：";
			cin >> input.age;
			iter->age = input.age;
			cout << "更新完毕！" << endl;;
			break;
		case 3:
			cout << "该学生的性别是：" << iter->male << endl;
			cout << "输入要更新的数据：";
			cin >> input.male;
			iter->male = input.male;
			cout << "更新完毕！" << endl;;
			break;
		case 4:
			cout << "该学生的语文成绩是：" << iter->nChin << endl;
			cout << "输入要更新的数据：";
			cin >> input.nChin;
			iter->nChin = input.nChin;
			cout << "更新完毕！" << endl;;
			break;
		case 5:
			cout << "该学生的数学成绩是：" << iter->nMath << endl;
			cout << "输入要更新的数据：";
			cin >> input.nMath;
			iter->nMath = input.nMath;
			cout << "更新完毕！" << endl;
			break;
		case 6:
			cout << "该学生的英语成绩是：" << iter->nEngl << endl;
			cout << "输入要更新的数据：";
			cin >> input.nEngl;
			iter->nEngl = input.nEngl;
			cout << "更新完毕！" << endl;
			break;
		default:cout << "输入无效" << endl << "按\t1重新输入：" << endl << "按其他数字返回修改菜单" << endl;
			cin >> n;
			switch (n)
			{
			case 1:modify(ts); break;
			case 2:break;
			}
		}
		iter->nsum = iter->nChin + iter->nMath + iter->nEngl;
		returnmenu(ts);
	}

	else cout << "没有找到这个学生";
	returnmenu(ts);
}
void total(char ts)
{
	cout << "该校的学生总数是：";
	cout << stu.size() << endl;
	returnmenu(ts);
}

bool CompByID(User &a, User &b)
{
	return a.number < b.number;
}
bool CompByChina(User &a, User &b)
{
	return a.nChin > b.nChin;
}
bool CompByMath(User &a, User &b)
{
	return a.nMath > b.nMath;
}
bool CompByEngl(User &a, User &b)
{
	return a.nEngl > b.nEngl;
}
bool CompBysum(User &a, User &b)
{
	return a.nsum > b.nsum;
}

void sort_chance(char ts)
{
	cout << "请选择排序的方式：" << endl;
	cout << "按1\t按学生学号排序(从小到大)：" << endl;
	cout << "按2\t按学生的语文成绩降序：" << endl;
	cout << "按3\t按学生的数学成绩降序： " << endl;
	cout << "按4\t按学生的英语成绩降序：" << endl;
	cout << "按5\t按学生的总成绩降序：" << endl;
	cout << "按0\t 返回主菜单" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:sort(stu.begin(), stu.end(), CompByID); cout << "排序完毕" << endl; returnmenu(ts); break;
	case 2:sort(stu.begin(), stu.end(), CompByChina); cout << "排序完毕" << endl; returnmenu(ts); break;
	case 3:sort(stu.begin(), stu.end(), CompByMath); cout << "排序完毕" << endl; returnmenu(ts); break;
	case 4:sort(stu.begin(), stu.end(), CompByEngl); cout << "排序完毕" << endl; returnmenu(ts); break;
	case 5:sort(stu.begin(), stu.end(), CompBysum); cout << "排序完毕" << endl; returnmenu(ts); break;
	case 0:returnmenu(ts);
	default:cout << "输入无效" << endl << "按\t1重新输入：" << endl << "按其他数字返回排序菜单" << endl;
		cin >> n;
		switch (n)
		{
		case 1:sort_chance(ts); break;
		case 2:break;
		}
	}
}

void login()
{
	tec[0].Tname = "11";
	tec[0].Tpass = "11";

	tec[1].Tname = "22";
	tec[1].Tpass = "22";

	tec[2].Tname = "33";
	tec[2].Tpass = "33";

	string strname;
	string strpass;
	string quit;
	cout << "欢迎进入学生信息管理系统！"<<endl<<"如需退出请输入quit"<<endl; cin>>quit;
	if (quit == "quit")
	{
		exit(0);
	}
	cout << "请输入用户名："; cin >> strname;
	cout << "请输入密码："; cin >> strpass;
	system("cls");
	for (int i = 0; i < 3; i++)
		{
			if (tec[i].Tname == strname&&tec[i].Tpass == strpass)
			{
				cout << "验证正确" << endl;;
				cout << "你获得老师权限" << endl;
				menu();
				break;
			}
			if (tec[i].Tname == strname || tec[i].Tpass == strpass)
			{
				cout << "用户名或者密码输入错误，请重新输入" << endl;
				login();
				break;
			}
			if (tec[i].Tname != strname&&tec[i].Tpass != strpass)
			{
				cout << "你获得学生权限：" << endl;
				menu2();
				break;
			}
		}	
	
}
void menu()
{
	char t = 't';
	cout << "1 浏览" << endl;
	cout << "2 添加" << endl;
	cout << "3 查找" << endl;
	cout << "4 删除" << endl;
	cout << "5 统计" << endl;
	cout << "6 排序" << endl;
	cout << "7 修改 " << endl;
	cout << "8 插入" << endl;
	cout << "9 返回登陆界面" << endl;
	cout << "0 退出" << endl;
	int n;
	cin >> n;
	system("cls");
	switch (n)
	{
	
	case 1:show(t); break;
	case 2:input(t); break;
	case 3:find(t); break;
	case 4:remove(t); break;
	case 5:total(t); break;
	case 6:sort_chance(t); break;
	case 7:modify(t); break;
	case 8:insert(t); break;
	case 9:login(); break;
	case 0: break;
	default:cout << "菜单无此选项，请重新选择！" << endl; break;
	}
}
void menu2()
{
	char s = 's';
	cout << "1 浏览" << endl;
	cout << "2 查找" << endl;
	cout << "3 统计" << endl;
	cout << "4 排序" << endl;
	cout << "5 返回登陆界面" << endl;
	cout << "0 退出" << endl;
	int n;
	cin >> n;
	system("cls");
	switch (n)
	{
	case 1:show(s); break;
	case 2:find(s); break;
	case 3:total(s); break;
	case 4:sort_chance(s); break;
	case 5:login(); break;
	case 0:break;
	default:cout << "菜单无此选项，请重新选择！" << endl; break;
	}
}

int  main()
{
	login();
	return 0;
}


