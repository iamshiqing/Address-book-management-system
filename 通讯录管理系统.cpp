#include<iostream>
#include<string>
using namespace std;
#define max 1000
struct person {
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};
struct addressbooks{
	person personarray[max];
	int personsize;
};
void showmenu()
{
	cout << "*************************" << endl;
	cout << "***** 1��������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}
void addperson(addressbooks * abs) {
	if (abs->personsize == 1000)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "������������" << endl;
		cin >> abs->personarray[abs->personsize].name;
		while (1)
		{
			cout << "�������Ա�" << endl;
			cout << "1 --- ��" << endl;
			cout << "2 --- Ů" << endl;
			cin >> abs->personarray[abs->personsize].sex;
			if (abs->personarray[abs->personsize].sex == 1 || abs->personarray[abs->personsize].sex == 2)
				break;
			else
				cout << "�����������������룡" << endl;

		}
		while (1)
		{
			cout << "���������䣺 " << endl;
			cin >> abs->personarray[abs->personsize].age;
			if (abs->personarray[abs->personsize].age > 0 && abs->personarray[abs->personsize].age < 150)
				break;
			else
				cout << "�����������������룡" << endl;
		}
		while (1)
		{
			cout << "�������ֻ����룺" << endl;
			cin >> abs->personarray[abs->personsize].phone;
			if (abs->personarray[abs->personsize].phone.length()==11)
				break;
			else
				cout << "�����������������룡" << endl;
		}
		cout << "�������ͥ��ַ��" << endl;
		cin >> abs->personarray[abs->personsize].addr;
		abs->personsize++;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}

}
void showperson(addressbooks* abs)
{
	if (abs->personsize == 0)
	{
		cout << "��ǰͨѶ¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "����\t" << "�Ա�\t" << "����\t" << "�ֻ�����\t" << "��ͥ��ַ" << endl;
		for (int i = 0; i < abs->personsize; i++)
		{
			cout << abs->personarray[i].name << "\t";
			if (abs->personarray[i].sex == 1)
				cout << "��\t";
			else
				cout << "Ů\t";
			cout << abs->personarray[i].age << "\t";
			cout << abs->personarray[i].phone << "\t";
			cout << abs->personarray[i].addr << endl;
		}
		system("pause");
		system("cls");
	}
}
int isexist(addressbooks * abs,string name)
{
	for (int i = 0; i < abs->personsize; i++)
	{
		if (abs->personarray[i].name == name)
			return i;
	}
	return -1;
}

void deleteperson(addressbooks* abs)
{
	string name;
	cout << "������Ҫɾ������ϵ�ˣ�" << endl;
	cin >> name;
	if (isexist(abs, name) != -1)
	{
		for (int i = isexist(abs,name); i < abs->personsize - 1; i++)
		{
			abs->personarray[i]=abs->personarray[i + 1];
		}
		abs->personsize--;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	if (isexist(abs, name) != -1)
	{
		cout << "����\t" << "�Ա�\t" << "����\t" << "�ֻ�����\t" << "��ͥ��ַ" << endl;
		cout << abs->personarray[isexist(abs, name)].name << "\t";
		if (abs->personarray[isexist(abs, name)].sex == 1)
			cout << "��\t";
		else
			cout << "Ů\t";
		cout << abs->personarray[isexist(abs, name)].age << "\t";
		cout << abs->personarray[isexist(abs, name)].phone << "\t";
		cout << abs->personarray[isexist(abs, name)].addr << endl;
	}
	else
		cout << "���޴��ˣ�" << endl;
	system("pause");
	system("cls");
}
void modifyperson(addressbooks* abs)
{
	string name;
	cout << "������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	cin >> name;
	if (isexist(abs, name) != -1)
	{
		cout << "������������" << endl;
		cin >> abs->personarray[isexist(abs, name)].name;
		while (1)
		{
			cout << "��ѡ���Ա�" << endl;
			cout << "1 --- ��" << endl;
			cout << "2 --- Ů" << endl;
			cin >> abs->personarray[isexist(abs, name)].sex;
			if (abs->personarray[isexist(abs, name)].sex == 1 || abs->personarray[isexist(abs, name)].sex == 2)
				break;
			else
				cout << "�����������������룡" << endl;

		}
		while (1)
		{
			cout << "���������䣺 " << endl;
			cin >> abs->personarray[isexist(abs, name)].age;
			if (abs->personarray[isexist(abs, name)].age > 0 && abs->personarray[isexist(abs, name)].age < 150)
				break;
			else
				cout << "�����������������룡" << endl;
		}
		while (1)
		{
			cout << "�������ֻ����룺" << endl;
			cin >> abs->personarray[isexist(abs, name)].phone;
			if (abs->personarray[isexist(abs, name)].phone.length() == 11)
				break;
			else
				cout << "�����������������룡" << endl;
		}
		cout << "�������ͥ��ַ��" << endl;
		cin >> abs->personarray[isexist(abs, name)].addr;
		cout << "�޸ĳɹ���" << endl;
	}
	else
		cout << "���޴��ˣ�" << endl;
	system("pause");
	system("cls");
}
void cleanperson(addressbooks* abs)
{
	cout << "ȷ���Ƿ�����ͨѶ¼��y/n) ?" << endl;
	char select;
	while (1)
	{
		cin >> select;
		if (select == 'y')
		{
			abs->personsize = 0;
			cout << "ͨѶ¼����գ�"<<endl;
			break;
		}
		else if (select == 'n')
			break;
		else
			cout << "�����������������룺" << endl;
	}
	system("pause");
	system("cls");
}
int main() {
	addressbooks abs;
	abs.personsize=0;
	int select;
	while (1)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);
			break;
		case 2:
			showperson(&abs);
			break;
		case 3:
			deleteperson(&abs);
			break;
		case 4:
			findperson(&abs);
			break;
		case 5:
			modifyperson(&abs);
			break;
		case 6:
			cleanperson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			return 0;
			break;
		default:
			cout << "�������������ѡ��" << endl;
			break;
		}
	}
	return 0;
}