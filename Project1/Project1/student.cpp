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
	cout << "ѧ��: ";
	input >> astu.uid;
	if (astu.uid == "0")
	{
		return input;
	}
	cout << "������";
	input >> astu.name;
loopse:
	cout << "�Ա�";
	input >> astu.sex;
	//�ж��Ա��Ƿ�Ϸ�
	if (!(astu.sex == "��" || astu.sex == "Ů"))
	{
		cerr << "�Ա������������������룡" << endl;
		goto loopse;
	}
	cout << "���䣺 ";
	input >> astu.age;
loopc:
	cout << "�γ̳ɼ�: ";
	input >> astu.score;

	if (astu.score < 0 || astu.score>100)
	{
		cerr << "�γ̳ɼ�������������������!" << endl;
		goto loopc;
	}

	cout << "רҵ: ";
	input >> astu.major;
looppn:
	cout << "��������ƪ����" << endl;
	input >> astu.paperNumber;
	if (!(astu.paperNumber <= 3 && astu.paperNumber > 0))
	{
		cerr << "������������ƪ����Χ1 - 3" << endl;
		goto looppn;
	}
	if (astu.paperNumber >= 1)
	{
		cout << "����һ��";
		input >> astu.apaper.paper1;
	loopff:
		cout << "����(1,2,3)��";
		input >> astu.apaper.paperLevel1;
		//�жϼ����Ƿ�Ϸ�
		if (!(astu.apaper.paperLevel1 == 1 || astu.apaper.paperLevel1 == 2 || astu.apaper.paperLevel1 == 3))
		{
			cerr << "����ļ������󣨼���Ϊ1 2 3�������������룡" << endl;
			goto loopff;
		}
	loopf:
		cout << "����һ��";
		input >> astu.apaper.paper1Score;
		//�жϷ����Ƿ�Ϸ�
		if (astu.apaper.paper1Score < 0 || astu.apaper.paper1Score > 90)
		{
			cerr << "����ķ���һ�������������룡" << endl;
			goto loopf;
		}
	}

	if (astu.paperNumber >= 2)
	{
		cout << "���Ķ���";
		input >> astu.apaper.paper2;
	loopss:
		cout << "����(1,2,3)��";
		input >> astu.apaper.paperLevel2;
		if (!(astu.apaper.paperLevel2 == 1 || astu.apaper.paperLevel2 == 2 || astu.apaper.paperLevel2 == 3))
		{
			cerr << "����ļ������󣨼���Ϊ1 2 3�������������룡" << endl;
			goto loopss;
		}
	loops:
		cout << "��������";
		input >> astu.apaper.paper2Score;
		if (astu.apaper.paper2Score < 0 || astu.apaper.paper2Score > 90)
		{
			cerr << "����ķ������������������룡" << endl;
			goto loops;
		}
	}
	if (astu.paperNumber >= 3)
	{
		cout << "��������";
		input >> astu.apaper.paper3;
	looptt:
		cout << "����(1,2,3)��";
		input >> astu.apaper.paperLevel3;
		if (!(astu.apaper.paperLevel3 == 1 || astu.apaper.paperLevel3 == 2 || astu.apaper.paperLevel3 == 3))
		{
			cerr << "����ļ������󣨼���Ϊ1 2 3�������������룡" << endl;
			goto looptt;
		}
	loopt:
		cout << "��������";
		input >> astu.apaper.paper3Score;
		if (astu.apaper.paper3Score < 0 || astu.apaper.paper3Score > 90)
		{
			cerr << "����ķ������������������룡" << endl;
			goto loopt;
		}
	}
	cout << "���ĳɼ���";
	astu.paperScore = astu.calculatePaperScore();
	cout << astu.paperScore << endl;

	cout << "�ܳɼ���";
	astu.sumScore = astu.calculateSumScore();
	cout << astu.sumScore << endl;
	return input;
}
