#include<iostream>
#include<Windows.h>
using namespace std;

//void Loading()
//{
//	cout << "Loading"; 
//	for (int i = 0; i < 99; i++)
//	{
//		cout << " ";
//		cout << "Loading";
//		Sleep(100); 
//		cout << ".";
//		system("cls");
//	}
//	
//}

void Loading()
{

		int i, j, count = 5;

		for (i = 0; i < 20; count += 5, i++)
		{
			printf("\n\n\n\n\n\n\n\t\t\t\tLoading");
			for (j = 0; j < i % 3 + 1; j++)
				printf(".");
			printf("\n\t\t");
			for (j = 0; j <= i; j++)
				printf("��");
			for (j = 19 - i; j >= 0; j--)
				printf("  ");
			printf("%d%%", count);
			Sleep(100);
			system("CLS");
		}
	
}
void ShowMenu()
{
	cout << "\n\n\n\n\n\n\n" << endl;

	cout << "\t\t\t\t  ��ӭʹ��Ա������ϵͳ V1.0  " << endl;
	cout << "\t\t\t\t******  1.����Ա��      ******" << endl;
	cout << "\t\t\t\t******  2.�鿴����Ա��  ******" << endl;
	cout << "\t\t\t\t******  3.¼��Ա����Ϣ  ******" << endl;
	cout << "\t\t\t\t******  4.ɾ��Ա����Ϣ  ******" << endl;
	cout << "\t\t\t\t******  5.����Ա������  ******" << endl;
	cout << "\t\t\t\t******  6.Ա�����ʽ���  ******" << endl;
	cout << "\t\t\t\t******  0.�˳�ϵͳ      ******" << endl;
}

class Intern
{
	friend void test();
public:
	Intern(string Name,int Salary,int PeriodOfInternship,string Department)//:m_Name(Name),m_Salary(Salary),m_PeriodOfInternship(PeriodOfInternship),m_Department(Department)
	{
		m_Name = Name;
		m_Salary = Salary;
		m_PeriodOfInternship = PeriodOfInternship;
		m_Department = Department;
	}
	string get_Name()
	{
		return this->m_Name;
	}
	int get_Salary()
	{
		return this->m_Salary;
	}
	int get_PeriodOfInternship()
	{
		return this->m_PeriodOfInternship;
	}
	string get_Department()
	{
		return this->m_Department;
	}
private:
	string m_Name;
	int m_Salary;
	int m_PeriodOfInternship;
	string m_Department;
};

class Programmer
{
public:
	Programmer (string Name, int Salary, float AverageOT, string Department)
	{
		this->m_Name = Name;
		this->m_Salary = Salary;
		this->m_AverageOT = AverageOT;
		this->m_Department = Department;
	}
	string get_Name()
	{
		return this->m_Name;
	}
	int get_Salary()
	{
		return this->m_Salary;
	}
	float get_AverageOT()
	{
		return this->m_AverageOT;
	}
	string get_Department()
	{
		return this->m_Department;
	}
private:
	string m_Name;
	int m_Salary;
	float m_AverageOT;
	string m_Department;
};

class Manager
{
public:
	Manager(string Name, int Salary, string SecretaryName, string Department)
	{
		this->m_Name = Name;
		this->m_Salary = Salary;
		this->m_SecretaryName = SecretaryName;
		this->m_Department = Department;
	}
	string get_Name()
	{
		return this->m_Name;
	}
	int get_Salary()
	{
		return this->m_Salary;
	}
	string get_SecretaryName()
	{
		return this->m_SecretaryName;
	}
	string get_Department()
	{
		return this->m_Department;
	}
private:
	string m_Name;
	int m_Salary;
	string m_SecretaryName;
	string m_Department;

};

void ShowInfo(Intern intern,Programmer programmer,Manager manager)
{
	cout << "ʵϰ��" << endl;
	cout << "����\t\t" << "����\t\t" << "ʵϰ��\t\t" << "��������" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << intern.get_Name() << "\t\t" << intern.get_Salary() << "\t\t" << intern.get_PeriodOfInternship() << "\t\t" << intern.get_Department() << endl;
	cout << endl << endl << endl;
	cout << "����Ա" << endl;
	cout << "����\t\t" << "����\t\t" << "�Ӱ�ʱ��\t" << "��������" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << programmer.get_Name() << "\t\t" << programmer.get_Salary() << "\t\t"<< programmer.get_AverageOT() << "\t\t" << programmer.get_Department() << endl;
	cout << endl << endl << endl;
	cout << "����" << endl;
	cout << "����\t\t" << "����\t\t" << "��������\t" << "��������" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << manager.get_Name() << "\t\t" << manager.get_Salary() << "\t\t"<< manager.get_SecretaryName() << "\t\t" << manager.get_Department() << endl;
	system("pause");
	system("cls");
}

void Promotable(Programmer programmer, Manager manager)
{

}

//void test()
//{
//	Intern Intern_arr[100] = {
//		Intern("����", 20000, 3, "ʵϰ��") };
//}
int Function()
{
	Intern* Intern_arr[100];
	while (true)
	{
		Intern i1("����", 20000, 3, "ʵϰ��");
		Intern i2("����", 19000, 3, "ʵϰ��");
		Intern i3("����", 20500, 1, "ʵϰ��");

		Programmer p1("��СѾ", 40000, 4, "������");
		Programmer p2("·�˼�", 45000, 5, "������");
		Programmer p3("·����", 42000, 4.5, "������");

		Manager m1("����", 100000, "СA", "���ڲ�");
		Manager m2("����", 110000, "СC", "��Ʋ�");
		ShowMenu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1:return 0; break;
		case 2:ShowInfo(i1, p2, m1); break;
		case 0:
			{
				cout << "ϵͳ�˳���......" << endl;
				Sleep(1000);
				return 0;
				break;
			}
		}
	}
}

int main()
{

	cout << "����������" << endl;
	string password;
	cin >> password;
	if (password == "123456")
	{
		Loading();
		Function();
	}
	else { cout << "��������������!!!!!!!!!!!!!"; }
	system("pause");
	return 0;
}