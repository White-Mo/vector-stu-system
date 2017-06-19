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
	cout << "��0�������˵�" << endl; cin >> n;
	system("cls");
	if (n == 0) {
		if (ts == 't') { menu(); }
		if (ts == 's') { menu2(); }
	}
}
void show(char ts)
{
	cout << "ѧ��" << "\t"
		<< "����" << "\t"
		<<"����"<< "\t"
		<<"�Ա�"<< "\t"
		<< "����" << "\t"
		<< "��ѧ" << "\t"
		<< "Ӣ��" << "\t"
		<< "�ܳɼ�" << "\t" << endl;
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
		printf("������ѧ��(1-100)�����������䣬�Ա���ѧ ���� Ӣ��ɼ�\n");
		
		cin >> input.number >> input.name >> input.age>>input.male>>input.nChin >> input.nMath >> input.nEngl;
		input.nsum = input.nMath + input.nChin + input.nEngl;
		stu.push_back(input);

		printf("�Ƿ����¼��ѧ����Ϣ?(Y or N)");
		rewind(stdin);
		scanf_s("%c", &c, sizeof(c));
		cout << endl;
	} while (c != 'N'&&c != 'n');
	returnmenu(ts);
	return;
}

void findByID(char ts)
{
	cout << "����Ҫ��ѯ��ѧ����ѧ�ţ�";
	int num;
	cin >> num;
	vector<User>::iterator iter;
	iter = find_if(stu.begin(), stu.end(), [num](struct User a) {return a.number == num; });
	if (iter != stu.end())
	{
		cout << "ѧ��" << "\t"
			<< "����" << "\t"
			<<"����" <<"\t"
			<< "����" << "\t"
			<< "��ѧ" << "\t"
			<< "Ӣ��" << "\t"
			<< "�ܳɼ�" << "\t" << endl;
		cout << iter->number << "\t"
			<< iter->name << "\t"
			<<iter->age<<"\t"
			<< iter->male << "\t"
			<< iter->nChin << "\t"
			<< iter->nMath << "\t"
			<< iter->nEngl << "\t"
			<< iter->nsum << endl;
	}
	else cout << "û�����ѧ������Ϣ" << endl;
	returnmenu( ts);
	return;
}
void findByName(char ts)
{
	cout << "����Ҫ��ѯ��ѧ�������֣�";
	string name;
	cin >> name;
	vector<User>::iterator iter;
	iter = find_if(stu.begin(), stu.end(), [name](struct User a) {return a.name == name; });
	if (iter != stu.end())
	{
		cout << "ѧ��" << "\t"
			<< "����" << "\t"
			<< "����" << "\t"
			<< "����" << "\t"
			<< "��ѧ" << "\t"
			<< "Ӣ��" << "\t"
			<< "�ܳɼ�" << "\t" << endl;
		cout << iter->number << "\t"
			<< iter->name << "\t"
			<< iter->age << "\t"
			<< iter->male << "\t"
			<< iter->nChin << "\t"
			<< iter->nMath << "\t"
			<< iter->nEngl << "\t"
			<< iter->nsum << endl;

	}
	else cout << "û�����ѧ������Ϣ" << endl;
	returnmenu(ts);
	return;
}
void find(char ts)
{
	cout << "��ѯ��ʽ��" << endl;
	cout << "��\t1    ͨ��ѧ�Ų�ѯ��" << endl;
	cout << "��\t2    ͨ��������ѯ��" << endl;
	cout << "��\t0    �������˵�" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:findByID(ts); break;
	case 2:findByName(ts); break;
	case 0:returnmenu(ts);
	default:cout << "������Ч�����������룺" << endl; break;
	}
}

