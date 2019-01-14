#pragma once
#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;

void firstInputData(Graduate_a* head) {
	int flag;
	cout << "正在录入数据，是否继续？yes:1,no:0" << endl;
	cin >> flag;
	if (!flag)
		return;
	cout << "请输入数据" << endl;

	Graduate_a *q;
	q = head;
	while (q->pnext)
		q = q->pnext;

	while (flag) {
		Graduate_a *p = new Graduate_a;
		cin >> *p;
		q->pnext = p;
		q = p;
		getchar();
		cout << "继续？yes：1，no：0" << endl;
		cin >> flag;
	}
}

void saveStudentData(Graduate_a* head) {
	//建立一个txt文本文件
	Graduate_a *p = head->pnext;
	ofstream outfile("AcademicStudentData.txt", ios::out);
	if (!outfile)
	{
		cerr << "文件打开失败!" << endl;
		cerr << "错误代码0x125158" << endl;
		cerr << "请联系管理员处理" << endl;
		system("pause");
		exit(0);
	}
	while (p != NULL)
	{
		outfile << *p;
		p = p->pnext;
	}
	outfile.close();
	//建立一个dat二进制文件，方便以后读取
	p = head->pnext;//重新赋值
	ofstream outfiled("AcademicStudentData.dat", ios::out | ios::binary);
	if (!outfiled)
	{
		cerr << "文件打开失败!" << endl;
		cerr << "错误代码0x125158" << endl;
		cerr << "请联系管理员处理" << endl;
		system("pause");
		exit(0);
	}
	while (p != NULL)
	{
		outfiled.write((char*)p, sizeof(*p));
		p = p->pnext;
	}
	outfiled.close();
	return;
}

