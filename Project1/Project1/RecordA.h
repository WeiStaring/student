#pragma once
#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;
typedef pair<Graduate_a *, Graduate_a*> apair;
typedef pair<Graduate_e *, Graduate_e*> epair;
apair getThing(Graduate_a*head, string clue) {
	Graduate_a * p = head->pnext, *q;
	if (p == 0)
		return { 0,0 };
	q = head;
	string target;
	string b;
	
	cout << "������"<<clue << endl;
	cin >> target;

	while (p)
	{
		if (clue == "ѧ��")
			b = p->getNum();
		else if (clue == "����")
			b = p->getName();
		if (b == target)
			break;
		q = p;
		p = p->pnext;
	}
	if (p == NULL)
		cerr << "û���������" << endl;
	return { p,q };
}
epair getThing(Graduate_e*head, string clue) {
	Graduate_e * p = head->pnext, *q;
	if (p == 0)
		return { 0,0 };
	q = head;
	string target;
	string b;

	cout << "������" << clue << endl;
	cin >> target;

	while (p)
	{
		if (clue == "ѧ��")
			b = p->getNum();
		else if (clue == "����")
			b = p->getName();
		if (b == target)
			break;
		q = p;
		p = p->pnext;
	}
	if (p == NULL)
		cerr << "û���������" << endl;
	return { p,q };
}
void deletehead(Graduate_a * head) {
	Graduate_a *tempptr;
	while (head->pnext != NULL)
	{
		tempptr = head->pnext;
		delete head;
		head = tempptr;
	}
	delete head;
}
void deletehead(Graduate_e * head) {
	Graduate_e *tempptr;
	while (head->pnext != NULL)
	{
		tempptr = head->pnext;
		delete head;
		head = tempptr;
	}
	delete head;
}

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
	ofstream outfile("EngineerStudentData.txt", ios::out);
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
	ofstream outfiled("EngineerStudentData.dat", ios::out | ios::binary);
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
apair seekAcademicData(Graduate_a *head)//����ĳ��ѧ���о�������
{
	if (head->pnext == NULL)//�жϻ������Ƿ�������
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
	apair pa;
loop:
	cout << "ѧ�ţ�1���� ������2����" << endl;
	int i = 0;
	cin >> i;
	if (!(i == 1 || i == 2))
	{
		cerr << "�����������������룡" << endl;
		goto loop;
	}
	switch (i)
	{
	case 1:
		pa = getThing(head, "ѧ��"); break;
	case 2:
		pa = getThing(head, "����"); break;
	}
	return pa;
}
/*Graduate_a* inputAcademicData(Graduate_a *head)//¼��ѧ���о�������
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
}*/
/*Graduate_a* insertAcademicData(Graduate_a *head)//����ĳ��ѧ���о�������
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
	q = seekAcademicData(Graduate_a::aHead).first;
	p->pnext = q->pnext;
	q->pnext = p;
	return head;
}*/
void delAcademicData(Graduate_a *head, Graduate_a* del_a_Head,bool flag=0)//ɾ��ĳ��ѧ���о�������
{
	apair pa;
	pa = seekAcademicData(head);
	Graduate_a *p, *q;
	p = pa.first;
	q = pa.second;
	if (p == NULL) {
		cerr << "û��������ݣ�" << endl;
		return ;
	}
	if (flag == 1) {
		q->pnext = p->pnext;
		delete p;
		return;
	}
	int i = 0;
	for (;;) {
		cout << *p << endl;
		cout << "�Ƿ�ȷ��ɾ�����ǣ�1���� ��2��" << endl;
		cin >> i;
		if (i == 1)
		{
			cout << "ѡ���߼�ɾ��1������ɾ��2" << endl;
			cin >> i;
			q->pnext = p->pnext;
			if (i == 1) {
				p->pnext = del_a_Head->pnext;
				del_a_Head->pnext = p;
			}
			else
				delete p;
			break;
		}
		else if (i == 2)
		{
			cerr << "ȡ���ɹ���" << endl;
			break;
		}
		else
			cout << "�����������������룡" << endl;
	}
}
void recycleData(Graduate_a *aHead, Graduate_a * del_aHead) {
	try
	{
		apair pa = seekAcademicData(del_aHead);
		Graduate_a *p, *q;
		p = pa.first;
		q = pa.second;
		q->pnext = p->pnext;
		p->pnext = aHead->pnext;
		aHead->pnext = p;
		cout << "�ָ��ɹ�" << endl;
		system("cls");
	}
	catch (const std::exception&e)
	{
		cout << "error" << endl;
	}
}
//�������о�����ͨ�����Ķ���
epair seekEngineerData(Graduate_e *head)//����ĳ��ѧ���о�������
{
	if (head->pnext == NULL)//�жϻ������Ƿ�������
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
	epair pe;
loop:
	cout << "ѧ�ţ�1���� ������2����" << endl;
	int i = 0;
	cin >> i;
	if (!(i == 1 || i == 2))
	{
		cerr << "�����������������룡" << endl;
		goto loop;
	}
	switch (i)
	{
	case 1:
		pe = getThing(head, "ѧ��"); break;
	case 2:
		pe = getThing(head, "����"); break;
	}
	return pe;
}
void delAcademicData(Graduate_e *head, Graduate_e* del_e_Head, bool flag = 0)//ɾ��ĳ��ѧ���о�������
{
	epair pe;
	pe = seekEngineerData(head);
	Graduate_e *p, *q;
	p = pe.first;
	q = pe.second;
	if (p == NULL) {
		cerr << "û��������ݣ�" << endl;
		return;
	}
	if (flag == 1) {
		q->pnext = p->pnext;
		delete p;
		return;
	}
	int i = 0;
	for (;;) {
		cout << *p << endl;
		cout << "�Ƿ�ȷ��ɾ�����ǣ�1���� ��2��" << endl;
		cin >> i;
		if (i == 1)
		{
			cout << "ѡ���߼�ɾ��1������ɾ��2" << endl;
			cin >> i;
			q->pnext = p->pnext;
			if (i == 1) {
				p->pnext = del_e_Head->pnext;
				del_e_Head->pnext = p;
			}
			else
				delete p;
			break;
		}
		else if (i == 2)
		{
			cerr << "ȡ���ɹ���" << endl;
			break;
		}
		else
			cout << "�����������������룡" << endl;
	}
}
void recycleData(Graduate_e *eHead, Graduate_e * del_eHead) {
	try
	{
		epair pe = seekEngineerData(del_eHead);
		Graduate_e *p, *q;
		p = pe.first;
		q = pe.second;
		q->pnext = p->pnext;
		p->pnext = eHead->pnext;
		eHead->pnext = p;
		cout << "�ָ��ɹ�" << endl;
		system("cls");
	}
	catch (const std::exception&e)
	{
		cout << "error" << endl;
	}
}