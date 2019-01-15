#pragma once
#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;

void firstInputData(Graduate_a* head) {
	int flag;
	cout << "�����������ݣ��Ƿ������yes:1,no:0" << endl;
	cin >> flag;
	if (!flag)
		return;
	cout << "����������" << endl;

	Graduate_a *q;
	q = head;
	while (q->pnext)
		q = q->pnext;

	while (flag) {

		Graduate_a *p = new Graduate_a;
		cin >> *p;
		q->pnext = p;
		q = p;
		cout << "������yes��1��no��0" << endl;
		cin >> flag;
	}
}

void firstInputData(Graduate_e* head) {
	int flag;
	cout << "�����������ݣ��Ƿ������yes:1,no:0" << endl;
	cin >> flag;
	if (!flag)
		return;
	cout << "����������" << endl;

	Graduate_e *q;
	q = head;
	while (q->pnext)
		q = q->pnext;

	while (flag) {

		Graduate_e *p = new Graduate_e;
		cin >> *p;
		q->pnext = p;
		q = p;
		cout << "������yes��1��no��0" << endl;
		cin >> flag;
	}
}

void saveStudentData(Graduate_a* head) {
	//����һ��txt�ı��ļ�
	Graduate_a *p = head->pnext;
	ofstream outfile("AcademicStudentData.txt", ios::out);
	if (!outfile)
	{
		cerr << "�ļ���ʧ��!" << endl;
		cerr << "�������0x125158" << endl;
		cerr << "����ϵ����Ա����" << endl;
		system("pause");
		exit(0);
	}
	while (p != NULL)
	{
		outfile << *p;
		p = p->pnext;
	}
	outfile.close();
	//����һ��dat�������ļ��������Ժ��ȡ
	p = head->pnext;//���¸�ֵ
	ofstream outfiled("AcademicStudentData.dat", ios::out | ios::binary);
	if (!outfiled)
	{
		cerr << "�ļ���ʧ��!" << endl;
		cerr << "�������0x125158" << endl;
		cerr << "����ϵ����Ա����" << endl;
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

void saveStudentData(Graduate_e* head) {
	//����һ��txt�ı��ļ�
	Graduate_e *p = head->pnext;
	ofstream outfile("AcademicStudentData.txt", ios::out);
	if (!outfile)
	{
		cerr << "�ļ���ʧ��!" << endl;
		cerr << "�������0x125158" << endl;
		cerr << "����ϵ����Ա����" << endl;
		system("pause");
		exit(0);
	}
	while (p != NULL)
	{
		outfile << *p;
		p = p->pnext;
	}
	outfile.close();
	//����һ��dat�������ļ��������Ժ��ȡ
	p = head->pnext;//���¸�ֵ
	ofstream outfiled("AcademicStudentData.dat", ios::out | ios::binary);
	if (!outfiled)
	{
		cerr << "�ļ���ʧ��!" << endl;
		cerr << "�������0x125158" << endl;
		cerr << "����ϵ����Ա����" << endl;
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


//ѧ�����о�����ͨ�����Ķ���
Graduate_a* seekAcademicData(Graduate_a *head)//����ĳ��ѧ���о�������
{
	if (head->pnext == NULL)//�жϻ������Ƿ�������
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
loop:
	cout << "ѧ�ţ�1���� ������2����" << endl;
	int i = 0;
	cin >> i;
	if (!(i == 1 || i == 2))
	{
		cerr << "�����������������룡" << endl;
		goto loop;
	}
	Graduate_a *p = head->pnext;
	string targetNum;
	string targetName;
	switch (i)
	{
	case 1:
	loopnu:
		cout << "������ѧ�ţ�" << endl;
		cin >> targetNum;
		while (p->getNum() != targetNum)
		{
			p = p->pnext;
		}
		if (p == NULL)
		{
			cerr << "û��������ݣ����������룡" << endl;
			goto loopnu;
		}
		return p;
		break;
	case 2:
	loopna:
		cout << "������������" << endl;
		cin >> targetName;
		while (p->getName() != targetName)
		{
			p = p->pnext;
		}
		if (p == NULL)
		{
			cerr << "û��������ݣ����������룡" << endl;
			goto loopna;
		}
		return p;
		break;

	default:
		cerr << "������룺0x123459��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
}
Graduate_a* inputAcademicData(Graduate_a *head)//¼��ѧ���о�������
{
	Graduate_a *p, *q;
	p = q = new Graduate_a;
	if (p == NULL || q == NULL)//�����ڴ�ʧ�ܲ���
	{
		cerr << "������룺0x123456��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
	cout << "��ʼ¼�����ݣ�ѧ��Ϊ��ʱ������" << endl;
	cin >> *p;
	cout << "¼��ɹ���" << endl;
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
		if (p == NULL)//�����ڴ�ʧ�ܲ���
		{
			cerr << "������룺0x123457��" << endl;
			cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
			system("pause");
			exit(0);
		}
		cin >> *p;
		if (p->getNum() != "")
		{
			cout << "¼��ɹ���" << endl;
		}
		else
		{
			cout << "¼�����!" << endl;
		}
		i++;
	}
	q->pnext = NULL;
	return head;
}
Graduate_a* insertAcademicData(Graduate_a *head)//����ĳ��ѧ���о�������
{
	if (head->pnext == NULL)//�жϻ������Ƿ�������
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
	Graduate_a *p, *q;

	cout << "������һ���µ����ݣ�ѧ���о�����" << endl;
	p = new Graduate_a;
	if (p == NULL)
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
	cin >> *p;
	cout << "¼��ɹ���" << endl;
	cout << "������������ĸ�����֮��" << endl;
	//�ҵ�Ҫ�������
	q = seekAcademicData(Graduate_a::aHead);
	p->pnext = q->pnext;
	q->pnext = p;
	return head;
}
Graduate_a* delAcademicData(Graduate_a *head)//ɾ��ĳ��ѧ���о�������
{
	if (head->pnext == NULL)//�жϻ������Ƿ�������
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
	Graduate_a *p, *q;
	cout << "ѧ�ţ�1���� ������2����" << endl;
	int i = 0;
	while (1) {
		cin >> i;
		if (i == 1 || i == 2) 
			break;
		cout << "����ȷ����" << endl;
	}
	
	p = head->pnext;
	q = head;
	string targetNum;
	string targetName;
	switch (i)
	{
	case 1:
		for (;;) {
			cout << "������ѧ�ţ�" << endl;
			cin >> targetNum;
			if (targetNum == "0")
				return NULL;
			while (p->getNum() != targetNum)
			{
				q = p;
				p = p->pnext;
			}
			if (p == NULL)
				cerr << "û��������ݣ����������룡��������0�˳�" << endl;
			else 
				break;
		}
		break;
	case 2:
		for (;;) {
			cout << "������������" << endl;
			cin >> targetName;
			while (p->getName() != targetName)
			{
				q = p;
				p = p->pnext;
			}
			if (p == NULL)
				cerr << "û��������ݣ����������룡" << endl;
			else 
				break;
		}
		break;

	}
	i = 0;
	for (;;) {
		cout << "�Ƿ�ȷ��ɾ�����ǣ�1���� ��2��" << endl;
		cin >> i;
		if (i == 1)
		{
			q->pnext = p->pnext;
			break;
		}
		else if (i == 2)
		{
			cerr << "ȡ���ɹ���" << endl;
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}
	return head;
}
pair<Graduate_a *, Graduate_a*> getThing(Graduate_a*head,string clue,string target, string (*fun)()) {
	Graduate_a * p=head, *q;
	for (;;) {
		cout << clue << endl;
		cin >> target;
		while (fun() != target)
		{
			q = p;
			p = p->pnext;
		}
		if (p == NULL)
			cerr << "û��������ݣ����������룡" << endl;
		else
			break;
	}
	return { p,q };
}
