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
	cout << "***** 1、增加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}
void addperson(addressbooks * abs) {
	if (abs->personsize == 1000)
	{
		cout << "通讯录已满，无法添加！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "请输入姓名：" << endl;
		cin >> abs->personarray[abs->personsize].name;
		while (1)
		{
			cout << "请输入性别：" << endl;
			cout << "1 --- 男" << endl;
			cout << "2 --- 女" << endl;
			cin >> abs->personarray[abs->personsize].sex;
			if (abs->personarray[abs->personsize].sex == 1 || abs->personarray[abs->personsize].sex == 2)
				break;
			else
				cout << "输入有误，请重新输入！" << endl;

		}
		while (1)
		{
			cout << "请输入年龄： " << endl;
			cin >> abs->personarray[abs->personsize].age;
			if (abs->personarray[abs->personsize].age > 0 && abs->personarray[abs->personsize].age < 150)
				break;
			else
				cout << "输入有误，请重新输入！" << endl;
		}
		while (1)
		{
			cout << "请输入手机号码：" << endl;
			cin >> abs->personarray[abs->personsize].phone;
			if (abs->personarray[abs->personsize].phone.length()==11)
				break;
			else
				cout << "输入有误，请重新输入！" << endl;
		}
		cout << "请输入家庭地址：" << endl;
		cin >> abs->personarray[abs->personsize].addr;
		abs->personsize++;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}

}
void showperson(addressbooks* abs)
{
	if (abs->personsize == 0)
	{
		cout << "当前通讯录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "姓名\t" << "性别\t" << "年龄\t" << "手机号码\t" << "家庭地址" << endl;
		for (int i = 0; i < abs->personsize; i++)
		{
			cout << abs->personarray[i].name << "\t";
			if (abs->personarray[i].sex == 1)
				cout << "男\t";
			else
				cout << "女\t";
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
	cout << "请输入要删除的联系人：" << endl;
	cin >> name;
	if (isexist(abs, name) != -1)
	{
		for (int i = isexist(abs,name); i < abs->personsize - 1; i++)
		{
			abs->personarray[i]=abs->personarray[i + 1];
		}
		abs->personsize--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks* abs)
{
	cout << "请输入要查找的联系人：" << endl;
	string name;
	cin >> name;
	if (isexist(abs, name) != -1)
	{
		cout << "姓名\t" << "性别\t" << "年龄\t" << "手机号码\t" << "家庭地址" << endl;
		cout << abs->personarray[isexist(abs, name)].name << "\t";
		if (abs->personarray[isexist(abs, name)].sex == 1)
			cout << "男\t";
		else
			cout << "女\t";
		cout << abs->personarray[isexist(abs, name)].age << "\t";
		cout << abs->personarray[isexist(abs, name)].phone << "\t";
		cout << abs->personarray[isexist(abs, name)].addr << endl;
	}
	else
		cout << "查无此人！" << endl;
	system("pause");
	system("cls");
}
void modifyperson(addressbooks* abs)
{
	string name;
	cout << "请输入要修改的联系人：" << endl;
	cin >> name;
	if (isexist(abs, name) != -1)
	{
		cout << "请输入姓名：" << endl;
		cin >> abs->personarray[isexist(abs, name)].name;
		while (1)
		{
			cout << "请选择性别：" << endl;
			cout << "1 --- 男" << endl;
			cout << "2 --- 女" << endl;
			cin >> abs->personarray[isexist(abs, name)].sex;
			if (abs->personarray[isexist(abs, name)].sex == 1 || abs->personarray[isexist(abs, name)].sex == 2)
				break;
			else
				cout << "输入有误，请重新输入！" << endl;

		}
		while (1)
		{
			cout << "请输入年龄： " << endl;
			cin >> abs->personarray[isexist(abs, name)].age;
			if (abs->personarray[isexist(abs, name)].age > 0 && abs->personarray[isexist(abs, name)].age < 150)
				break;
			else
				cout << "输入有误，请重新输入！" << endl;
		}
		while (1)
		{
			cout << "请输入手机号码：" << endl;
			cin >> abs->personarray[isexist(abs, name)].phone;
			if (abs->personarray[isexist(abs, name)].phone.length() == 11)
				break;
			else
				cout << "输入有误，请重新输入！" << endl;
		}
		cout << "请输入家庭地址：" << endl;
		cin >> abs->personarray[isexist(abs, name)].addr;
		cout << "修改成功！" << endl;
	}
	else
		cout << "查无此人！" << endl;
	system("pause");
	system("cls");
}
void cleanperson(addressbooks* abs)
{
	cout << "确认是否清理通讯录（y/n) ?" << endl;
	char select;
	while (1)
	{
		cin >> select;
		if (select == 'y')
		{
			abs->personsize = 0;
			cout << "通讯录已清空！"<<endl;
			break;
		}
		else if (select == 'n')
			break;
		else
			cout << "输入有误，请重新输入：" << endl;
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
			cout << "欢迎下次使用！" << endl;
			return 0;
			break;
		default:
			cout << "输入错误，请重新选择！" << endl;
			break;
		}
	}
	return 0;
}