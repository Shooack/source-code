#include<iostream>
#include<Windows.h>
using namespace std;
#define max 1000
//ϵͳ����Ҫʵ�ֵĹ������£�
//* �����ϵ�ˣ���ͨѶ¼��������ˣ���Ϣ�������������Ա����䡢��ϵ�绰����ͥסַ������¼1color0��
//* ��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ
//* ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
//* ������ϵ�ˣ����������鿴ָ����ϵ����Ϣ
//* �޸���ϵ�ˣ��������������޸�ָ����ϵ��
//* �����ϵ�ˣ����ͨѶ¼��������Ϣ
//* �˳�ͨѶ¼���˳���ǰʹ�õ�ͨѶ¼

struct person
{
	string name;
	int age;
	int gender;//1.��  2.Ů
	string phone;
	string address;

};

struct addressbooks
{
	person personarray[max];
	int size;
};

//*********************��ʾ�˵�*********************
void showmenu()
{
	cout << "************************" << endl;
	cout << " ��ͨѶ¼����ϵͳ��v1.0 " << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
	cout << "��ѡ������Ҫ�Ĺ��ܣ�" << endl;

}

//********************�����ϵ��********************
void add_person(addressbooks* book)
{
	system("color 06");
	if (book->size == max)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		book->personarray[book->size].name = name;

		//����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		book->personarray[book->size].age = age;

		//�Ա�
		int gender = 0;
		cout << "�������Ա�" << endl;
		cout << "1--��" << endl << "2--Ů" << endl;
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
				cout << "��������Ա���������������" << endl;
			}
		}

		//�绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		book->personarray[book->size].phone = phone;

		//��ַ
		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		book->personarray[book->size].address = address;

		book->size++;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}
}

//********************��ʾ��ϵ��********************
void show_person(addressbooks* book)
{
	system("color 02");
	if (book->size == 0)
	{
		cout << "��ǰ��ϵ�˼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "����\t\t" << "����\t\t" << "�Ա�\t\t" << "�绰\t\t" << "��ַ\t\t" << endl;
		cout << "========================================================================" << endl;
		for (int i = 0; i < book->size; i++)
		{
			cout << book->personarray[i].name << "\t\t";
			cout << book->personarray[i].age << "\t\t";
			cout << (book->personarray[i].gender == 1 ? "��" : "Ů") << "\t\t";
			cout << book->personarray[i].phone << "\t\t";
			cout << book->personarray[i].address << "\t\t" << endl;
		}
	}
	system("pause");
	system("cls");
}

//*************�����ϵ���Ƿ����ͨѶ¼��*************
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

//********************ɾ����ϵ��********************
void delete_person(addressbooks* book)
{
	system("color 0E");
	if (book->size == 0)
	{
		cout << "��ǰû�п�ɾ�����б�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������Ҫɾ����ϵ�˵�����" << endl;
		string name;
		cin >> name;
		int result = isexist(book, name);
		if (result == -1)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			cout << "�ҵ����ڵ�" << result + 1 << "λ" << endl;
			for (int i = 0; i < book->size; i++)
			{
				book->personarray[result] = book->personarray[result + 1];
			}
			book->size--;
			cout << "ɾ���ɹ���" << endl;
		}

		system("pause");
		system("cls");
	}
}

//********************������ϵ��********************
void find_person(addressbooks* book)
{
	system("color 0D");
	if (book->size == 0)
	{
		cout << "��ǰû�пɲ��ҵ��б�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������Ҫ���ҵ���ϵ������" << endl;
		string name;
		cin >> name;
		int result = isexist(book, name);
		if (result == -1)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			cout << "����\t\t" << "����\t\t" << "�Ա�\t\t" << "�绰\t\t" << "��ַ\t\t" << endl;
			cout << "========================================================================" << endl;
			cout << book->personarray[result].name << "\t\t";
			cout << book->personarray[result].age << "\t\t";
			cout << (book->personarray[result].gender == 1 ? "��" : "Ů") << "\t\t";
			cout << book->personarray[result].phone << "\t\t";
			cout << book->personarray[result].address << "\t\t" << endl;
		}
		system("pause");
		system("cls");
	}
}

//********************�޸���ϵ��********************
void modify_person(addressbooks* book)
{
	system("color 0C");
	if (book->size == 0)
	{
		cout << "��ǰû�п��޸ĵ��б�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������Ҫ�޸ĵ���ϵ������" << endl;
		string name;
		cin >> name;
		int result = isexist(book, name);
		if (result == -1)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			while (true)
			{
				cout << "��ѡ����Ҫ�޸ĵ���" << endl;
				cout << "1.�޸�����" << endl;
				cout << "2.�޸�����" << endl;
				cout << "3.�޸��Ա�" << endl;
				cout << "4.�޸ĵ绰" << endl;
				cout << "5.�޸ĵ�ַ" << endl;
				cout << "0.������һ��" << endl;
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
					cout << "��Ҫ��--" << book->personarray[result].name << "--�޸�Ϊ��" << endl;
					cin >> name;
					book->personarray[result].name = name;
					cout << "�޸ĳɹ���" << endl;
					break;
				}
				case 2:
				{
					int age;
					cout << "��Ҫ��--" << book->personarray[result].age << "--�޸�Ϊ��" << endl;
					cin >> age;
					book->personarray[result].age = age;
					cout << "�޸ĳɹ���" << endl;
					break;
				}
				case 3:
				{
					int gender;
					cout << "��Ҫ��--" << book->personarray[result].gender << "--�޸�Ϊ��" << endl;
					cout << "1--��" << endl << "2--Ů" << endl;
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
							cout << "��������Ա���������������" << endl;
						}
					}
					cout << "�޸ĳɹ���" << endl;
					break;
				}
				case 4:
				{
					string phone;
					cout << "��Ҫ��--" << book->personarray[result].phone << "--�޸�Ϊ��" << endl;
					cin >> phone;
					book->personarray[result].phone = phone;
					cout << "�޸ĳɹ���" << endl;
					break;
				}
				case 5:
				{
					string address;
					cout << "��Ҫ��--" << book->personarray[result].address << "--�޸�Ϊ��" << endl;
					cin >> address;
					book->personarray[result].address = address;
					cout << "�޸ĳɹ���" << endl;
					break;
				}
				default:
					cout << "������Ĵ�����������������" << endl;
					cout << endl;
				}
			}
		}
		system("pause");
		system("cls");
	}
}

//********************�����ϵ��********************
void clean_person(addressbooks* book)
{
	system("color 0F");
	if (book->size == 0)
	{
		cout << "��ǰ�б�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		book->size = 0;
		cout << "ͨѶ¼�б������" << endl;
	}
	system("pause");
	system("cls");
}

//**********************������**********************
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
		case 1://�����ϵ��
			add_person(&book);
			break;
		case 2://��ʾ��ϵ��
			show_person(&book);
			break;
		case 3://ɾ����ϵ��
			delete_person(&book);
			break;
		case 4://������ϵ��
			find_person(&book);
			break;
		case 5://�޸���ϵ��
			modify_person(&book);
			break;
		case 6://�����ϵ��
			clean_person(&book);
			break;
		case 0://�˳�ͨѶ¼
			cout << "�����˳��У���ӭ�´�ʹ��" << endl;
			Sleep(1000);
			return 0;
			break;
		default:cout << "������Ĵ����������������룡" << endl;
		}
	}
	system("pause");
	return 0;
}