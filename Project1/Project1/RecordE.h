#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;

void firstInputData(Graduate_a* head) {
	int flag;
	cout << "����¼�����ݣ��Ƿ������yes:1,no:0" << endl;
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
		getchar();
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
//ѧ�����о�����ͨ�����Ķ���
//����ĳ��ѧ���о�������
Graduate_a* seekAcademicData(Graduate_a *head)
{
	if (head->pnext == NULL)//�жϻ������Ƿ�������
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա������" << endl;
		system("pause");
		exit(0);
	}
	int i = 0;
	for (;;) {
		cout << "ѧ�ţ�1���� ������2����" << endl;
		cin >> i;
		if (!(i == 1 || i == 2))
		{
			cerr << "�����������������룡" << endl;
		}
		else break;
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
		cerr << "�쳣���󣡣����ϱ�����Ա������" << endl;
		system("pause");
		exit(0);
	}
}
//¼��ѧ���о�������
Graduate_a* inputAcademicData(Graduate_a *head)
{
	Graduate_a *p, *q;
	p = q = new Graduate_a;
	if (p == NULL || q == NULL)//�����ڴ�ʧ�ܲ���
	{
		cerr << "������룺0x123456��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա������" << endl;
		system("pause");
		exit(0);
	}
	cout << "��ʼ¼�����ݣ�ѧ��Ϊ��ʱ������" << endl;
	cin >> *p;
	cout << "¼��ɹ���" << endl;
	int i = 1;
	try
	{
		while (p->getNum() != "0")
		{
			if (i == 1)
				head->pnext = p;
			else
				q->pnext = p;
			q = p;
			p = new Graduate_a;
			/*if (p == NULL)//�����ڴ�ʧ�ܲ���
			{
				cerr << "������룺0x123457��" << endl;
				cerr << "�쳣���󣡣����ϱ�����Ա������" << endl;
				system("pause");
				exit(0);
			}*/
			cin >> *p;
			if (p->getNum() != "")
				cout << "¼��ɹ���" << endl;
			else
				cout << "¼�����!" << endl;
			i++;
		}
	}
	catch (const std::exception& e)
	{
		cerr << "error" << endl;
	}
	q->pnext = NULL;
	return head;
}
//����ĳ��ѧ���о�������
Graduate_a* insertAcademicData(Graduate_a *head)
{
	if (head->pnext == NULL)//�жϻ������Ƿ�������
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա������" << endl;
		system("pause");
		exit(0);
	}
	Graduate_a *p, *q;

	cout << "������һ���µ����ݣ�ѧ���о�����" << endl;
	p = new Graduate_a;
	if (p == NULL)
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա������" << endl;
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
//ɾ��ĳ��ѧ���о�������
Graduate_a* delAcademicData(Graduate_a *head)
{
	if (head->pnext == NULL)//�жϻ������Ƿ�������
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա������" << endl;
		system("pause");
		exit(0);
	}
	Graduate_a *p, *q;
	int i = 0;
	for (;;) {
		cout << "ѧ�ţ�1���� ������2����" << endl;
		cin >> i;
		if (!(i == 1 || i == 2))
		{
			cerr << "�����������������룡" << endl;
		}
		break;
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
			while (p->getNum() != targetNum)
			{
				q = p;
				p = p->pnext;
			}
			if (p == NULL)
			{
				cerr << "û��������ݣ����������룡" << endl;
			}
			else break;
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
			{
				cerr << "û��������ݣ����������룡" << endl;
			}
			else break;
		}
		break;

	default:
		cerr << "������룺0x123459��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա������" << endl;
		system("pause");
		exit(0);
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
//���ѧ���о�������
void printAcademicData(Graduate_a *head)
{
	Graduate_a *p = head->pnext;
	if (head->pnext == NULL)
	{
		cerr << "������룺0x156456�������������ݣ�" << endl;
		cerr << "����ϵ����Ա������" << endl;
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
//�޸�ѧ���о���������
void modifyAcademicData()
{
	Graduate_a *p, *q;
	p = seekAcademicData(Graduate_a::aHead);
	q = new Graduate_a;
	q->pnext = p->pnext;
	if (q == NULL)
	{
		cerr << "�������0x156112" << endl;
		cerr << "����ϵ����Ա�����" << endl;
		system("pause");
		exit(0);
	}
	cin >> *q;
	int i = 0;
	for (;;) {
		cout << "�Ƿ�ȷ���޸� �ǣ�1���� ��2����" << endl;
		cin >> i;
		if (i == 1)
		{
			*p = *q;
			cout << "�޸ĳɹ�" << endl;
			break;
		}
		else if (i == 2)
		{
			cout << "ȡ���ɹ���" << endl;
			delete q;
			break;
		}
		else {
			cerr << "�������� ���������룡" << endl;
		}
	}
	return;
}