void removeByID(char ts)
{
	cout << "����Ҫɾ����ѧ����ѧ�ţ�";
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
	cout << "����Ҫɾ����ѧ����������";
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
	cout << "��ѯ��ʽ��" << endl;
	cout << "��\t1    ͨ��ѧ�Ų�ѯɾ����" << endl;
	cout << "��\t2    ͨ��������ѯɾ����" << endl;
	cout << "��\t0    �������˵�" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:removeByID(ts); break;
	case 2:removeByName(ts); break;
	case 0:returnmenu(ts);
	default:cout << "������Ч" << endl << "��\t1�������룺" << endl << "���������ַ���ɾ���˵�" << endl;
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
	cout << "����Ҫ�����ѧ������Ϣ��" << endl;
	User input;
	printf("������ѧ��(1-100)��������,���䣬�Ա���ѧ ���� Ӣ��ɼ�\n");
	
	cout << endl;
	cin >> input.number >> input.name >>input.age>>input.male>> input.nChin >> input.nMath >> input.nEngl;

	input.nsum = input.nMath + input.nChin + input.nEngl;

	vector<User>::iterator iter;
	cout << "����Ҫ�����λ�ã�";
	int pos;
	cin >> pos;
	iter = stu.begin() + (pos - 1);

	stu.insert(iter, input);
	show(ts);
}
void modify(char ts)
{
	cout << "����Ҫ�޸ĵ�ѧ����ѧ�Ž��в��ң�" << endl;
	int num;
	cin >> num;

	User input;
	vector<User>::iterator iter;
	iter = find_if(stu.begin(), stu.end(), [num](struct User a) {return a.number == num; });
	if (iter != stu.end())
	{
		cout << "��ѧ������Ϣ���£�" << endl;

		cout << "ѧ��" << "\t"
			<< "����" << "\t"
			<< "����" << "\t"
			<< "����" << "\t"
			<< "��ѧ" << "\t"
			<< "Ӣ��" << "\t"
			<< "�ܳɼ�" << "\t" << endl;
		cout << iter->number << "\t"
			<< iter->name << "\t"
			<< iter->age << "\t"
			<< iter->male << "\t"
			<< iter->nChin << "\t"
			<< iter->nMath << "\t"
			<< iter->nEngl << "\t"
			<< iter->nsum << endl;

		cout << "��������������Ҫ�޸ĵ���Ϣ" << endl;

		int n;
		cout << "��1\t�޸�ѧ��������" << endl;
		cout << "��2\t�޸�ѧ��������" << endl; 
		cout << "��3\t�޸�ѧ��������" << endl;
		cout << "��4\t�޸�ѧ�������ĳɼ���" << endl;
		cout << "��5\t�޸�ѧ������ѧ�ɼ��� " << endl;
		cout << "��6\t�޸�ѧ����Ӣ��ɼ���" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "��ѧ���������ǣ�" << iter->name << endl;
			cout << "����Ҫ���µ����ݣ�";
			cin >> input.name;
			iter->name = input.name;
			cout << "������ϣ�" << endl;
			break;
		case 2:
			cout << "��ѧ���������ǣ�" << iter->age << endl;
			cout << "����Ҫ���µ����ݣ�";
			cin >> input.age;
			iter->age = input.age;
			cout << "������ϣ�" << endl;;
			break;
		case 3:
			cout << "��ѧ�����Ա��ǣ�" << iter->male << endl;
			cout << "����Ҫ���µ����ݣ�";
			cin >> input.male;
			iter->male = input.male;
			cout << "������ϣ�" << endl;;
			break;
		case 4:
			cout << "��ѧ�������ĳɼ��ǣ�" << iter->nChin << endl;
			cout << "����Ҫ���µ����ݣ�";
			cin >> input.nChin;
			iter->nChin = input.nChin;
			cout << "������ϣ�" << endl;;
			break;
		case 5:
			cout << "��ѧ������ѧ�ɼ��ǣ�" << iter->nMath << endl;
			cout << "����Ҫ���µ����ݣ�";
			cin >> input.nMath;
			iter->nMath = input.nMath;
			cout << "������ϣ�" << endl;
			break;
		case 6:
			cout << "��ѧ����Ӣ��ɼ��ǣ�" << iter->nEngl << endl;
			cout << "����Ҫ���µ����ݣ�";
			cin >> input.nEngl;
			iter->nEngl = input.nEngl;
			cout << "������ϣ�" << endl;
			break;
		default:cout << "������Ч" << endl << "��\t1�������룺" << endl << "���������ַ����޸Ĳ˵�" << endl;
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

	else cout << "û���ҵ����ѧ��";
	returnmenu(ts);
}
void total(char ts)
{
	cout << "��У��ѧ�������ǣ�";
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
	cout << "��ѡ������ķ�ʽ��" << endl;
	cout << "��1\t��ѧ��ѧ������(��С����)��" << endl;
	cout << "��2\t��ѧ�������ĳɼ�����" << endl;
	cout << "��3\t��ѧ������ѧ�ɼ����� " << endl;
	cout << "��4\t��ѧ����Ӣ��ɼ�����" << endl;
	cout << "��5\t��ѧ�����ܳɼ�����" << endl;
	cout << "��0\t �������˵�" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:sort(stu.begin(), stu.end(), CompByID); cout << "�������" << endl; returnmenu(ts); break;
	case 2:sort(stu.begin(), stu.end(), CompByChina); cout << "�������" << endl; returnmenu(ts); break;
	case 3:sort(stu.begin(), stu.end(), CompByMath); cout << "�������" << endl; returnmenu(ts); break;
	case 4:sort(stu.begin(), stu.end(), CompByEngl); cout << "�������" << endl; returnmenu(ts); break;
	case 5:sort(stu.begin(), stu.end(), CompBysum); cout << "�������" << endl; returnmenu(ts); break;
	case 0:returnmenu(ts);
	default:cout << "������Ч" << endl << "��\t1�������룺" << endl << "���������ַ�������˵�" << endl;
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
	cout << "��ӭ����ѧ����Ϣ����ϵͳ��"<<endl<<"�����˳�������quit"<<endl; cin>>quit;
	if (quit == "quit")
	{
		exit(0);
	}
	cout << "�������û�����"; cin >> strname;
	cout << "���������룺"; cin >> strpass;
	system("cls");
	for (int i = 0; i < 3; i++)
		{
			if (tec[i].Tname == strname&&tec[i].Tpass == strpass)
			{
				cout << "��֤��ȷ" << endl;;
				cout << "������ʦȨ��" << endl;
				menu();
				break;
			}
			if (tec[i].Tname == strname || tec[i].Tpass == strpass)
			{
				cout << "�û����������������������������" << endl;
				login();
				break;
			}
			if (tec[i].Tname != strname&&tec[i].Tpass != strpass)
			{
				cout << "����ѧ��Ȩ�ޣ�" << endl;
				menu2();
				break;
			}
		}	
	
}
void menu()
{
	char t = 't';
	cout << "1 ���" << endl;
	cout << "2 ���" << endl;
	cout << "3 ����" << endl;
	cout << "4 ɾ��" << endl;
	cout << "5 ͳ��" << endl;
	cout << "6 ����" << endl;
	cout << "7 �޸� " << endl;
	cout << "8 ����" << endl;
	cout << "9 ���ص�½����" << endl;
	cout << "0 �˳�" << endl;
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
	default:cout << "�˵��޴�ѡ�������ѡ��" << endl; break;
	}
}
void menu2()
{
	char s = 's';
	cout << "1 ���" << endl;
	cout << "2 ����" << endl;
	cout << "3 ͳ��" << endl;
	cout << "4 ����" << endl;
	cout << "5 ���ص�½����" << endl;
	cout << "0 �˳�" << endl;
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
	default:cout << "�˵��޴�ѡ�������ѡ��" << endl; break;
	}
}

int  main()
{
	login();
	return 0;
}