//学术类研究生普通函数的定义
Graduate_a* seekAcademicData(Graduate_a *head)//查找某个学术研究生数据
{
	if (head->pnext == NULL)//判断缓存中是否有数据
	{
		cerr << "错误代码：0x123458！" << endl;
		cerr << "异常错误！（请上报管理员处理）" << endl;
		system("pause");
		exit(0);
	}
loop:
	cout << "学号（1）， 姓名（2）？" << endl;
	int i = 0;
	cin >> i;
	if (!(i == 1 || i == 2))
	{
		cerr << "输入有误，请重新输入！" << endl;
		goto loop;
	}
	Graduate_a *p = head->pnext;
	string targetNum;
	string targetName;
	switch (i)
	{
	case 1:
	loopnu:
		cout << "请输入学号：" << endl;
		cin >> targetNum;
		while (p->getNum() != targetNum)
		{
			p = p->pnext;
		}
		if (p == NULL)
		{
			cerr << "没有这个数据！请重新输入！" << endl;
			goto loopnu;
		}
		return p;
		break;
	case 2:
	loopna:
		cout << "请输入姓名：" << endl;
		cin >> targetName;
		while (p->getName() != targetName)
		{
			p = p->pnext;
		}
		if (p == NULL)
		{
			cerr << "没有这个数据！请重新输入！" << endl;
			goto loopna;
		}
		return p;
		break;

	default:
		cerr << "错误代码：0x123459！" << endl;
		cerr << "异常错误！（请上报管理员处理）" << endl;
		system("pause");
		exit(0);
	}
}
//录入学术研究生数据
Graduate_a* inputAcademicData(Graduate_a *head)
{
	Graduate_a *p, *q;
	p = q = new Graduate_a;
	if (p == NULL || q == NULL)//申请内存失败操作
	{
		cerr << "错误代码：0x123456！" << endl;
		cerr << "异常错误！（请上报管理员处理）" << endl;
		system("pause");
		exit(0);
	}
	cout << "开始录入数据（学号为零时结束）" << endl;
	cin >> *p;
	cout << "录入成功！" << endl;
	int i = 1;

	while (p->getNum() != "")
	{
		if (i == 1)
		{
			head->pnext = p;
		}
		else
		{
			q->pnext = p;
		}
		q = p;
		p = new Graduate_a;
		if (p == NULL)//申请内存失败操作
		{
			cerr << "错误代码：0x123457！" << endl;
			cerr << "异常错误！（请上报管理员处理）" << endl;
			system("pause");
			exit(0);
		}
		cin >> *p;
		p->getNum();
		if (p->getNum() != "")
		{
			cout << "录入成功！" << endl;
		}
		else
		{
			cout << "录入结束!" << endl;
		}
		i++;
	}
	q->pnext = NULL;
	return head;
}
//插入某个学术研究生数据
Graduate_a* insertAcademicData(Graduate_a *head)
{
	if (head->pnext == NULL)//判断缓存中是否有数据
	{
		cerr << "错误代码：0x123458！" << endl;
		cerr << "异常错误！（请上报管理员处理）" << endl;
		system("pause");
		exit(0);
	}
	Graduate_a *p, *q;

	cout << "请输入一个新的数据（学术研究生）" << endl;
	p = new Graduate_a;
	if (p == NULL)
	{
		cerr << "错误代码：0x123458！" << endl;
		cerr << "异常错误！（请上报管理员处理）" << endl;
		system("pause");
		exit(0);
	}
	cin >> *p;
	cout << "录入成功！" << endl;
	cout << "请输入插入在哪个数据之后？" << endl;
	//找到要插入的人
	q = seekAcademicData(Graduate_a::aHead);
	p->pnext = q->pnext;
	q->pnext = p;
	return head;
}
//删除某个学术研究生数据
Graduate_a* delAcademicData(Graduate_a *head)
{
	if (head->pnext == NULL)//判断缓存中是否有数据
	{
		cerr << "错误代码：0x123458！" << endl;
		cerr << "异常错误！（请上报管理员处理）" << endl;
		system("pause");
		exit(0);
	}
	Graduate_a *p, *q;
loop:
	cout << "学号（1）， 姓名（2）？" << endl;
	int i = 0;
	cin >> i;
	if (!(i == 1 || i == 2))
	{
		cerr << "输入有误，请重新输入！" << endl;
		goto loop;
	}
	p = head->pnext;
	q = head;
	string targetNum;
	string targetName;
	switch (i)
	{
	case 1:
	loopnu:
		cout << "请输入学号：" << endl;
		cin >> targetNum;
		while (p->getNum() != targetNum)
		{
			q = p;
			p = p->pnext;
		}
		if (p == NULL)
		{
			cerr << "没有这个数据！请重新输入！" << endl;
			goto loopnu;
		}
		break;
	case 2:
	loopna:
		cout << "请输入姓名：" << endl;
		cin >> targetName;
		while (p->getName() != targetName)
		{
			q = p;
			p = p->pnext;
		}
		if (p == NULL)
		{
			cerr << "没有这个数据！请重新输入！" << endl;
			goto loopna;
		}
		break;

	default:
		cerr << "错误代码：0x123459！" << endl;
		cerr << "异常错误！（请上报管理员处理）" << endl;
		system("pause");
		exit(0);
	}
	i = 0;
loopq:
	cout << "是否确定删除？是（1）， 否（2）" << endl;
	cin >> i;
	if (i == 1)
	{
		q->pnext = p->pnext;
	}
	else if (i == 2)
	{
		cerr << "取消成功！" << endl;
	}
	else
	{
		cout << "输入有误，请重新输入！" << endl;
		goto loopq;
	}
	return head;
}
//输出学术研究生数据
void printAcademicData(Graduate_a *head)
{
	Graduate_a *p = head->pnext;
	if (head->pnext == NULL)
	{
		cerr << "错误代码：0x156456（链表中无数据）" << endl;
		cerr << "请联系管理员处理！" << endl;
		system("pause");
		exit(0);
	}
	while (p != NULL)
	{
		cout << *p << endl;
		p = p->pnext;
	}
	return;
}
//修改学术研究生的数据
void modifyAcademicData()
{
	Graduate_a *p, *q;
	p = seekAcademicData(Graduate_a::aHead);
	q = new Graduate_a;
	q->pnext = p->pnext;
	if (q == NULL)
	{
		cerr << "错误代码0x156112" << endl;
		cerr << "请联系管理员解决！" << endl;
		system("pause");
		exit(0);
	}
	cin >> *q;
	int i = 0;
loop:
	cout << "是否确定修改 是（1）， 否（2）？" << endl;
	cin >> i;
	if (i == 1)
	{
		*p = *q;
		cout << "修改成功" << endl;
	}
	else if (i == 2)
	{
		cout << "取消成功！" << endl;
		delete q;
	}
	else
	{
		cerr << "输入有误， 请重新输入！" << endl;
		goto loop;
	}
	return;
}