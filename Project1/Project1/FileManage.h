#pragma once
#include<iostream>
#include<fstream>
#include"Student.h"
#include"RecordManage.h"
using namespace std;

void saveAcademicStudentData(Graduate_a *head)//保存学术研究生数据到磁盘
{
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
//读取磁盘数据到内存
Graduate_a* getAcademicStudentData(Graduate_a *head)//获取磁盘中学术研究生数据到缓存
{
loop:
	ifstream infile("AcademicStudentData.dat", ios::in | ios::binary);
	if (!infile)
	{
		cerr << "欢迎您第一次使用该系统，您首先要做的录入数据！" << endl;
		cerr << "警告：如果您不是第一次使用该系统，错误代码0x125158（请联系管理员处理）" << endl;
		firstInputData(Graduate_a::aHead);
		saveStudentData(Graduate_e::eHead);
		exit(0);
		goto loop;
	}
	infile.seekg(0, ios::beg);//重置指针的位置
	Graduate_a *p, *q;
	p = q = new Graduate_a;

	if (p == NULL || q == NULL)//申请内存失败操作
	{
		cerr << "错误代码：0x123456！" << endl;
		cerr << "异常错误！（请上报管理员处理）" << endl;
		system("pause");
		exit(0);
	}
	infile.read((char*)p, sizeof(*p));
	int i = 1;
	while (!infile.eof())
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
		infile.read((char*)p, sizeof(*p));
		i++;
	}
	q->pnext = NULL;
	infile.close();
	return head;
}
//追加函数
void addAcademicStudentData(Graduate_a *head)//追加学术研究生数据
{
	//建立一个txt.dat文件
	Graduate_a *p = head->pnext;
	Graduate_a *q = NULL;
	if (p == NULL)
	{
		cerr << "错误代码0x1566（链表 缓存中无数据）" << endl;
		cerr << "请联系管理员处理！" << endl;
		system("pause");
		exit(0);
	}
	ofstream outfile("AcademicStudentData.txt", ios::app);
	if (!outfile)
	{
		cerr << "文件打开失败!" << endl;
		cerr << "错误代码0x125158" << endl;
		cerr << "请联系管理员处理" << endl;
		system("pause");
		exit(0);
	}
	ofstream outfiled("AcademicStudentData.dat", ios::app);
	if (!outfiled)
	{
		cerr << "文件打开失败!" << endl;
		cerr << "错误代码0x125158" << endl;
		cerr << "请联系管理员处理" << endl;
		system("pause");
		exit(0);
	}
	//开始寻找链表末尾
	while (p != NULL)
	{
		q = p;
		p = p->pnext;
	}
	//寻找完毕
	cout << "开始添加!" << endl;
	q = inputAcademicData(q);
	while (q != NULL)
	{
		outfile << *q;
		outfiled.write((char*)q, sizeof(*q));
		q = q->pnext;
	}
	cout << "添加成功" << endl;
	outfile.close();
	outfiled.close();
	return;
}