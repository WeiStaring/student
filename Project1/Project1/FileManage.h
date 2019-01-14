#pragma once
#include<iostream>
#include<fstream>
#include"Student.h"
#include"RecordManage.h"
using namespace std;

void saveAcademicStudentData(Graduate_a *head)//����ѧ���о������ݵ�����
{
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
//��ȡ�������ݵ��ڴ�
Graduate_a* getAcademicStudentData(Graduate_a *head)//��ȡ������ѧ���о������ݵ�����
{
loop:
	ifstream infile("AcademicStudentData.dat", ios::in | ios::binary);
	if (!infile)
	{
		cerr << "��ӭ����һ��ʹ�ø�ϵͳ��������Ҫ����¼�����ݣ�" << endl;
		cerr << "���棺��������ǵ�һ��ʹ�ø�ϵͳ���������0x125158������ϵ����Ա����" << endl;
		firstInputData(Graduate_a::aHead);
		saveStudentData(Graduate_e::eHead);
		exit(0);
		goto loop;
	}
	infile.seekg(0, ios::beg);//����ָ���λ��
	Graduate_a *p, *q;
	p = q = new Graduate_a;

	if (p == NULL || q == NULL)//�����ڴ�ʧ�ܲ���
	{
		cerr << "������룺0x123456��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
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
		if (p == NULL)//�����ڴ�ʧ�ܲ���
		{
			cerr << "������룺0x123457��" << endl;
			cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
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
//׷�Ӻ���
void addAcademicStudentData(Graduate_a *head)//׷��ѧ���о�������
{
	//����һ��txt.dat�ļ�
	Graduate_a *p = head->pnext;
	Graduate_a *q = NULL;
	if (p == NULL)
	{
		cerr << "�������0x1566������ �����������ݣ�" << endl;
		cerr << "����ϵ����Ա����" << endl;
		system("pause");
		exit(0);
	}
	ofstream outfile("AcademicStudentData.txt", ios::app);
	if (!outfile)
	{
		cerr << "�ļ���ʧ��!" << endl;
		cerr << "�������0x125158" << endl;
		cerr << "����ϵ����Ա����" << endl;
		system("pause");
		exit(0);
	}
	ofstream outfiled("AcademicStudentData.dat", ios::app);
	if (!outfiled)
	{
		cerr << "�ļ���ʧ��!" << endl;
		cerr << "�������0x125158" << endl;
		cerr << "����ϵ����Ա����" << endl;
		system("pause");
		exit(0);
	}
	//��ʼѰ������ĩβ
	while (p != NULL)
	{
		q = p;
		p = p->pnext;
	}
	//Ѱ�����
	cout << "��ʼ���!" << endl;
	q = inputAcademicData(q);
	while (q != NULL)
	{
		outfile << *q;
		outfiled.write((char*)q, sizeof(*q));
		q = q->pnext;
	}
	cout << "��ӳɹ�" << endl;
	outfile.close();
	outfiled.close();
	return;
}