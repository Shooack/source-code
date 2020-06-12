#include<iostream>
#include<Windows.h>
using namespace std;
#define max 1000
//系统中需要实现的功能如下：
//* 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1color0人
//* 显示联系人：显示通讯录中所有联系人信息
//* 删除联系人：按照姓名进行删除指定联系人
//* 查找联系人：按照姓名查看指定联系人信息
//* 修改联系人：按照姓名重新修改指定联系人
//* 清空联系人：清空通讯录中所有信息
//* 退出通讯录：退出当前使用的通讯录

struct person
{
	string name;
	int age;
	int gender;//1.男  2.女
	string phone;
	string address;

};

struct addressbooks
{
	person personarray[max];
	int size;
};

//*********************显示菜单*********************
void showmenu()
{
	cout << "************************" << endl;
	cout << " 【通讯录管理系统】v1.0 " << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
	cout << "请选择您需要的功能：" << endl;

}

//********************添加联系人********************
void add_person(addressbooks* book)
{
	system("color 06");
	if (book->size == max)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		book->personarray[book->size].name = name;

		//年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		book->personarray[book->size].age = age;

		//性别
		int gender = 0;
		cout << "请输入性别：" << endl;
		cout << "1--男" << endl << "2--女" << endl;
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				book->personarray[book->size].gender = gender;
				break;
			}
			else
			{
				cout << "您输入的性别有误，请重新输入" << endl;
			}
		}

		//电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		book->personarray[book->size].phone = phone;

		//地址
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		book->personarray[book->size].address = address;

		book->size++;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}
}

//********************显示联系人********************
void show_person(addressbooks* book)
{
	system("color 02");
	if (book->size == 0)
	{
		cout << "当前联系人记录为空" << endl;
	}
	else
	{
		cout << "姓名\t\t" << "年龄\t\t" << "性别\t\t" << "电话\t\t" << "地址\t\t" << endl;
		cout << "========================================================================" << endl;
		for (int i = 0; i < book->size; i++)
		{
			cout << book->personarray[i].name << "\t\t";
			cout << book->personarray[i].age << "\t\t";
			cout << (book->personarray[i].gender == 1 ? "男" : "女") << "\t\t";
			cout << book->personarray[i].phone << "\t\t";
			cout << book->personarray[i].address << "\t\t" << endl;
		}
	}
	system("pause");
	system("cls");
}

//*************检测联系人是否存在通讯录中*************
int isexist(addressbooks* book, string name)
{
	for (int i = 0; i < book->size; i++)
	{
		if (book->personarray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

//********************删除联系人********************
void delete_person(addressbooks* book)
{
	system("color 0E");
	if (book->size == 0)
	{
		cout << "当前没有可删除的列表" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入需要删除联系人的姓名" << endl;
		string name;
		cin >> name;
		int result = isexist(book, name);
		if (result == -1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			cout << "找到了在第" << result + 1 << "位" << endl;
			for (int i = 0; i < book->size; i++)
			{
				book->personarray[result] = book->personarray[result + 1];
			}
			book->size--;
			cout << "删除成功！" << endl;
		}

		system("pause");
		system("cls");
	}
}

//********************查找联系人********************
void find_person(addressbooks* book)
{
	system("color 0D");
	if (book->size == 0)
	{
		cout << "当前没有可查找的列表" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入您要查找的联系人姓名" << endl;
		string name;
		cin >> name;
		int result = isexist(book, name);
		if (result == -1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			cout << "姓名\t\t" << "年龄\t\t" << "性别\t\t" << "电话\t\t" << "地址\t\t" << endl;
			cout << "========================================================================" << endl;
			cout << book->personarray[result].name << "\t\t";
			cout << book->personarray[result].age << "\t\t";
			cout << (book->personarray[result].gender == 1 ? "男" : "女") << "\t\t";
			cout << book->personarray[result].phone << "\t\t";
			cout << book->personarray[result].address << "\t\t" << endl;
		}
		system("pause");
		system("cls");
	}
}

//********************修改联系人********************
void modify_person(addressbooks* book)
{
	system("color 0C");
	if (book->size == 0)
	{
		cout << "当前没有可修改的列表" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入您要修改的联系人姓名" << endl;
		string name;
		cin >> name;
		int result = isexist(book, name);
		if (result == -1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			while (true)
			{
				cout << "请选择您要修改的项" << endl;
				cout << "1.修改姓名" << endl;
				cout << "2.修改年龄" << endl;
				cout << "3.修改性别" << endl;
				cout << "4.修改电话" << endl;
				cout << "5.修改地址" << endl;
				cout << "0.返回上一级" << endl;
				int select = 0;
				cin >> select;
				switch (select)
				{
				case 0:
				{
					system("cls");
					return;
					break;

				}
				case 1:
				{
					string name;
					cout << "您要把--" << book->personarray[result].name << "--修改为：" << endl;
					cin >> name;
					book->personarray[result].name = name;
					cout << "修改成功！" << endl;
					break;
				}
				case 2:
				{
					int age;
					cout << "您要把--" << book->personarray[result].age << "--修改为：" << endl;
					cin >> age;
					book->personarray[result].age = age;
					cout << "修改成功！" << endl;
					break;
				}
				case 3:
				{
					int gender;
					cout << "您要把--" << book->personarray[result].gender << "--修改为：" << endl;
					cout << "1--男" << endl << "2--女" << endl;
					while (true)
					{
						cin >> gender;
						if (gender == 1 || gender == 2)
						{
							book->personarray[result].gender = gender;
							break;
						}
						else
						{
							cout << "您输入的性别有误，请重新输入" << endl;
						}
					}
					cout << "修改成功！" << endl;
					break;
				}
				case 4:
				{
					string phone;
					cout << "您要把--" << book->personarray[result].phone << "--修改为：" << endl;
					cin >> phone;
					book->personarray[result].phone = phone;
					cout << "修改成功！" << endl;
					break;
				}
				case 5:
				{
					string address;
					cout << "您要把--" << book->personarray[result].address << "--修改为：" << endl;
					cin >> address;
					book->personarray[result].address = address;
					cout << "修改成功！" << endl;
					break;
				}
				default:
					cout << "您输入的代号有误，请重新输入" << endl;
					cout << endl;
				}
			}
		}
		system("pause");
		system("cls");
	}
}

//********************清空联系人********************
void clean_person(addressbooks* book)
{
	system("color 0F");
	if (book->size == 0)
	{
		cout << "当前列表为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		book->size = 0;
		cout << "通讯录列表已清空" << endl;
	}
	system("pause");
	system("cls");
}

//**********************主函数**********************
int main()
{
	addressbooks book;
	book.size = 0;
	while (true)
	{
		showmenu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			add_person(&book);
			break;
		case 2://显示联系人
			show_person(&book);
			break;
		case 3://删除联系人
			delete_person(&book);
			break;
		case 4://查找联系人
			find_person(&book);
			break;
		case 5://修改联系人
			modify_person(&book);
			break;
		case 6://清空联系人
			clean_person(&book);
			break;
		case 0://退出通讯录
			cout << "程序退出中，欢迎下次使用" << endl;
			Sleep(1000);
			return 0;
			break;
		default:cout << "您输入的代号有误，请重新输入！" << endl;
		}
	}
	system("pause");
	return 0;
}