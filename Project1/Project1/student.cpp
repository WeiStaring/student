#pragma once
#include<string>
#include"Student.h"
using namespace std;

Gradute_a::Gradute_a() {
	for (int i = 0; i < 3; ++i) {
		papers[i].first = 0;
	}
}

istream& Gradute_a::operator>>(istream &input, Gradute_a &astu)
{
	cout << "学号: ";
	input >> astu.uid;
	if (astu.uid == "0")
	{
		return input;
	}
	cout << "姓名：";
	input >> astu.name;
loopse:
	cout << "性别：";
	input >> astu.sex;
	//判断性别是否合法
	if (!(astu.sex == "男" || astu.sex == "女"))
	{
		cerr << "性别输入有误，请重新输入！" << endl;
		goto loopse;
	}
	cout << "年龄： ";
	input >> astu.age;
loopc:
	cout << "课程成绩: ";
	input >> astu.score;

	if (astu.score < 0 || astu.score>100)
	{
		cerr << "课程成绩输入有误，请重新输入!" << endl;
		goto loopc;
	}

	cout << "专业: ";
	input >> astu.major;
looppn:
	cout << "发表论文篇数：" << endl;
	input >> astu.paperNumber;
	if (!(astu.paperNumber <= 3 && astu.paperNumber > 0))
	{
		cerr << "输入有误，论文篇数范围1 - 3" << endl;
		goto looppn;
	}
	if (astu.paperNumber >= 1)
	{
		cout << "论文一：";
		input >> astu.apaper.paper1;
	loopff:
		cout << "级别(1,2,3)：";
		input >> astu.apaper.paperLevel1;
		//判断级别是否合法
		if (!(astu.apaper.paperLevel1 == 1 || astu.apaper.paperLevel1 == 2 || astu.apaper.paperLevel1 == 3))
		{
			cerr << "输入的级别有误（级别为1 2 3），请重新输入！" << endl;
			goto loopff;
		}
	loopf:
		cout << "分数一：";
		input >> astu.apaper.paper1Score;
		//判断分数是否合法
		if (astu.apaper.paper1Score < 0 || astu.apaper.paper1Score > 90)
		{
			cerr << "输入的分数一有误，请重新输入！" << endl;
			goto loopf;
		}
	}

	if (astu.paperNumber >= 2)
	{
		cout << "论文二：";
		input >> astu.apaper.paper2;
	loopss:
		cout << "级别(1,2,3)：";
		input >> astu.apaper.paperLevel2;
		if (!(astu.apaper.paperLevel2 == 1 || astu.apaper.paperLevel2 == 2 || astu.apaper.paperLevel2 == 3))
		{
			cerr << "输入的级别有误（级别为1 2 3），请重新输入！" << endl;
			goto loopss;
		}
	loops:
		cout << "分数二：";
		input >> astu.apaper.paper2Score;
		if (astu.apaper.paper2Score < 0 || astu.apaper.paper2Score > 90)
		{
			cerr << "输入的分数二有误，请重新输入！" << endl;
			goto loops;
		}
	}
	if (astu.paperNumber >= 3)
	{
		cout << "论文三：";
		input >> astu.apaper.paper3;
	looptt:
		cout << "级别(1,2,3)：";
		input >> astu.apaper.paperLevel3;
		if (!(astu.apaper.paperLevel3 == 1 || astu.apaper.paperLevel3 == 2 || astu.apaper.paperLevel3 == 3))
		{
			cerr << "输入的级别有误（级别为1 2 3），请重新输入！" << endl;
			goto looptt;
		}
	loopt:
		cout << "分数三：";
		input >> astu.apaper.paper3Score;
		if (astu.apaper.paper3Score < 0 || astu.apaper.paper3Score > 90)
		{
			cerr << "输入的分数三有误，请重新输入！" << endl;
			goto loopt;
		}
	}
	cout << "论文成绩：";
	astu.paperScore = astu.calculatePaperScore();
	cout << astu.paperScore << endl;

	cout << "总成绩：";
	astu.sumScore = astu.calculateSumScore();
	cout << astu.sumScore << endl;
	return input;
}
